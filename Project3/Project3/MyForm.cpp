#include "MyForm.h"

// This piece of code has been derived from the following YouTube tutorial video: https://www.youtube.com/watch?v=LF1cI7zeFm4&t=1409s
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project3::MyForm form;
    Application::Run(% form);
}