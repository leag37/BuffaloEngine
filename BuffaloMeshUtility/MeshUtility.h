#pragma once

#include "BuffObjExporter.h"

namespace BuffaloMeshUtility {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MeshUtility
	/// </summary>
	public ref class MeshUtility : public System::Windows::Forms::Form
	{
	public:
		MeshUtility(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MeshUtility()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnInputFile;
	protected: 


	private: System::Windows::Forms::TextBox^  txtInputFile;
	private: System::Windows::Forms::OpenFileDialog^  dlgInputFile;


	private: System::Windows::Forms::Button^  btnExport;
	private: System::Windows::Forms::TextBox^  txtOutputFile;

	private: System::Windows::Forms::Button^  btnOutputFile;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::FolderBrowserDialog^  dlgOutputFile;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnInputFile = (gcnew System::Windows::Forms::Button());
			this->txtInputFile = (gcnew System::Windows::Forms::TextBox());
			this->dlgInputFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnExport = (gcnew System::Windows::Forms::Button());
			this->txtOutputFile = (gcnew System::Windows::Forms::TextBox());
			this->btnOutputFile = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dlgOutputFile = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input File Name:";
			// 
			// btnInputFile
			// 
			this->btnInputFile->Location = System::Drawing::Point(215, 25);
			this->btnInputFile->Name = L"btnInputFile";
			this->btnInputFile->Size = System::Drawing::Size(24, 21);
			this->btnInputFile->TabIndex = 1;
			this->btnInputFile->Text = L"...";
			this->btnInputFile->UseVisualStyleBackColor = true;
			this->btnInputFile->Click += gcnew System::EventHandler(this, &MeshUtility::OnInputClick);
			// 
			// txtInputFile
			// 
			this->txtInputFile->Location = System::Drawing::Point(12, 25);
			this->txtInputFile->Name = L"txtInputFile";
			this->txtInputFile->Size = System::Drawing::Size(197, 20);
			this->txtInputFile->TabIndex = 0;
			// 
			// btnExport
			// 
			this->btnExport->Location = System::Drawing::Point(81, 137);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(75, 23);
			this->btnExport->TabIndex = 4;
			this->btnExport->Text = L"Export";
			this->btnExport->UseVisualStyleBackColor = true;
			this->btnExport->Click += gcnew System::EventHandler(this, &MeshUtility::OnExportClick);
			// 
			// txtOutputFile
			// 
			this->txtOutputFile->Location = System::Drawing::Point(12, 89);
			this->txtOutputFile->Name = L"txtOutputFile";
			this->txtOutputFile->Size = System::Drawing::Size(197, 20);
			this->txtOutputFile->TabIndex = 2;
			// 
			// btnOutputFile
			// 
			this->btnOutputFile->Location = System::Drawing::Point(215, 89);
			this->btnOutputFile->Name = L"btnOutputFile";
			this->btnOutputFile->Size = System::Drawing::Size(24, 21);
			this->btnOutputFile->TabIndex = 3;
			this->btnOutputFile->Text = L"...";
			this->btnOutputFile->UseVisualStyleBackColor = true;
			this->btnOutputFile->Click += gcnew System::EventHandler(this, &MeshUtility::OnOutputClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Output File Name:";
			// 
			// MeshUtility
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(251, 385);
			this->Controls->Add(this->txtOutputFile);
			this->Controls->Add(this->btnOutputFile);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnExport);
			this->Controls->Add(this->txtInputFile);
			this->Controls->Add(this->btnInputFile);
			this->Controls->Add(this->label1);
			this->Name = L"MeshUtility";
			this->Text = L"Mesh Utility";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void OnInputClick(System::Object^  sender, System::EventArgs^  e) 
		{
			if(dlgInputFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				txtInputFile->Text = dlgInputFile->FileName;
			}
		}
	
		System::Void OnOutputClick(System::Object^  sender, System::EventArgs^  e) 
		{
			if(dlgOutputFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				txtOutputFile->Text = dlgOutputFile->SelectedPath + "\\" + System::IO::Path::GetFileNameWithoutExtension(dlgInputFile->FileName) + ".mesh";
			}
		}

		System::Void OnExportClick(System::Object^  sender, System::EventArgs^  e) 
		{
			// Create a new exporter and pass in the input and output paths
			BuffaloEngine::ObjExporter exporter;
			std::string input;
			for(System::CharEnumerator^ enumerator = txtInputFile->Text->GetEnumerator(); enumerator->MoveNext() == true; )
			{
				input += static_cast<char>(enumerator->Current);
			}
			
			std::string output;
			for(System::CharEnumerator^ enumerator = txtOutputFile->Text->GetEnumerator(); enumerator->MoveNext() == true; )
			{
				output += static_cast<char>(enumerator->Current);
			}
			
			exporter.Export(input, output);
		}
	};
}

