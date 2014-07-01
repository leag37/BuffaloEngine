// Filename: BuffObjExporter.cpp
// Author: Gael Huber
#include "BuffObjExporter.h"
#include "stdafx.h"

namespace BuffaloEngine
{	
	/**
	* Default constructor
	*/
	ObjExporter::ObjExporter()
	{
	}

	/**
	* Destructor
	*/
	ObjExporter::~ObjExporter()
	{
	}

	/**
	* Export the file
	* @param
	*	const string& The input file
	* @param
	*	const string& The output file
	* @return
	*	bool Returns true if the export was successful
	*/
	bool ObjExporter::Export(const std::string& input, const std::string& output)
	{
		std::fstream iFile;
		iFile.open(input.c_str());

		// Make sure the file is open
		if(iFile.fail() == true)
		{
			return false;
		}

		// Vertex numerical data
		int posCount, normCount, texCount, faceCount, indexCount;
		posCount = normCount = texCount = faceCount = indexCount = 0;

		// Read the file to count vertex data
		char data;
		iFile.get(data);
		while(iFile.eof() == false)
		{
			// Vertex data
			if(data == 'v')
			{
				iFile.get(data);
				if(data == ' ') { ++posCount; }
				else if(data == 't') { ++texCount; }
				else if(data == 'n') { ++normCount; }
			}

			if(data == 'f')
			{
				iFile.get(data);
				if(data == ' ') { ++faceCount; }
			}

			while(data != '\n')
			{
				iFile.get(data);
			}

			// Get next line
			iFile.get(data);
		}

		// Seek to the beginning of the file
		iFile.close();
		iFile.open(input.c_str());

		// Vertex positions
		std::vector<float> vertexPos = std::vector<float>(posCount * 3, 0.0f);
		std::vector<float> vertexNorm = std::vector<float>(normCount * 3, 0.0f);
		std::vector<float> texCoords = std::vector<float>(texCount * 2, 0.0f);
		std::vector<int> indices = std::vector<int>(faceCount * 3, 0);

		int posSize = vertexPos.size();
		int normSize = vertexNorm.size();
		int texSize = texCoords.size();
		int indSize = indices.size();

		// Vertex data
		int vertexElements = 0;
		int vertexSize = 0;

		// Count number of elements
		if(posCount > 0)
		{
			++vertexElements;
			vertexSize += 3;
		}
		if(normCount > 0)
		{
			++vertexElements;
			vertexSize += 3;
		}
		if(texCount > 0)
		{
			++vertexElements;
			vertexSize += 2;
		}

		std::vector<float> vertices = std::vector<float>(posCount * vertexSize, FLT_MAX);

		// Create the file header
		MeshFileHeader fileHeader = 
		{
			'b', 'e',
			posCount,
			vertexElements,
			faceCount * 3
		};

		// Reset counts
		posCount = normCount = texCount = faceCount = 0;

		// Read vertex data
		iFile.get(data);
		while(iFile.eof() == false)
		{
			// Vertex data
			if(data == 'v')
			{
				iFile.get(data);
				// Vertex position
				if(data == ' ')
				{
					float x, y, z;
					iFile >> x >> y >> z;

					vertexPos[posCount++] = x;
					vertexPos[posCount++] = y;
					vertexPos[posCount++] = z;
				}
				// Vertex normal
				else if(data == 'n')
				{
					float x, y, z;
					iFile >> x >> y >> z;

					vertexNorm[normCount++] = x;
					vertexNorm[normCount++] = y;
					vertexNorm[normCount++] = z;
				}
				// Texture coord
				else if(data == 't')
				{
					float u, v;
					iFile >> u >> v;

					texCoords[texCount++] = u;
					texCoords[texCount++] = v;
				}
			}

			// Face data
			if(data == 'f')
			{
				for(int i = 0; i < 3; ++i)
				{
					// Position, normal, texture
					int ip, it, in;
					ip = it = in = 0;
					char extra;
					iFile >> ip >> extra >> it >> extra >> in;

					// Subtract 1 from each index
					--ip;
					--it;
					--in;

					// Check if the index at ip current exists
					int index = ip * vertexSize;
					if(vertices[index] == FLT_MAX)
					{
						// The vertex data does not exist, fill the vertex element with the appropriate data
						vertices[index + 0] = vertexPos[ip * 3];
						vertices[index + 1] = vertexPos[ip * 3 + 1];
						vertices[index + 2] = vertexPos[ip * 3 + 2];
					
						vertices[index + 3] = vertexNorm[in * 3];
						vertices[index + 4] = vertexNorm[in * 3 + 1];
						vertices[index + 5] = vertexNorm[in * 3 + 2];

						vertices[index + 6] = texCoords[it * 2];
						vertices[index + 7] = texCoords[it * 2 + 1];
					}

					// Set the index value
					indices[faceCount++] = ip;
				}
			}

			// End of line
			while(data != '\n')
			{
				iFile.get(data);
			}
			iFile.get(data);
		}
		iFile.close();

		// Write the file data
		std::fstream oFile(output.c_str(), std::ios::out | std::ios::binary);
		if(oFile.is_open())
		{
			// Write the file header
			oFile.write((char*)&fileHeader, sizeof(MeshFileHeader));

			// Write semantics
			if(posCount > 0)
			{
				VertexElementSemantic semantic = VERTEX_ELEMENT_SEMANTIC_POSITION;
				oFile.write((char*)&semantic, sizeof(VertexElementSemantic));
			}
			if(normCount > 0)
			{
				VertexElementSemantic semantic = VERTEX_ELEMENT_SEMANTIC_NORMAL;
				oFile.write((char*)&semantic, sizeof(VertexElementSemantic));
			}
			if(texCount > 0)
			{
				VertexElementSemantic semantic = VERTEX_ELEMENT_SEMANTIC_TEXCOORD;
				oFile.write((char*)&semantic, sizeof(VertexElementSemantic));
			}
			
			// Write vertex data
			oFile.write((char*)&vertices[0], sizeof(float) * vertices.size());

			// Write indices
			oFile.write((char*)&indices[0], sizeof(int) * indices.size());

			// Close the file
			oFile.close();
		}

		return true;
	}

}	// Namespace