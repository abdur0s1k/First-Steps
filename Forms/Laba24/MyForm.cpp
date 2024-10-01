#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ argv) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba24::MyForm^ f = gcnew Laba24::MyForm;
    Application::Run(f);
}
