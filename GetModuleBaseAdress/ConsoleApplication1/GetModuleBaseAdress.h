#pragma once
#include <cstringt.h>
#include <tlhelp32.h>
extern DWORD GetModuleBaseAddress(const TCHAR* LPSTRModuleName, DWORD __DwordProcessId);