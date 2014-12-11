#include "MyForm2.h"

using namespace Project6;
using namespace std;
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <algorithm>



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{			
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Application::Run(gcnew MyForm());
	
	

	return 0;
}
