#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <process.h>



using namespace std;


int randomSelAll() { //Generates a random Char
	int r = 33;
	r = 33 + rand() % 89;
	return r;
}

int randomSelCap() { //Generates a random capital letter
	int r = 33;
	r = 65 + rand() % 25;
	return r;
}

int randomSelSmall() { //Generates a random non-capital letter
	int r = 33;
	r = 97 + rand() % 25;
	return r;
}

int randomSelDig() { //Generates a random digit
	int r = 33;
	r = 48 + rand() % 10;
	return r;
}

int randomSelSym() { //Generates a random symbol
	int r = 33;
	r = 33 + rand() % 15;
	return r;
}

void printA(const vector<int>& vec) { //Prints the Vector
	
	std::cout << "\n\n\n\tYour Generated Password: \n\n\t";
	for (int n = 0; n < vec.size(); n++) {
		std::cout << (char)vec[n];
	}
	std::cout << "\n";
}

vector<int> createPc() {
	int length;
	cout << "\n\tEnter password length: \n";
	cin >> length;
	vector<int> vec;
	vec.resize(length);
	srand(time(NULL));

	for (int i = 0; i < vec.size(); i = i + 1) {
		vec[i] = randomSelAll();
	}

	return vec;
}

vector<int> createP(int length) {
	vector<int> vec;
	vec.resize(length);
	srand(time(NULL));

	for (int i = 0; i < vec.size(); i = i + 1) {
		vec[i] = randomSelAll();
	}

	return vec;
}

int main() {	

	int s = 0;
	do
	{
		
		cout << "\n\n\n\t Password Options";
		cout << "\n\n\t01. Length: 64";
		cout << "\n\n\t02. Length: 128";
		cout << "\n\n\t03. Length: 512";
		cout << "\n\n\t04. Length: Custom";
		cout << "\n\n\t05. Exit";
		cout << "\n\n\tSelect Option (1-5) ";
		_getch();
		cin >> s;
		switch (s)
		{
		case 1:
			printA(createP(64));
			break;
		case 2:
			printA(createP(128));
			break;
		case 3:
			printA(createP(512));
			break;
		case 4:
			printA(createPc());
			break;
		case 5:
			exit(0);
		default:
			cout << "\a";
		}
	} while (s != '5');




	return 0;
}

