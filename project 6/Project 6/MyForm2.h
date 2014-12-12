#pragma once

#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <cstddef>
#include <ctime>


namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Media;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System;

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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel1;
	private: Graphics^ gbmp;
	private: Graphics^ g;
	private: Bitmap^ player;
	private: Bitmap^ view;
	private: Bitmap^ enemy;
	private: Bitmap^ wall;
	private: Bitmap^ door;
	private: SoundPlayer^ musicplayer;
	private: System::Windows::Forms::Label^  label1;


	protected:
















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(132, 237);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"UP";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(51, 260);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"LEFT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(213, 260);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"RIGHT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(132, 278);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"DOWN";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// panel1
			// 
//			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(637, 212);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Miramonte", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkRed;
			this->label1->Location = System::Drawing::Point(290, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 26);
			this->label1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(661, 346);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		int px = 0;
		int py = 0;
		int ex = 16;
		int ey = 4;
		int ehealth = 1;
		int phealth = 2;
		bool key = false;
		int level = 1;


		void E1AILevel1()
		{
			srand(time(NULL));
			int emove = rand() % 4 + 1;

			switch (emove)
			{
			case 1:
				if (ehealth > 0 && phealth > 0)
				{
					if (ey < 5)
					{
						ey++;
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
					else g->DrawImage(enemy, ex * 35, ey * 35);

					if (ex == 7 && ey == 0)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 0)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 1)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 1)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 1 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 2 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 3 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 4 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 5 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 6 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 9 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 10 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 11 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 12 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 13 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 14 && ey == 2)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 3)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 3)
					{
						ey--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}
					break;
				}
			case 2:
				if (ehealth > 0 && phealth > 0)
				{
					if (ex < 17)
					{
						ex++;
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
					else g->DrawImage(enemy, ex * 35, ey * 35);

					if (ex == 7 && ey == 0)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 0)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 1)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 1)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 1 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 2 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 3 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 4 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 5 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 6 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 9 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 10 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 11 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 12 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 13 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 14 && ey == 2)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 3)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 3)
					{
						ex--;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					break;
				}
			case 3:
				if (ehealth > 0 && phealth > 0)
				{
					if (ey > 0)
					{
						ey--;
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
					else g->DrawImage(enemy, ex * 35, ey * 35);

					if (ex == 7 && ey == 0)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 0)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 1)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 1)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 1 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 2 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 3 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 4 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 5 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 6 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 9 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 10 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 11 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 12 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 13 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 14 && ey == 2)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 3)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 3)
					{
						ey++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					break;
				}
			case 4:
				if (ehealth > 0 && phealth > 0)
				{
					if (ex > 0)
					{
						ex--;
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
					else g->DrawImage(enemy, ex * 35, ey * 35);

					if (ex == 7 && ey == 0)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 0)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 1)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 1)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 1 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 2 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 3 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 4 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 5 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 6 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 9 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 10 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 11 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 12 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 13 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 14 && ey == 2)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 7 && ey == 3)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					if (ex == 8 && ey == 3)
					{
						ex++;
						Refresh();
						g->DrawImage(door, 0 * 35, 0 * 35);
						drawWallLevel1();
						g->DrawImage(player, px * 35, py * 35);
						if (ehealth > 0)
						{
							g->DrawImage(enemy, ex * 35, ey * 35);
						}
					}

					break;
				}
			}
		}

		void E1AILevel2()
		{
		srand(time(NULL));
		int emove = rand() % 4 + 1;

		switch (emove)
		{
		case 1:
			if (ehealth > 0 && phealth > 0)
			{
				if (ey < 5)
				{
					ey++;
					g->DrawImage(enemy, ex * 35, ey * 35);
				}
				else g->DrawImage(enemy, ex * 35, ey * 35);

				if (ex == 7 && ey == 0)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 0)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 1)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 1)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 9 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 10 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 2)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 3)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 3)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 3 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 3)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 4)
				{
					ey--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				break;
			}
		case 2:
			if (ehealth > 0 && phealth > 0)
			{
				if (ex < 17)
				{
					ex++;
					g->DrawImage(enemy, ex * 35, ey * 35);
				}
				else g->DrawImage(enemy, ex * 35, ey * 35);

				if (ex == 7 && ey == 0)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 0)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 1)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 1)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 9 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 10 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 2)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 3)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 3)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 3 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 3)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 4)
				{
					ex--;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				break;
			}
		case 3:
			if (ehealth > 0 && phealth > 0)
			{
				if (ey > 0)
				{
					ey--;
					g->DrawImage(enemy, ex * 35, ey * 35);
				}
				else g->DrawImage(enemy, ex * 35, ey * 35);

				if (ex == 7 && ey == 0)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 0)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 1)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 1)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 9 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 10 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 2)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 3)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 3)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 3 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 3)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 4)
				{
					ey++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				break;
			}
		case 4:
			if (ehealth > 0 && phealth > 0)
			{
				if (ex > 0)
				{
					ex--;
					g->DrawImage(enemy, ex * 35, ey * 35);
				}
				else g->DrawImage(enemy, ex * 35, ey * 35);

				if (ex == 7 && ey == 0)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 0)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 1)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 1)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 9 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 10 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 2)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 3)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 3)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 7 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 8 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 6 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 5 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 4 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 3 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 3)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				if (ex == 11 && ey == 4)
				{
					ex++;
					Refresh();
					g->DrawImage(door, 0 * 35, 0 * 35);
					drawWallLevel2();
					g->DrawImage(player, px * 35, py * 35);
					if (ehealth > 0)
					{
						g->DrawImage(enemy, ex * 35, ey * 35);
					}
				}

				break;
			}
		}
		}

		void drawWallLevel1()
		{
			g->DrawImage(wall, 7 * 35, 0 * 35);
			g->DrawImage(wall, 8 * 35, 0 * 35);
			g->DrawImage(wall, 7 * 35, 1 * 35);
			g->DrawImage(wall, 8 * 35, 1 * 35);
			g->DrawImage(wall, 1 * 35, 2 * 35);
			g->DrawImage(wall, 2 * 35, 2 * 35);
			g->DrawImage(wall, 3 * 35, 2 * 35);
			g->DrawImage(wall, 4 * 35, 2 * 35);
			g->DrawImage(wall, 5 * 35, 2 * 35);
			g->DrawImage(wall, 6 * 35, 2 * 35);
			g->DrawImage(wall, 7 * 35, 2 * 35);
			g->DrawImage(wall, 8 * 35, 2 * 35);
			g->DrawImage(wall, 9 * 35, 2 * 35);
			g->DrawImage(wall, 10 * 35, 2 * 35);
			g->DrawImage(wall, 11 * 35, 2 * 35);
			g->DrawImage(wall, 12 * 35, 2 * 35);
			g->DrawImage(wall, 13 * 35, 2 * 35);
			g->DrawImage(wall, 14 * 35, 2 * 35);
			g->DrawImage(wall, 7 * 35, 3 * 35);
			g->DrawImage(wall, 8 * 35, 3 * 35);
		}

		void drawWallLevel2()
		{
			g->DrawImage(wall, 7 * 35, 0 * 35);
			g->DrawImage(wall, 8 * 35, 0 * 35);
			g->DrawImage(wall, 7 * 35, 1 * 35);
			g->DrawImage(wall, 8 * 35, 1 * 35);
			g->DrawImage(wall, 4 * 35, 2 * 35);
			g->DrawImage(wall, 5 * 35, 2 * 35);
			g->DrawImage(wall, 6 * 35, 2 * 35);
			g->DrawImage(wall, 7 * 35, 2 * 35);
			g->DrawImage(wall, 8 * 35, 2 * 35);
			g->DrawImage(wall, 9 * 35, 2 * 35);
			g->DrawImage(wall, 10 * 35, 2 * 35);
			g->DrawImage(wall, 11 * 35, 2 * 35);
			g->DrawImage(wall, 7 * 35, 3 * 35);
			g->DrawImage(wall, 8 * 35, 3 * 35);
			g->DrawImage(wall, 8 * 35, 4 * 35);
			g->DrawImage(wall, 7 * 35, 4 * 35);
			g->DrawImage(wall, 6 * 35, 4 * 35);
			g->DrawImage(wall, 5 * 35, 4 * 35);
			g->DrawImage(wall, 11 * 35, 3 * 35);
			g->DrawImage(wall, 11 * 35, 4 * 35);
			g->DrawImage(wall, 3 * 35, 4 * 35);
			g->DrawImage(wall, 4 * 35, 4 * 35);
		}
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				  g = panel1->CreateGraphics();
				  player = gcnew Bitmap("PlayerV3.png");
				  enemy = gcnew Bitmap("EnemyV1.png");
				  wall = gcnew Bitmap("wall.png");
				  door = gcnew Bitmap("TrapDoor.png");

				  musicplayer = gcnew System::Media::SoundPlayer();
				  musicplayer->SoundLocation = "GuilesthemeWAV.wav";
				  musicplayer->Play(); 
				  musicplayer->PlayLooping(); 


	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 if (px == 0 && py == 0 && ey == 4 && ex == 16 && level == 1)
				 {
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 drawWallLevel1();
				 }
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 Refresh();

			 if (level == 1)
			 {
				 drawWallLevel1();
				 g->DrawImage(door, 0 * 35, 0 * 35);

				if (phealth > 0)
				{
					 if (px < 17)
					 {
						 px++;
						 g->DrawImage(player, px * 35, py * 35);
					}
						else g->DrawImage(player, px * 35, py * 35);
				}

				E1AILevel1();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 Refresh();
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 7 && py == 0)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 0)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 1)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 1)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 1 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 2 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 12 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 13 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 14 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }
			 }

			 if (level == 2)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel2();

				 if (phealth > 0)
				 {
					 if (px < 17)
					 {
						 px++;
						 g->DrawImage(player, px * 35, py * 35);
					 }
					 else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel2();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 level++;
				 }

				 if (px == 7 && py == 0)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 0)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 1)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 1)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 3)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 4)
				 {
					 px--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }
			 }
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 Refresh();


			 if (level == 1)
			 {
				 drawWallLevel1();
				 g->DrawImage(door, 0 * 35, 0 * 35);

				 if (phealth > 0)
				 {
					 if (py < 5)
					 {
						 py++;
						 g->DrawImage(player, px * 35, py * 35);
					 }
					 else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel1();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 Refresh();
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 7 && py == 0)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 0)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 1)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 1)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 1 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 2 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 12 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 13 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 14 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }
			 }

			 if (level == 2)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel2();

				 if (phealth > 0)
				 {
					 if (py < 5)
					 {
						 py++;
						 g->DrawImage(player, px * 35, py * 35);
					 }
					 else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel2();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 ehealth = 1;
					 key = false;
					 level++;
				 }

				 if (px == 8 && py == 1)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 3)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 4)
				 {
					 py--;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }
			 }
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 Refresh();



			 if (level == 1)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel1();

				if (phealth > 0)
				{
					 if (px > 0)
					{
						 px--;
						g->DrawImage(player, px * 35, py * 35);
					 }
					else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel1();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 Refresh();
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 7 && py == 0)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 0)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 1)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 1)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 1 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 2 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 12 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 13 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 14 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

			 }

			 if (level == 2)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel2();

				 if (phealth > 0)
				 {
					 if (px > 0)
					 {
						 px--;
						 g->DrawImage(player, px * 35, py * 35);
					 }
					 else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel2();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 8 && py == 1)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 3)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 4)
				 {
					 px++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

			 }
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 Refresh();



			 if (level == 1)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel1();

				 if (phealth > 0)
				 {
					 if (py > 0)
					 {
						 py--;
						 g->DrawImage(player, px * 35, py * 35);
					}
					else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel1();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 Refresh();
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 7 && py == 0)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 0)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 1)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 1)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 1 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 2 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 12 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 13 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 14 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel1();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }
			 }

			 if (level == 2)
			 {
				 g->DrawImage(door, 0 * 35, 0 * 35);
				 drawWallLevel2();

				 if (phealth > 0)
				 {
					 if (py > 0)
					 {
						 py--;
						 g->DrawImage(player, px * 35, py * 35);
					 }
					 else g->DrawImage(player, px * 35, py * 35);
				 }

				 E1AILevel2();

				 if (ey == py && ex == px && phealth > 0)
				 {
					 ehealth--;
					 phealth--;
					 key = true;
				 }

				 if (ehealth == 0)
				 {
					 Refresh();
					 g->DrawImage(player, px * 35, py * 35);
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
				 }

				 if (phealth == 0)
				 {
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(enemy, ex * 35, ey * 35);
					 label1->Text = "DEAD";
				 }

				 if (py == 0 && px == 0 && key == true)
				 {
					 px = 0;
					 py = 0;
					 ex = 16;
					 ey = 4;
					 key = false;
					 ehealth = 1;
					 level++;
				 }

				 if (px == 8 && py == 1)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 9 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 10 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 2)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 3)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 3)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 7 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 8 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 6 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 5 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 4 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 3 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 3)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

				 if (px == 11 && py == 4)
				 {
					 py++;
					 Refresh();
					 g->DrawImage(door, 0 * 35, 0 * 35);
					 drawWallLevel2();
					 g->DrawImage(player, px * 35, py * 35);
					 if (ehealth > 0)
					 {
						 g->DrawImage(enemy, ex * 35, ey * 35);
					 }
				 }

			 }
}
};
}
