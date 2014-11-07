#pragma once

namespace WinFormsProjectTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  CurrentHealth;
	protected:
	private: System::Windows::Forms::Label^  seperator;
	private: System::Windows::Forms::Label^  MaxHealth;
	private: System::Windows::Forms::PictureBox^  keyBox;
	private: System::Windows::Forms::PictureBox^  GameBox;
	private: System::Windows::Forms::Button^  UpButton;
	private: System::Windows::Forms::Button^  BottomButton;
	private: System::Windows::Forms::Button^  LeftButton;
	private: System::Windows::Forms::Button^  RightButton;

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
			this->CurrentHealth = (gcnew System::Windows::Forms::Label());
			this->seperator = (gcnew System::Windows::Forms::Label());
			this->MaxHealth = (gcnew System::Windows::Forms::Label());
			this->keyBox = (gcnew System::Windows::Forms::PictureBox());
			this->GameBox = (gcnew System::Windows::Forms::PictureBox());
			this->UpButton = (gcnew System::Windows::Forms::Button());
			this->BottomButton = (gcnew System::Windows::Forms::Button());
			this->LeftButton = (gcnew System::Windows::Forms::Button());
			this->RightButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->keyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameBox))->BeginInit();
			this->SuspendLayout();
			// 
			// CurrentHealth
			// 
			this->CurrentHealth->AutoSize = true;
			this->CurrentHealth->Location = System::Drawing::Point(15, 19);
			this->CurrentHealth->Name = L"CurrentHealth";
			this->CurrentHealth->Size = System::Drawing::Size(35, 13);
			this->CurrentHealth->TabIndex = 0;
			this->CurrentHealth->Text = L"label1";
			// 
			// seperator
			// 
			this->seperator->AutoSize = true;
			this->seperator->Location = System::Drawing::Point(57, 19);
			this->seperator->Name = L"seperator";
			this->seperator->Size = System::Drawing::Size(12, 13);
			this->seperator->TabIndex = 1;
			this->seperator->Text = L"/";
			// 
			// MaxHealth
			// 
			this->MaxHealth->AutoSize = true;
			this->MaxHealth->Location = System::Drawing::Point(76, 19);
			this->MaxHealth->Name = L"MaxHealth";
			this->MaxHealth->Size = System::Drawing::Size(35, 13);
			this->MaxHealth->TabIndex = 2;
			this->MaxHealth->Text = L"label1";
			// 
			// keyBox
			// 
			this->keyBox->Location = System::Drawing::Point(12, 35);
			this->keyBox->Name = L"keyBox";
			this->keyBox->Size = System::Drawing::Size(98, 88);
			this->keyBox->TabIndex = 3;
			this->keyBox->TabStop = false;
			// 
			// GameBox
			// 
			this->GameBox->Location = System::Drawing::Point(134, 12);
			this->GameBox->Name = L"GameBox";
			this->GameBox->Size = System::Drawing::Size(496, 341);
			this->GameBox->TabIndex = 4;
			this->GameBox->TabStop = false;
			// 
			// UpButton
			// 
			this->UpButton->Location = System::Drawing::Point(50, 142);
			this->UpButton->Name = L"UpButton";
			this->UpButton->Size = System::Drawing::Size(32, 23);
			this->UpButton->TabIndex = 5;
			this->UpButton->Text = L"^";
			this->UpButton->UseVisualStyleBackColor = true;
			// 
			// BottomButton
			// 
			this->BottomButton->Location = System::Drawing::Point(50, 200);
			this->BottomButton->Name = L"BottomButton";
			this->BottomButton->Size = System::Drawing::Size(32, 23);
			this->BottomButton->TabIndex = 6;
			this->BottomButton->Text = L"v";
			this->BottomButton->UseVisualStyleBackColor = true;
			// 
			// LeftButton
			// 
			this->LeftButton->Location = System::Drawing::Point(18, 171);
			this->LeftButton->Name = L"LeftButton";
			this->LeftButton->Size = System::Drawing::Size(32, 23);
			this->LeftButton->TabIndex = 7;
			this->LeftButton->Text = L"<";
			this->LeftButton->UseVisualStyleBackColor = true;
			// 
			// RightButton
			// 
			this->RightButton->Location = System::Drawing::Point(79, 171);
			this->RightButton->Name = L"RightButton";
			this->RightButton->Size = System::Drawing::Size(32, 23);
			this->RightButton->TabIndex = 8;
			this->RightButton->Text = L">";
			this->RightButton->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 368);
			this->Controls->Add(this->RightButton);
			this->Controls->Add(this->LeftButton);
			this->Controls->Add(this->BottomButton);
			this->Controls->Add(this->UpButton);
			this->Controls->Add(this->GameBox);
			this->Controls->Add(this->keyBox);
			this->Controls->Add(this->MaxHealth);
			this->Controls->Add(this->seperator);
			this->Controls->Add(this->CurrentHealth);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->keyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
