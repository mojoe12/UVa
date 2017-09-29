#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
bool ifelement(char c);
double getmass(char element, int nmoles);
int chartoint(char c);

int main(int argc, char *argv[]) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cout << fixed << setprecision(3);
		string mole; 
		cin >> mole;
		double mass = 0;
		int m = mole.length();
		for (int j = 0; j < m; j++) {
			if (j == mole.length()-1 || ifelement(mole[j+1])) {
				mass += getmass(mole[j], 1);}
			else {
				if (j == m-2 || ifelement(mole[j+2])) {
					mass += getmass(mole[j], (mole[j+1] - '0'));
					j++;}
				else {
					mass += getmass(mole[j], 10 * (mole[j+1] - '0') + (mole[j+2] - '0') );
					j += 2;
				}
			}
		}
		cout << mass << endl;
	}
}
bool ifelement(char c) {
	if (c == 'C' || c == 'O' || c == 'H' || c == 'N') return true;
	return false;
}

double getmass(char element, int nmoles) {
	switch(element) {
		case 'C': return nmoles * 12.01;
		case 'H': return nmoles * 1.008;
		case 'O': return nmoles * 16.00;
		case 'N': return nmoles * 14.01;
	}
	return 0;
}

int chartoint(char c) {
	return c - '0';
}

