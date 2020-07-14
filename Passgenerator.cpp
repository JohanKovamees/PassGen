#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>




using namespace std;

void MainMenu();

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
	
	std::cout << "\n\n\n\tYour Generated Password: \n\n";
	for (int n = 0; n < vec.size(); n++) {
		std::cout << (char)vec[n];
	}
	std::cout << "\n";
}

vector<char> PrintAr(const vector<int>& vec) { //Returns the vector as a string 
	vector<char> tmp;
	for (int i = 0; i < vec.size(); i++) {
		tmp[i] = (char)vec[i];
	}
	return tmp;
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

void writeTo() {
	string filename;
	string username;
	string location;
	int len;
	int amount;
	string s;

	cout << "Enter the amount of passwords/user combinations: ";
	cin >> amount;
	cout << "Enter filename: ";
	cin >> filename;
	
	ofstream pfile;
	pfile.open(filename);

	for (int n = 0; n < amount; n++) {
		
		cout << "Enter location (what site the username/pass is used on): ";
		cin >> location;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter length of password: ";
		cin >> len;
		vector<int> a = createP(len);

		pfile << "\n\nLocation: " << location;
		pfile << "\nUsername: " << username << endl;
		for (int n = 0; n < a.size(); n++) {
			pfile << (char)a[n];
		}
	}
	pfile.close();



}

void writeToX() {
	string filename;
	string username;
	string location;
	int len;
	int amount;
	string s;
	

	cout << "Enter the amount of passwords/user combinations: ";
	cin >> amount;
	cout << "Enter filename: ";
	cin >> filename;

	std::ofstream pfile;
	pfile.open(filename, std::ios_base::app);

	for (int n = 0; n < amount; n++) {

		cout << "Enter location (what site the username/pass is used on): ";
		cin >> location;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter length of password: ";
		cin >> len;
		vector<int> a = createP(len);

		pfile << "\n\nLocation: " << location;
		pfile << "\nUsername: " << username << endl;
		for (int n = 0; n < a.size(); n++) {
			pfile << (char)a[n];
		}
	}
	pfile.close();
	



}

void SimplePresets() {
	int smSP = 0;
	std::string cl(50, '\n');
	do {
		cout << "\n\t   **************\n";
		cout << "\t   Simple Presets";
		cout << "\n\t   **************\n";
		cout << "\tOptions";
		cout << "\n\n\t1. Length: 8";
		cout << "\n\n\t2. Length: 16";
		cout << "\n\n\t3. Length: 64";
		cout << "\n\n\t4. Length: 128";
		cout << "\n\n\t5. Length: 1048";
		cout << "\n\n\t6. Back";
		cout << "\n\n\tSelect Option (1-6) ";
		
		cin >> smSP;
		
		switch (smSP)
		{
		case 1:
			std::cout << cl;
			printA(createP(8));
			break;
		case 2:
			std::cout << cl;
			printA(createP(16));
			break;
		case 3:
			std::cout << cl;
			printA(createP(64));
			break;
		case 4:
			std::cout << cl;
			printA(createP(128));
			break;
		case 5:
			std::cout << cl;
			printA(createP(1048));
			break;
		case 6:
			std::cout << cl;
			MainMenu();
		default:
			cout << "\a";
		}
		
	} while (smSP != 6);
}

void txtGen() {
	string filename;
	string location;
	string username;
	int amount;
	int len;
	
	
	
	int tg = 0;
	std::string cl(50, '\n');
	do {
		cout << "\n\t   *********************************\n";
		cout << "\t   Generate Passwords to a text file";
		cout << "\n\t   *********************************\n";
		cout << "\tOptions";
		cout << "\n\n\t1. Generate passwords with added titles";
		cout << "\n\n\t2. Generate passwords with added titles to existing file";
		cout << "\n\n\t3. Back";
		cout << "\n\n\tSelect Option (1-3) ";
		
		cin >> tg;

		switch (tg)
		{
		case 1:
			std::cout << cl;
			
			writeTo();
			
			break;
		case 2:
			std::cout << cl;
			writeToX();
			break;
		case 3:
			std::cout << cl;
			MainMenu();
		default:
			cout << "\a";
		}

	} while (tg != 3);
}


void MainMenu() {
	std::string cl(50, '\n');

	int mm = 0;
	do
	{	
		
		cout << "\n\t   *********\n";
		cout << "\t   Main Menu \t\t Created by Johan Kovamees";
		cout << "\n\t   *********\n";
		cout << "\tOptions";
		cout << "\n\n\t1. Simple Presets";
		cout << "\n\n\t2. Generate passwords to a textfile";
		cout << "\n\n\t3. Custom Length";
		cout << "\n\n\t4. Exit";
		cout << "\n\n\tSelect Option (1-4) ";
		
		cin >> mm;
		switch (mm)
		{
		case 1:
			std::cout << cl;
			SimplePresets();
			break;
		case 2:
			std::cout << cl;
			txtGen();
			break;
		case 3:
			std::cout << cl;
			printA(createPc());
			break;
		case 4:
			std::cout << cl;
			exit(0);
		default:
			cout << "\a";
		}
	} while (mm != '4');
}

int main() {	

	MainMenu();

	return 0;
}

