#include "Includes.h"

HANDLE fConsole = GetStdHandle(STD_OUTPUT_HANDLE);

DWORD get_proc_id(const char* proc_name)
{
	DWORD proc_id = 0;
	auto* const h_snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (h_snap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 proc_entry;
		proc_entry.dwSize = sizeof(proc_entry);

		if (Process32First(h_snap, &proc_entry))
		{
			do
			{
				if (!_stricmp(proc_entry.szExeFile, proc_name))
				{
					proc_id = proc_entry.th32ProcessID;
					break;
				}
			} while (Process32Next(h_snap, &proc_entry));
		}
	}

	CloseHandle(h_snap);
	return proc_id;
}
string random_string(size_t length)
{

	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ∆ÿ≈#!§#%&/()?`=*^_-.,;:®|$£$£@Ä{[]}|<>"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}
bool DoesFileExist(const char* name) {
	if (FILE* file = fopen(name, "r")) {
		fclose(file);
		return true;
	}

	return false;
}
void getHWIDdata() {
	//First part gets the HDD informations
	std::cout << "HWID information" << std::endl;
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		std::cout << "Volume Name: " << volumeName << std::endl;
		std::cout << "HDD Serial: " << serialNumber << std::endl;
		std::cout << "File System Type: " << fileSystemName << std::endl;
		std::cout << "Max Component Length: " << maxComponentLen << std::endl;
	}
	//Second part gets the computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	if (GetComputerName(
		computerName,
		&size))
	{
		std::cout << "Computer Name: " << computerName << std::endl;
	}
	//Third part gets the CPU Hash
	int cpuinfo[4] = { 0, 0, 0, 0 }; //EAX, EBX, ECX, EDX
	__cpuid(cpuinfo, 0);
	char16_t hash = 0;
	char16_t* ptr = (char16_t*)(&cpuinfo[0]);
	for (char32_t i = 0; i < 8; i++)
		hash += ptr[i];
	std::cout << "CPU Hash: " << hash << std::endl;
	system("pause");
}

/*bool LoadLibraryInject(DWORD ProcessId, const char* Dll)
{
	SetConsoleTextAttribute(fConsole, 2);
	cout << "[*] INJECTION METHOD 1";
	SetConsoleTextAttribute(fConsole, 4);
	char szPath[MAX_PATH];
	GetFullPathName(Dll, MAX_PATH, szPath, 0);

	auto* const h_proc = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);

	if (h_proc != INVALID_HANDLE_VALUE)
	{
		const LPVOID nt_open_file = GetProcAddress(LoadLibraryA("ntdll"), "NtOpenFile");
		if (nt_open_file)
		{
			char original_bytes[5];
			memcpy(original_bytes, nt_open_file, 5);
			WriteProcessMemory(h_proc, nt_open_file, original_bytes, 5, nullptr);
		}

		auto* loc = VirtualAllocEx(h_proc, nullptr, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		WriteProcessMemory(h_proc, loc, szPath, strlen(szPath) + 1, nullptr);
		auto* const h_thread = CreateRemoteThread(h_proc, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(LoadLibraryA), loc, 0, nullptr);

		if (h_thread) CloseHandle(h_thread);
	}

	if (h_proc) CloseHandle(h_proc);

	return TRUE;
}
*/
bool LoadLibraryInject2(DWORD ProcessId, const char* Dll)
{
	SetConsoleTextAttribute(fConsole, 2);
	cout << "[*] INJECTION METHOD 2";
	SetConsoleTextAttribute(fConsole, 4);
	if (ProcessId == NULL)
		return false;

	char CustomDLL[MAX_PATH];
	GetFullPathName(Dll, MAX_PATH, CustomDLL, 0);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(CustomDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	if (!WriteProcessMemory(hProcess, allocatedMem, CustomDLL, sizeof(CustomDLL), NULL))
		return FALSE;

	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

	if (hProcess)
		CloseHandle(hProcess);

	return TRUE;
}

bool LoadLibraryInject(DWORD ProcessId, const char* Dll)
{
	if (ProcessId == NULL)
		return false;

	char CustomDLL[MAX_PATH];
	GetFullPathName(Dll, MAX_PATH, CustomDLL, 0);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(CustomDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	if (!WriteProcessMemory(hProcess, allocatedMem, CustomDLL, sizeof(CustomDLL), NULL))
		return FALSE;

	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

	if (hProcess)
		CloseHandle(hProcess);

	return TRUE;
}