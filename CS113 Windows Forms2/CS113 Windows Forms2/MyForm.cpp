#include "MyForm.h"

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
}
