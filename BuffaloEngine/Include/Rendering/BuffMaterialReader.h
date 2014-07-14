// Filename: BuffMaterialReader.h
// Author: Gael Huber
#ifndef __BUFFMATERIALREADER_H__
#define __BUFFMATERIALREADER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffMaterial.h"

#include <fstream>
#include <vector>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	class Material::MaterialReader : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		MaterialReader();

		/**
		* Destructor
		*/
		~MaterialReader();

		/**
		* Read and initialize data for this material
		* @param
		*	Material* The material to populate
		* @return
		*	bool Returns true if successful
		*/
		bool Read(Material* material);

	private:
		/**
		* Read and tokenize a line from the material
		* @param
		*	std::vector<std::string>& The tokens of the line
		* @return
		*	bool True if successful
		*/
		bool ReadLine(std::vector<std::string>& tokens);

		/**
		* Check if this line is a block start indicator
		* @param
		*	const std::vector<std::string>& The tokens of the line
		* @return
		*	bool True if block start
		*/
		bool IsBlockStart(std::vector<std::string>& tokens);

		/**
		* Check if this line is a block end indicator
		* @param
		*	const std::vector<std::string>& The tokens of the line
		* @return
		*	bool True if block end
		*/
		bool IsBlockEnd(std::vector<std::string>& tokens);

		/**
		* Tokenize a line into individual strings
		* @param
		*	const std::string& The string to tokenize
		* @return
		*	std::vector<std::string> The vector of tokens
		*/
		std::vector<std::string> Tokenize(const std::string& line);

		/**
		* Read a layout block. Layouts describe the input layout and semantic types of vertices being 
		* passed into the material
		*/
		void ReadLayoutBlock();

		/**
		* Read a constant buffer block for a "per frame" buffer
		*/
		void ReadCBFrameBlock();

		/**
		* Read a constant buffer block for a "per material" buffer
		*/
		void ReadCBMaterialBlock();

		/**
		* Read a constant buffer block for a "per object" buffer
		*/
		void ReadCBObjectBlock();

		/**
		* Read a technique description. Techniques describe a series of passes that pair
		* rendering pipeline stages to various shaders
		*/
		void ReadTechniqueBlock();

	private:
		/**
		* The material being read
		*/
		Material* _material;

		/**
		* A handle to the file stream
		*/
		std::fstream _stream;
	};

	/** @} */

}	// Namespace

#endif // __BUFFMATERIALREADER_H__