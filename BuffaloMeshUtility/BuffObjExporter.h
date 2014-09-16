// Filename: BuffObjExporter.h
// Author: Gael Huber
#ifndef __BUFFOBJEXPORTER_H__
#define __BUFFOBJEXPORTER_H__

#include "stdafx.h"
#include <string>

namespace BuffaloEngine
{
	/**
	* File header for .MESH file extension
	*/
	struct MeshFileHeader
	{
		char sig[2];
		int vertexCount;
		int vertexElements;
		int indexCount;
	};

	/**
	* Vertex element semantics
	*/
	enum VertexElementSemantic
	{
		VERTEX_ELEMENT_SEMANTIC_UNKNOWN = 0,
		VERTEX_ELEMENT_SEMANTIC_POSITION,
		VERTEX_ELEMENT_SEMANTIC_NORMAL,
		VERTEX_ELEMENT_SEMANTIC_TEXCOORD
	};

	/**
	* The core logic for the file export
	*/
	class ObjExporter
	{
	public:
		/**
		* Default constructor
		*/
		ObjExporter();

		/**
		* Destructor
		*/
		~ObjExporter();

		/**
		* Export the file
		* @param
		*	const string& The input file
		* @param
		*	const string& The output file
		* @return
		*	bool Returns true if the export was successful
		*/
		bool Export(const std::string& input, const std::string& output);
	};

}	// Namespace

#endif // __BUFFOBJEXPORTER_H__