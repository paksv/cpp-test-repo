// cpp-test-repo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include2.h"
#include <Windows.h>
#include <VersionHelpers.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1)
	{
		printf("A command is required!");
		return 2;
	} else if (_tcscmp(argv[1], _T("version")) == 0) {
		OSVERSIONINFOEX osvi;
		BOOL bIsWinXPOrLater;

		ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
		GetVersionEx((OSVERSIONINFO*)&osvi);

		printf("Windows version: %d.%d %ls (build %d, platformId: %d)", osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.szCSDVersion, osvi.dwBuildNumber, osvi.dwPlatformId);
	} 	else if (_tcscmp(argv[1], _T("action")) == 0) {
#ifdef _WIN_SERVER_VAR_
		printf("This is a server platform product\n");
#elif defined _WIN_DESKTOP_VAR_
		printf("This is a desktop product\n");
#else
		printf("No platform specified on compilation\n");
		return 2;
#endif
	} 	else if (_tcscmp(argv[1], _T("test")) == 0) {
#ifdef _WIN_SERVER_VAR_
		if (!IsWindowsServer())
		{
			printf("This binary is compiled for Windows Server!\n");
			return 2;
		} else
		{
			printf("Test OK");
			return 0;
		}
#elif defined  _WIN_DESKTOP_VAR_
		if (IsWindowsServer())
		{
			printf("This binary is compiled for Windows Desktop\n");
			return 2;
		} else
		{
			printf("Test OK");
			return 0;
		}
#else
		printf("No platform specified on compilation\n");
		return 2;
#endif
	} else
	{
		wsprintf(_T("Unknown command specified: %s"), argv[1]);
	}


	return 0;
}

