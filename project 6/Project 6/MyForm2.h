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
	private: SoundPlayer^ musicplayer;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(637, 212);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
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
			this->ResumeLayout(false);

		}
#pragma endregion

		int px = 0;
		int py = 0;
		int ex = 16;
		int ey = 4;
		
		
		

	private: System::Void guess_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void check_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter8_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void letter9_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				  g = panel1->CreateGraphics();
				  player = gcnew Bitmap("K:/CS114/Github/CS114Project/Images/PlayerV2.png");
				  enemy = gcnew Bitmap("K:/CS114/Github/CS114Project/Images/EnemyV1.png");

				  musicplayer = gcnew System::Media::SoundPlayer();
				  musicplayer->SoundLocation = "K:/CS114/Github/CS114Project/GuilesthemeWAV.wav";
				  musicplayer->Play(); 
				  musicplayer->PlayLooping(); 


	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {		 
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 panel1->Refresh();

			 if (px < 17)
			 {
				 
				 px++;
				 g->DrawImage(player, px * 35, py * 35);
			 } 
			 else g->DrawImage(player, px * 35, py * 35);

				 
				switch (emove)
				 {
					 case 1:
						 if (ey < 5)
						 {
							 ey++;
							 g->DrawImage(enemy, ex * 35, ey * 35);
						 } 
						 else g->DrawImage(enemy, ex * 35, ey * 35);
						 break;
					 case 2:
						 if (ex < 17)
						 {
							 ex++;
							 g->DrawImage(enemy, ex * 35, ey * 35);
						 }
						 else g->DrawImage(enemy, ex * 35, ey * 35);
						 break;
					 case 3:
						 if (ey > 0)
						 {
							 ey--;
							 g->DrawImage(enemy, ex * 35, ey * 35);
						 } 
						 else g->DrawImage(enemy, ex * 35, ey * 35);
						 break;
						 
					 case 4:
						 if (ex > 0)
						 {
							 ex--;
							 g->DrawImage(enemy, ex * 35, ey * 35);
						 }
						 else g->DrawImage(enemy, ex * 35, ey * 35);
						 break;
				 }	 
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 panel1->Refresh();

			 if (py < 5)
			 {
				 py++;
				 g->DrawImage(player, px * 35, py * 35);
			 } 
			 else g->DrawImage(player, px * 35, py * 35);

			 switch (emove)
			 {
			 case 1:
				 if (ey < 5)
				 {
					 ey++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 2:
				 if (ex < 17)
				 {
					 ex++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 3:
				 if (ey > 0)
				 {
					 ey--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;

			 case 4:
				 if (ex > 0)
				 {
					 ex--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 }
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 panel1->Refresh();

			 if (px > 0)
			 {
				 px--;
				 g->DrawImage(player, px * 35, py * 35);
			 } 
			 else g->DrawImage(player, px * 35, py * 35);

			 switch (emove)
			 {
			 case 1:
				 if (ey < 5)
				 {
					 ey++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 2:
				 if (ex < 17)
				 {
					 ex++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 3:
				 if (ey > 0)
				 {
					 ey--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;

			 case 4:
				 if (ex > 0)
				 {
					 ex--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 }


}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 srand(time(NULL));
			 int emove = rand() % 4 + 1;
			 panel1->Refresh();

			 if (py > 0)
			 {
				py--;
				 g->DrawImage(player, px * 35, py * 35);
			 } 
			 else g->DrawImage(player, px * 35, py * 35);

			 switch (emove)
			 {
			 case 1:
				 if (ey < 5)
				 {
					 ey++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 2:
				 if (ex < 17)
				 {
					 ex++;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 case 3:
				 if (ey > 0)
				 {
					 ey--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;

			 case 4:
				 if (ex > 0)
				 {
					 ex--;
					 g->DrawImage(enemy, ex * 35, ey * 35);
				 }
				 else g->DrawImage(enemy, ex * 35, ey * 35);
				 break;
			 }
}
};
}
