// WhimsicalEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
#ifndef _DEBUG
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif // !_DEBUG

	//LYViewerApp app;

	GLYEngine->BindApp(&app, a_iArgc, a_pszArgv);

	if (GLYEngine->Initialize())
	{


		GLYEngine->Run();
		GLYEngine->Finalize();

#ifdef _DEBUG
		LY_LOG_INFO("Press any key to safely close the console...");
		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
		std::getchar();
#endif
		return EXIT_SUCCESS;
	}
#ifndef _DEBUG
	::FreeConsole();
#endif // !_DEBUG
	return EXIT_FAILURE;
}
