#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	MessageBox(NULL, TEXT("Hello, Windows 98!"), TEXT("HelloMsg"), 0);

	::direct2D::testlist::unTidied::direct2Dtest();

	return 0;
}
