#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba21::MyForm^ f = gcnew Laba21::MyForm; 
    Application::Run(f);
}



