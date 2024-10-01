#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ argv) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba27::MyForm^ form = gcnew Laba27::MyForm;
    Application::Run(form);

    return 0;
}
