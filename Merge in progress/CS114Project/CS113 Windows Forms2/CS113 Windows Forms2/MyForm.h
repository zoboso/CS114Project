#pragma once
#include "Entity.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>



namespace WinFormsProjectTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Media;
	using namespace System::Drawing;
	
	//vector<vector<Entity>> world[10][10];
	//vector<vector<Entity>> world;

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
	private: Graphics^ gbmp;
	private: Graphics^ g;
	private: Bitmap^ player;
	private: Bitmap^ view;
	private: Bitmap^ enemy;
	private: Bitmap^ wall;
	private: Bitmap^ door;
	private: SoundPlayer^ musicplayer;
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
			this->CurrentHealth->ForeColor = System::Drawing::Color::DarkRed;
			this->CurrentHealth->Location = System::Drawing::Point(15, 19);
			this->CurrentHealth->Name = L"CurrentHealth";
			this->CurrentHealth->Size = System::Drawing::Size(35, 13);
			this->CurrentHealth->TabIndex = 0;
			this->CurrentHealth->Text = L"label1";
			// 
			// seperator
			// 
			this->seperator->AutoSize = true;
			this->seperator->ForeColor = System::Drawing::Color::DarkRed;
			this->seperator->Location = System::Drawing::Point(57, 19);
			this->seperator->Name = L"seperator";
			this->seperator->Size = System::Drawing::Size(12, 13);
			this->seperator->TabIndex = 1;
			this->seperator->Text = L"/";
			// 
			// MaxHealth
			// 
			this->MaxHealth->AutoSize = true;
			this->MaxHealth->ForeColor = System::Drawing::Color::DarkRed;
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
			this->GameBox->BackColor = System::Drawing::Color::White;
			this->GameBox->Location = System::Drawing::Point(134, 12);
			this->GameBox->Name = L"GameBox";
			this->GameBox->Size = System::Drawing::Size(350, 350);
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
			this->UpButton->Click += gcnew System::EventHandler(this, &MyForm::UpButton_Click);
			// 
			// BottomButton
			// 
			this->BottomButton->Location = System::Drawing::Point(50, 200);
			this->BottomButton->Name = L"BottomButton";
			this->BottomButton->Size = System::Drawing::Size(32, 23);
			this->BottomButton->TabIndex = 6;
			this->BottomButton->Text = L"v";
			this->BottomButton->UseVisualStyleBackColor = true;
			this->BottomButton->Click += gcnew System::EventHandler(this, &MyForm::BottomButton_Click);
			// 
			// LeftButton
			// 
			this->LeftButton->Location = System::Drawing::Point(18, 171);
			this->LeftButton->Name = L"LeftButton";
			this->LeftButton->Size = System::Drawing::Size(32, 23);
			this->LeftButton->TabIndex = 7;
			this->LeftButton->Text = L"<";
			this->LeftButton->UseVisualStyleBackColor = true;
			this->LeftButton->Click += gcnew System::EventHandler(this, &MyForm::LeftButton_Click);
			// 
			// RightButton
			// 
			this->RightButton->Location = System::Drawing::Point(79, 171);
			this->RightButton->Name = L"RightButton";
			this->RightButton->Size = System::Drawing::Size(32, 23);
			this->RightButton->TabIndex = 8;
			this->RightButton->Text = L">";
			this->RightButton->UseVisualStyleBackColor = true;
			this->RightButton->Click += gcnew System::EventHandler(this, &MyForm::RightButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(510, 376);
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
			this->Text = L"Find the Key";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->keyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		array < Entity^, 2 >^ world = gcnew array<Entity^,2>(10, 10);

		void populate(int lvl)
		{
			ifstream myFile;
			int level = lvl;
			myFile.open("level" + to_string(level) + ".txt");
			string line;
			int row = 0;
			while (getline(myFile, line)){
				for (int column = 0; column < line.length(); column++){
					char square = line[column];
					switch (square){
					case ' ':
					{
								world[row,column] =gcnew Entity(0, 0, row, column, 0, false, false, true, false, false, false);
								break;
					}
					case '1':
					{
								world[row,column] =gcnew Entity(0, 0, row, column, 0, false, false, false, false, false, false);
								break;
					}
					case '2':
					{
								world[row,column] =gcnew Entity(12, 2, row, column, 0, false, true, false, true, false, false);
								break;
					}
					case '3':
					{
								world[row,column] =gcnew Entity(1, 1, row, column, 0, false, true, false, false, false, false);
								break;
					}
					case '4':
					{
								world[row,column] =gcnew Entity(0, 0, row, column, 0, false, false, false, false, false, true);
								break;
					}

					}
				}
				row++;
				cout << endl;
			}
			myFile.close();
		}
		void draw()
		{

			for (int x = 0; x<10; x++)
			{
				for (int y = 0; y<10; y++)
				{
					if (world[x,y].isDoor() == true)
					{
						g->DrawImage(door, x * 36, y * 36);
					}
					if (world[x,y].isPlayer() == true)
					{
						g->DrawImage(player, x * 36, y * 36);
					}
					if (world[x,y].isActor() == true)
					{
						g->DrawImage(enemy, x * 36, y * 36);
					}
					if (world[x,y].isTraversable() == false && world[x,y].isActor() == false && world[x,y].isDoor()==false)
					{
						g->DrawImage(wall, x * 36, y * 36);
					}
				}
			}

		}
private: System::Void RightButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void UpButton_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LeftButton_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void BottomButton_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 g = GameBox->CreateGraphics();
			 player = gcnew Bitmap("PlayerV4.png");
			 enemy = gcnew Bitmap("EnemyV2.png");
			 wall = gcnew Bitmap("wall.png");
			 door = gcnew Bitmap("TrapDoor.png");
			 musicplayer = gcnew System::Media::SoundPlayer();
			 musicplayer->SoundLocation = "GuilesthemeWAV.wav";
			 populate(1);
			 draw();
			 musicplayer->Play();
			 musicplayer->PlayLooping();			 
			
}
};
}
