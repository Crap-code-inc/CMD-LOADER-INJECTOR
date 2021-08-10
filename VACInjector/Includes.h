#pragma once

#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <algorithm> // random name
#include <thread> // Threads
#include <tchar.h>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")
#include <filesystem>
#include <limits.h>
#include <direct.h>
#include <intrin.h>
#include <iomanip> //Display middle 

using namespace std;


#include <conio.h>//For _getch().
#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer
//#define HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

static int injectorMethod;

#include "Animations.h"
#include "functions.h"

