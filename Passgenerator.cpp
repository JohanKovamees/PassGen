#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>

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

void printA(const std::array<int, 16>& arr) {
	for (int n = 0; n < arr.size(); n++) {
		std::cout << (char)arr[n];
	}
}


int main() {	
	
	srand(time(NULL));
//	cout << "Enter password length: ";
//	cin >> length;

	std::array <int, 16> arr;



	for (int i = 0; i < arr.size(); i = i + 1) {
		arr[i] = randomSelAll();
	}

	std::cout << "Your Generated Password: ";

	printA(arr);




	return 0;
}

