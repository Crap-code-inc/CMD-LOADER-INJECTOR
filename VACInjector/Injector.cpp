#include "Includes.h"

//loginManager loginManagerObj = new loginManager();
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void injectCSGO() {
	//Downloading dll
	string location = "DLL.dll";
	string url = "http://javel.dk/DLL.dll";
	LPCSTR lpcURL = url.c_str();
	LPCSTR lpclocation = location.c_str();
	HRESULT hr = URLDownloadToFile(NULL, lpcURL, lpclocation, 0, NULL);

	DWORD proc_id = 0;
	while (!proc_id)
	{
		cout << "[-] Game not found, retrying in 2 secounds" << endl;
		proc_id = get_proc_id("csgo.exe");
		Sleep(2000);
	}

	if (proc_id) {
		cout << "[+] Proccess found, waiting for bootup" << endl;
		cout << "[*] Injecting in 30 secounds \n";
		Sleep(30000);
		if (DoesFileExist("DLL.dll")) {
			cout << "[*] INJECTION STARTED \n" << endl;
			if (LoadLibraryInject2(proc_id, "DLL.dll")) {
				Sleep(2000);
			}
			else {
				cout << "Injection faild" << endl;
				Sleep(5000);
				ExitProcess(0);
			}
		}
		else {
			cout << "The DLL was not found, make sure you got internet connection and try again" << endl;
			system("pause");
			ExitProcess(0);
		}
	}

	cout << "[+] INJECTION SUCCESFULL";
	Sleep(3000);
}
void injectCustom() {
	DWORD proc_id = 0;
	while (!proc_id)
	{
		cout << "[-] Game not found, retrying in 2 secounds" << endl;
		proc_id = get_proc_id("csgo.exe");
		Sleep(2000);
	}

	if (proc_id) {
		cout << "[+] Proccess found, waiting for bootup" << endl;
		cout << "[*] Injecting in 30 secounds \n";
		Sleep(30000);
		if (injectorMethod == 1) {
			if (DoesFileExist("DLL.dll")) {
				cout << "[*] INJECTION STARTED \n" << endl;
				if (LoadLibraryInject(proc_id, "CUSTOM.dll")) {
					cout << "Injecting" << endl;
					Sleep(2000);
				}
				else {
					cout << "Injection faild" << endl;
					Sleep(5000);
					ExitProcess(0);
				}
			}
			else {
				cout << "The DLL was not found, make sure you got internet connection and try again" << endl;
				system("pause");
				ExitProcess(0);
			}
		}
		else if (injectorMethod == 2) {
			if (DoesFileExist("DLL.dll")) {
				cout << "Injection started" << endl;
				if (LoadLibraryInject2(proc_id, "CUSTOM.dll")) {
					cout << "Injecting" << endl;
					Sleep(2000);
				}
				else {
					cout << "Injection faild" << endl;
					Sleep(5000);
					ExitProcess(0);
				}
			}
			else {
				cout << "The DLL was not found, make sure you got internet connection and try again" << endl;
				system("pause");
				ExitProcess(0);
			}
		}
		else {
			cout << "NO INJECTION MODE SELECTED!" << endl;
			system("pause");
			Sleep(5000);
			ExitProcess(0);
		}

	}

	cout << "[+] INJECTION SUCCESFULL";
	Sleep(3000);
}
class loginManager {
public:
	string userNameAttempt;
	string passWordAttempt;
	loginManager() {
		asscessGranted = false;
	}
	void login() {
		cout << "                                   \n";
		cout << "                                   \n";
		cout << "                                                $   ENTER YOUR USERNAME  $       \n";
		cout << "                                                >";
		cin >> userNameAttempt;
		if (userNameAttempt == username) {
			cout << "                                   \n";
			cout << "                                                $   ENTER YOUR PASSWORD  $       \n";
			cout << "                                                >";
			cin >> passWordAttempt;
			if (passWordAttempt == password) {
				cout << "LOGIN SUCCESFULL";
				return;
			}
			else {
				cout << "INVALID PASSWORD";
				Sleep(1500);
				system("CLS");
				login();
			}
		}
		else {
			cout << "INVALID USERNAME";
			system("CLS");
			login();
		}
	}
	string getUserName() {
		return userNameAttempt;
	}
private:
	string username = "beta";
	string password = "beta";
	bool asscessGranted;
} loginManagerObj;
void consoleTitle()
{
	while (true)
	{
		SetConsoleTitleA(random_string(20).c_str());
	}
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void menuSelector() {
	int selected = 0;    //Keeps track of which option is selected.
	int numChoices = 4; //The number of choices we have.
	bool selecting = true;//True if we are still waiting for the user to press enter.
	bool updated = false;//True if the selected value has just been updated.

	//Output options
	system("CLS");
	MainText();
	SetConsoleTextAttribute(hConsole, 4);
	cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
	cout << "\n";
	cout << "                                        F7: Load CSGO    \n";
	cout << "                                        F8: Load Custom .dll\n";
	cout << "                                        F9: Exit            \n";

	char c; //Store c outside of loop for efficiency.
	while (selecting) { //As long as we are selecting...
		switch ((c = _getch())) { //Check value of the last inputed character.
		case KEY_UP:
			if (selected > 0) { //Dont decrement if we are at the first option.
				--selected;
				updated = true;
			}
			break;
		case KEY_DOWN:
			if (selected < numChoices - 1) { //Dont increment if we are at the last option.
				++selected;
				updated = true;
			}
			break;
		case KEY_ENTER:
			//We are done selecting the option.
			selecting = false;
			break;
		default: break;
		}
		if (updated) { //Lets us know what the currently selected value is.
			std::cout << "Option " << (selected + 1) << " is selected.\n";
			system("CLS");

			switch (selected + 1) {
			case 1:
				MainText();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
				cout << "\n";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "                                                      [>]: CHEATS \n";
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      [>]: INJECTORS   \n";
				cout << "                                                      [>]: SPOOFERS   \n";
				cout << "\n";
				cout << "                                                      [X]: EXIT \n";
				break;
			case 2:
				MainText();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
				cout << "\n";
				
				
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      [>]: CHEATS    \n";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "                                                      [>]: INJECTORS     \n";
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      [>]: SPOOFERS   \n";
				cout << "                                                      \n";
				cout << "                                                      [X]: EXIT    \n";
				break;
			case 3:
				MainText();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
				cout << "\n";
				
				
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      [>]: CHEATS    \n";
				cout << "                                                      [>]: INJECTORS     \n";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "                                                      [>]: SPOOFERS   \n";
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      \n";
				cout << "                                                      [-]: EXIT    \n";
				break;
			case 4:
				MainText();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
				cout << "\n";


				SetConsoleTextAttribute(hConsole, 4);
				cout << "                                                      [>]: CHEATS    \n";
				cout << "                                                      [>]: INJECTORS     \n";
				cout << "                                                      [-]: SPOOFERS   \n";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "                                                      \n";
				cout << "                                                      [+]: EXIT    \n";
				break;
			}

			updated = false;
		}
	}
	//Lets us know what we ended up selecting.
	std::cout << "Selected " << (selected + 1) << '\n';
	if (selected + 1 == 1) {
		int selected = 0;    //Keeps track of which option is selected.
		int numChoices = 3; //The number of choices we have.
		bool selecting = true;//True if we are still waiting for the user to press enter.
		bool updated = false;//True if the selected value has just been updated.

		//Output options
		system("CLS");
		MainText();
		SetConsoleTextAttribute(hConsole, 4);
		cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
		cout << "\n";
		cout << "                                                      [-]: CS:GO CHEAT \n";
		cout << "                                                      [+]: CUSTOM DLL \n";
		cout << "\n";
		cout << "                                                      [<]: BACK \n";
		cout << "                                                      [X]: EXIT  \n";

		char c; //Store c outside of loop for efficiency.
		while (selecting) { //As long as we are selecting...
			switch ((c = _getch())) { //Check value of the last inputed character.
			case KEY_UP:
				if (selected > 0) { //Dont decrement if we are at the first option.
					--selected;
					updated = true;
				}
				break;
			case KEY_DOWN:
				if (selected < numChoices - 1) { //Dont increment if we are at the last option.
					++selected;
					updated = true;
				}
				break;
			case KEY_ENTER:
				//We are done selecting the option.
				selecting = false;
				break;
			default: break;
			}
			if (updated) { //Lets us know what the currently selected value is.
				std::cout << "Option " << (selected + 1) << " is selected.\n";
				system("CLS");

				switch (selected + 1) {
				case 1:
					MainText();
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [-]: CS:GO CHEAT \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: CUSTOM DLL \n";
					cout << "\n";
					cout << "                                                      [<]: BACK \n";
					cout << "                                                      [+]: EXIT \n";
					break;
				case 2:
					MainText();
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";
					cout << "                                                      [+]: CS:GO CHEAT \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [-]: CUSTOM DLL \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      \n";
					cout << "                                                      [<]: BACK \n";
					cout << "                                                      [+]: EXIT    \n";
					break;
				case 3:
					MainText();
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: CS:GO CHEAT \n";
					cout << "                                                      [+]: CUSTOM DLL \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      \n";
					cout << "                                                      [<]: BACK \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: EXIT    \n";
					break;
				case 4:
					MainText();
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: CS:GO CHEAT \n";
					cout << "                                                      [+]: CUSTOM DLL \n";
					cout << "                                                      \n";
					cout << "                                                      [<]: BACK \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [+]: EXIT    \n";
					break;
				}

				updated = false;
			}
		}
		//Lets us know what we ended up selecting.
		std::cout << "Selected " << (selected + 1) << '\n';
		if (selected + 1 == 1) {
			//CSGO
			injectCSGO();
		}
		else if (selected + 1 == 2) {
			//CUSTOM
			injectCustom();
		}
		else if (selected + 1 == 3) {
			//BACK
			menuSelector();
		}
		else if (selected + 1 == 4) {
			//EXIT
		}
	}
	if (selected + 1 == 2) {
		int selected = 0;    //Keeps track of which option is selected.
		int numChoices = 4; //The number of choices we have.
		bool selecting = true;//True if we are still waiting for the user to press enter.
		bool updated = false;//True if the selected value has just been updated.

		//Output options
		system("CLS");
		MainText();
		SetConsoleTextAttribute(hConsole, 4);
		cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
		cout << "\n";
		cout << "                                        F7: Load CSGO    \n";
		cout << "                                        F8: Load Custom .dll\n";
		cout << "                                        F9: Exit            \n";

		char c; //Store c outside of loop for efficiency.
		while (selecting) { //As long as we are selecting...
			switch ((c = _getch())) { //Check value of the last inputed character.
			case KEY_UP:
				if (selected > 0) { //Dont decrement if we are at the first option.
					--selected;
					updated = true;
				}
				break;
			case KEY_DOWN:
				if (selected < numChoices - 1) { //Dont increment if we are at the last option.
					++selected;
					updated = true;
				}
				break;
			case KEY_ENTER:
				//We are done selecting the option.
				selecting = false;
				break;
			default: break;
			}
			if (updated) { //Lets us know what the currently selected value is.
				std::cout << "Option " << (selected + 1) << " is selected.\n";
				system("CLS");

				switch (selected + 1) {
				case 1:
					MainText();
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";


					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [-]: 1. Method \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: 2. Method   \n";
					cout << "\n";
					cout << "                                                      [<]: BACK \n";
					cout << "                                                      [+]: EXIT \n";
					break;
				case 2:
					MainText();
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";


					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: 1. Method \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [-]: 2. Method   \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      \n";
					cout << "                                                      [<]: BACK \n";
					cout << "                                                      [+]: EXIT    \n";
					break;
				case 3:
					MainText();
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";


					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: 1. Method    \n";
					cout << "                                                      [+]: 2. Method    \n";
					cout << "                                                      \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [<]: BACK \n";
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: EXIT    \n";
					break;
				case 4:
					MainText();
					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                        X     USE ARROWS AND ENTER TO SELECT   X\n";
					cout << "\n";


					SetConsoleTextAttribute(hConsole, 4);
					cout << "                                                      [+]: 1. Method    \n";
					cout << "                                                      [+]: 2. Method    \n";
					cout << "                                                      \n";
					cout << "                                                      [<]: BACK \n";
					SetConsoleTextAttribute(hConsole, 2);
					cout << "                                                      [-]: EXIT    \n";

				}

				updated = false;
			}
		}
		//Lets us know what we ended up selecting.
		std::cout << "Selected " << (selected + 1) << '\n';
		if (selected + 1 == 1) {
			//1 Method
			injectorMethod = 1;
			menuSelector();
		}
		else if (selected + 1 == 2) {
			//2 Method
			injectorMethod = 2;
			menuSelector();
		}
		else if (selected + 1 == 3) {
			menuSelector();
		}
		else if (selected + 1 == 4) {

		}
	}
	if (selected + 1 == 3) {
		cout << "Dosent exist yet";
	}
}

int main()
{
	//thread Renamer(consoleTitle);

	crossScreen();
	system("taskkill / f / im steam.exe > nul 2 > &1");
	WelcomeScreen();

	/*
	bool connectionCheck = InternetCheckConnection(TEXT("https://www.google.com"), FLAG_ICC_FORCE_CONNECTION, 0);
	if (!connectionCheck) {
		std::cout << "wifi issue mate" << std::endl;
		Sleep(1500);
		std::exit(0);
	}*/

	loginManagerObj.login();

	crossScreen();
	loadinganimation();
	menuAnimation();
	menuSelector();


	//End Threads
	//Renamer.join();


return 0;
}