#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

	using namespace std;
	
	int x;
	
	void fn1(void);
	
	void SetStdinEcho(bool enable = true)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode );
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;
    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}
	void menu(){
		int o,wybor[2];
		cout << setw(42);
		cout << " " << "Choose your adventure" << endl;
		cout << setw(30);
		cout << " " << "Gra z wyborami oparta na ksiazkach przygodowych" << endl;
		cout << endl;
		cout << setw(55);
		cout << "1.Start" << endl;
		cout << endl;
		cout << setw(55);
		cout << "2.Wyjdz";
		cout << endl;
		SetStdinEcho(false);
		cin >> o;
		
		if(o==1){
			system("CLS");
		}
		if(o==2){
			exit(0);
		}
	};
	
	void historia1(){
	cout << "Twoja podroz rozpoczyna sie w tajemniczym lesie, przed soba widzisz 3 miejsca, gdzie sie udasz?"<<endl;
	cout << setw(56);
	cout << "1.W glab lasu"<<endl;
	cout << setw(62);
	cout << "2.Do tajemniczej jaskini"<<endl;
	cout << setw(60);
	cout << "3.Do odleglego miasta"<<endl;
	SetStdinEcho(false);
	cin >> x;
	if(x==1){
		cout << setw(61);
		cout << endl;
		cout << "Zmierzasz w glab lasu"<<endl;
	}
	else if(x==2){
		cout << setw(68);
		cout << endl;
		cout << "Zaglebiasz sie w mroczna jaskinie"<<endl;
	}
	else if(x==3){
		cout << setw(70);
		cout << endl;
		cout << "Idziesz dluga, kamienna droga do miasta"<<endl;
	}
	else{
		cout << setw(60);
		cout << endl;
		cout << "Nie ma takiej opcji"<<endl;
		exit(0);
	}
	atexit(fn1);
	}
	
	void wybor1(){
		if(x==1){
			cout << setw(85);
			cout << "Zmierzajac w glab lasu dotarles do wielkiej przepasci, "<<endl;
			cout << setw(87);
			cout << "po drugiej stronie widzisz tajemnicze ruiny, co chcesz zrobic?"<<endl;
			cin >> x;
		}
		if(x==2){
			cout << " "<<endl;
		}
		if(x==3){
			cout << setw(73);
			cout << "Udalo ci sie dojsc do miasta. "<<endl;
			cout << setw(92);
			cout << "Po przekroczeniu murow zaczepia cie tajemnicza postac w plaszczu, "<<endl;
			cout << setw(92);
			cout << "gestem pokazuje ci bys poszedl za nia w ciemna uliczke, co zrobisz?"<<endl;
			cout << setw(61);
			cout << endl;
			cout << "1.Zignoruj"<<endl;
			cout << setw(62);
			cout << "2.Idz za nia"<<endl;
			SetStdinEcho(false);
			cin >> x;
			if(x==1){
				cout << setw(86);
				cout << endl;
				cout << "Ignorujesz tajemnicza postac i idziesz dalej w glab miasta"<<endl;
			}
			else if(x==2){
				cout << setw(78);
				cout << endl;
				cout << "Postanawiasz podazyc za tajemnicza postacia"<<endl;
			}
			else{
				cout << setw(65);
				cout << endl;
				cout << "Nie ma takiej opcji"<<endl;
				exit(0);
			}	
			atexit(fn1);
		}
	}
	
	void wybor2(){
		if(x==3){
			cout << "dziala"<<endl;
		}
	}
	
void fn1(){
		#define KEY_RIGHT 77
	cout << setw(85);
	cout << "Nastepna strona";
	cout << endl;
	cout << setw(81);
	cout << "Wcisnij"<<endl;
	cout << setw(78);
	cout << "->";
	int c=1;
	while(1){
		c=0;
		switch((c=getch())){
			case KEY_RIGHT:
				system("CLS");
				wybor1();
				wybor2();
				break;
			default:
				break;
			}
		}
	}

int main() {
	menu();
	historia1();
	return 0;
}