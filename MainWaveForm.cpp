#include "MainWaveForm.h"
#include <Windows.h>

using namespace WaveletForms;

[System::STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainWaveForm);
    return 0;
}