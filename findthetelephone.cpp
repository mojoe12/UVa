#include <iostream>

using namespace std;

char decode (char c){
	switch (c){
		case 'A':
		case 'B':
		case 'C': return '2';
		case 'D':
		case 'E':
		case 'F': return '3';
		case 'G':
		case 'H':
		case 'I': return '4';
		case 'J':
		case 'K':
		case 'L': return '5';
		case 'M':
		case 'N':
		case 'O': return '6';
		case 'P':
		case 'Q':
		case 'R': 
		case 'S': return '7';
		case 'T':
		case 'U':
		case 'V': return '8';
		case 'W':
		case 'X':
		case 'Y': 
		case 'Z': return '9';
		default: return c;
	}
}

int main(int argc, char *argv[]) {
	string s;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			cout << decode(s[i]);
		}
		cout << endl;
	}
}