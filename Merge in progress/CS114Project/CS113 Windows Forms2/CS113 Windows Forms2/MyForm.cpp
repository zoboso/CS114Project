#include "MyForm.h"
#include <vector>
#include "Entity.h"
#include "input.h"



using namespace WinFormsProjectTemplate; //name of project
using namespace std;

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
		input(map, level++);

	}
}
