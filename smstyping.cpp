#include <iostream>
using namespace std;
int getnum(char c);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin,s);
	for (int c = 1; c <= k; c++) {
		getline(cin, s);
		int np = 0;
		for (int i = 0; i < s.length(); i++) {
			np += getnum(s[i]);
		}
		cout << "Case #" << c << ": " << np << endl;
	}
}

int getnum(char c) {
	switch (c) {
		case 'a': return 1;
		case 'b': return 2;
		case 'c': return 3;
		case 'd': return 1;
		case 'e': return 2;
		case 'f': return 3;
		case 'g': return 1;
		case 'h': return 2;
		case 'i': return 3;
		case 'j': return 1;
		case 'k': return 2;
		case 'l': return 3;
		case 'm': return 1;
		case 'n': return 2;
		case 'o': return 3;
		case 'p': return 1;
		case 'q': return 2;
		case 'r': return 3;
		case 's': return 4;
		case 't': return 1;
		case 'u': return 2;
		case 'v': return 3;
		case 'w': return 1;
		case 'x': return 2;
		case 'y': return 3;
		case 'z': return 4;
		default:  return 1;
	}
	return 0;
}