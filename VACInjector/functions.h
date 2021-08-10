#include "includes.h"


DWORD get_proc_id(const char* proc_name);
string random_string(size_t length);

bool DoesFileExist(const char* name);
void getHWIDdata();

bool LoadLibraryInject(DWORD ProcessId, const char* Dll);
bool LoadLibraryInject2(DWORD ProcessId, const char* Dll);

