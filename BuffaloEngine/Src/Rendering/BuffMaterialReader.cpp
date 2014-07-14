// Filename: BuffMaterialReader.cpp
// Author: Gael Huber
#include "Rendering\BuffMaterialReader.h"

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
		for (int i = 0; i < line.size(); ++i)
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
		//InputLayout inputLayout;

		// Ensure the block is being declared
		if (IsBlockStart(tokens))
		{
			ReadLine(tokens);
			while (IsBlockEnd(tokens) == false)
			{
				// Read the input layout parameter and add it to the description
				//InputLayoutParameter param;
				//ReadInputLayoutParameter(param);
				//inputLayout.AddParameter(param);
			}
		}

	}

	/**
	* Read a constant buffer block for a "per frame" buffer
	*/
	void Material::MaterialReader::ReadCBFrameBlock()
	{

	}

	/**
	* Read a constant buffer block for a "per material" buffer
	*/
	void Material::MaterialReader::ReadCBMaterialBlock()
	{

	}

	/**
	* Read a constant buffer block for a "per object" buffer
	*/
	void Material::MaterialReader::ReadCBObjectBlock()
	{

	}

	/**
	* Read a technique description. Techniques describe a series of passes that pair
	* rendering pipeline stages to various shaders
	*/
	void Material::MaterialReader::ReadTechniqueBlock()
	{

	}

}	// Namespace