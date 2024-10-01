#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba::MyForm^ f = gcnew Laba::MyForm; //WinFormsTest - имя вашего проекта
    Application::Run(f);
}
