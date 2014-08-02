// Filename: BuffMaterialReader.cpp
// Author: Gael Huber
#include "Rendering\BuffMaterialReader.h"

#include "Rendering\BuffRenderManager.h"

#include <algorithm>

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Material::MaterialReader::MaterialReader()
	{

	}

	/**
	* Destructor
	*/
	Material::MaterialReader::~MaterialReader()
	{

	}

	/**
	* Read and initialize data for this material
	* @param
	*	Material* The material to populate
	* @return
	*	bool Returns true if successful
	*/
	bool Material::MaterialReader::Read(Material* material)
	{
		// Cache the material
		_material = material;

		// Compute the material file name from the material name
		std::string filepath = "Resources/Shaders/" + material->_name + ".mat";

		// Open the file
		_stream.open(filepath.c_str(), std::ios::in);
		if (_stream.fail())
		{
			return false;
		}

		// Read the material line by line
		std::vector<std::string> tokens;
		while (ReadLine(tokens))
		{
			if (tokens.size() > 0)
			{
				// Layout
				if (tokens[0] == "layout")
				{
					ReadLayoutBlock();
				}
				else if (tokens[0] == "cbFrame")
				{
					ReadCBFrameBlock();
				}
				else if (tokens[0] == "cbMaterial")
				{
					ReadCBMaterialBlock();
				}
				else if (tokens[0] == "cbObject")
				{
					ReadCBObjectBlock();
				}
				else if (tokens[0] == "technique")
				{
					ReadTechniqueBlock();
				}
			}
		}

		// Close the file
		_stream.close();

		return true;
	}

	/**
	* Read and tokenize a line from the material
	* @param
	*	std::vector<std::string>& The tokens of the line
	* @return
	*	bool True if successful
	*/
	bool Material::MaterialReader::ReadLine(std::vector<std::string>& tokens)
	{
		std::string line;
		if (std::getline(_stream, line))
		{
			tokens = Tokenize(line);
			return true;
		}

		return false;
	}

	/**
	* Check if this line is a block start indicator
	* @param
	*	const std::vector<std::string>& The tokens of the line
	* @return
	*	bool True if block start
	*/
	bool Material::MaterialReader::IsBlockStart(std::vector<std::string>& tokens)
	{
		if (tokens.size() > 0)
		{
			return tokens[0] == "{";
		}

		return false;
	}

	/**
	* Check if this line is a block end indicator
	* @param
	*	const std::vector<std::string>& The tokens of the line
	* @return
	*	bool True if block end
	*/
	bool Material::MaterialReader::IsBlockEnd(std::vector<std::string>& tokens)
	{
		if (tokens.size() > 0)
		{
			return tokens[0] == "}";
		}

		return false;
	}

	/**
	* Tokenize a line into individual strings
	* @param
	*	const std::string& The string to tokenize
	* @return
	*	std::vector<std::string> The vector of tokens
	*/
	std::vector<std::string> Material::MaterialReader::Tokenize(const std::string& line)
	{
		std::vector<std::string> tokens;

		// Creation string
		std::string str;
		for (uint i = 0; i < line.size(); ++i)
		{
			if (line[i] == ' ')
			{
				tokens.push_back(str);
				str.clear();
			}
			else
			{
				str += line[i];
			}
		}
		tokens.push_back(str);

		// Clear white-space from each string
		for (std::vector<std::string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
		{
			for (int i = itr->size() - 1; i >= 0; --i)
			{
				if (isspace((*itr)[i]))
				{
					itr->erase(i, 1);
				}
			}
		}

		return tokens;
	}

	/**
	* Read a layout block. Layouts describe the input layout and semantic types of vertices being
	* passed into the material
	*/
	void Material::MaterialReader::ReadLayoutBlock()
	{
		// Read a line
		std::vector<std::string> tokens;
		ReadLine(tokens);

		// Input layout description
		InputLayout inputLayout;

		// Ensure the block is being declared
		if (IsBlockStart(tokens))
		{
			ReadLine(tokens);
			while (IsBlockEnd(tokens) == false)
			{
				// Read the input layout parameter and add it to the description
				InputLayoutParameter param;
				ReadInputLayoutParameter(param, tokens);
				inputLayout.AddParameter(param);

				ReadLine(tokens);
			}

			// Set the input layout for the material
			_material->_inputLayout = inputLayout;
		}
	}

	/**
	* Read an input layout parameter
	* @param
	*	InputLayoutParameter& The input layout parameter to populate
	* @param
	*	const std::vector<std::string>& The tokens for this line
	* @return
	*	bool Returns true if successful
	*/
	bool Material::MaterialReader::ReadInputLayoutParameter(InputLayoutParameter& param, const std::vector<std::string>& tokens)
	{
		ShaderParameter shaderParam = ShaderParameter(ShaderParameter::GetParameterType(tokens[0]), tokens[1]);
		param = InputLayoutParameter(shaderParam, VertexDescription::GetSemanticType(tokens[3]));

		return true;
	}

	/**
	* Read a constant buffer block for a "per frame" buffer
	*/
	void Material::MaterialReader::ReadCBFrameBlock()
	{
		ReadConstantBuffer(CONSTANT_BUFFER_TYPE_FRAME);
	}

	/**
	* Read a constant buffer block for a "per material" buffer
	*/
	void Material::MaterialReader::ReadCBMaterialBlock()
	{
		ReadConstantBuffer(CONSTANT_BUFFER_TYPE_MATERIAL);
	}

	/**
	* Read a constant buffer block for a "per object" buffer
	*/
	void Material::MaterialReader::ReadCBObjectBlock()
	{
		ReadConstantBuffer(CONSTANT_BUFFER_TYPE_OBJECT);
	}

	/**
	* Read in configuration for a constant buffer block
	* @param
	*	ConstantBufferType The type of buffer to create
	*/
	void Material::MaterialReader::ReadConstantBuffer(ConstantBufferType bufferType)
	{
		// Read a line
		std::vector<std::string> tokens;
		ReadLine(tokens);

		// Ensure the block is being declared
		if (IsBlockStart(tokens))
		{
			// Initialize the constant buffer
			ConstantBuffer* buffer = RenderManager::GetSingletonPtr()->CreateConstantBuffer();

			// Set the constant buffer type
			buffer->SetBufferType(bufferType);

			// Read the buffer
			ReadLine(tokens);
			while (IsBlockEnd(tokens) == false)
			{
				ShaderParameterType type = ShaderParameter::GetParameterType(tokens[0]);
				if (type != SHADER_PARAMETER_TYPE_UNKNOWN)
				{
					ShaderParameter parameter = ShaderParameter(type, tokens[1]);
					buffer->AddParameter(parameter);
				}
				ReadLine(tokens);
			}

			// Set the constant buffer
			_material->AddConstantBuffer(buffer);
		}		
	}

	/**
	* Read a technique description. Techniques describe a series of passes that pair
	* rendering pipeline stages to various shaders
	*/
	void Material::MaterialReader::ReadTechniqueBlock()
	{
		// Read a line
		std::vector<std::string> tokens;
		ReadLine(tokens);
		
		if (IsBlockStart(tokens))
		{
			// The technique being created
			Technique technique;

			ReadLine(tokens);
			while (IsBlockEnd(tokens) == false)
			{
				// If the block is a pass block
				if (tokens.size() > 0)
				{
					if (tokens[0] == "pass")
					{
						ReadPassBlock(technique);
					}
				}

				ReadLine(tokens);
			}

			// Add the technique to the material
			_material->_technique = technique;
		}
	}

	/**
	* Read a pass block description. Passes contain information about the particular
	* rendering pass.
	* @param
	*	Technique& The technique to which the pass will be attached
	*/
	void Material::MaterialReader::ReadPassBlock(Technique& technique)
	{
		// Read a line
		std::vector<std::string> tokens;
		ReadLine(tokens);

		if (IsBlockStart(tokens))
		{
			// The pass being assembled
			Pass pass;

			ReadLine(tokens);
			while (IsBlockEnd(tokens) == false)
			{
				// If the block is a pass block
				if (tokens.size() > 0)
				{
					// Process a vertex shader
					if (tokens[0] == "VertexShader")
					{
						// Create a vertex shader with the entry point and filename specified
						VertexShader* shader = RenderManager::GetSingletonPtr()->CreateVertexShader(tokens[1], tokens[2]);
						pass.SetVertexShader(shader);
					}
					else if (tokens[0] == "PixelShader")
					{
						// Create a pixel shader with the entry point and filename specified
						PixelShader* shader = RenderManager::GetSingletonPtr()->CreatePixelShader(tokens[1], tokens[2]);
						pass.SetPixelShader(shader);
					}
				}

				ReadLine(tokens);
			}

			// Add the pass to the technique
			technique.AddPass(pass);
		}
	}

}	// Namespace