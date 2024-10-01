#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba20::MyForm^ f = gcnew Laba20::MyForm; //WinFormsTest - имя вашего проекта
    Application::Run(f);
}
