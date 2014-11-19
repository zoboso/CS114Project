#include "MyForm.h"
#include <vector>
#include "C:\Users\Joseph\Documents\GitHub\CS114Project\Controller\Controller\Entity.h"
#include "C:\Users\Joseph\Documents\GitHub\CS114Project\Controller\Controller\Entity.cpp"
#include "Input.cpp"

using namespace WinFormsProjectTemplate; //name of project

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows visual effects
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MyForm());
	return 0;
	
	std::vector< std::vector< Entity >> map;
	int level = 1;

	{
		//Level's loop
		input(map, level++)

	}
}
