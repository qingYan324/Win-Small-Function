#include "GetModuleBaseAdress.h"
#include "pch.h"
DWORD GetModuleBaseAddress(const TCHAR* LPSTRModuleName, DWORD __DwordProcessId) //����1����������	qq.exe  ����2 ����ID
{
	MODULEENTRY32 lpModuleEntry = { 0 };
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, __DwordProcessId);
	if (!hSnapShot)
		return NULL;
	lpModuleEntry.dwSize = sizeof(lpModuleEntry);
	BOOL __RunModule = Module32First(hSnapShot, &lpModuleEntry);
	while (__RunModule)
	{
		if (!_tcscmp(lpModuleEntry.szModule, LPSTRModuleName))
		{
			CloseHandle(hSnapShot);
			return (DWORD)lpModuleEntry.modBaseAddr;
		}
		__RunModule = Module32Next(hSnapShot, &lpModuleEntry);
	}
	CloseHandle(hSnapShot);
	return NULL;
}

