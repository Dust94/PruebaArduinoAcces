#include "AccesForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PruebaIngresaAttention::AccesForm myForm;
	Application::Run(%myForm);
}