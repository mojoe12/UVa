#include <iostream>

using namespace std;

char decode (char c) {
	switch (c) {
		case 'd': return 'a';
		case 'f': return 's';
		case 'g': return 'd';
		case 'h': return 'f';
		case 'j': return 'g';
		case 'k': return 'h';
		case 'l': return 'j';
		case ';': return 'k';
		case '\'': return 'l';
		case 'e': return 'q';
		case 'r': return 'w';
		case 't': return 'e';
		case 'y': return 'r';
		case 'u': return 't';
		case 'i': return 'y';
		case 'o': return 'u';
		case 'p': return 'i';
		case '[': return 'o';
		case ']': return 'p';
		case '\\': return '[';
		case 'c': return 'z';
		case 'v': return 'x';
		case 'b': return 'c';
		case 'n': return 'v';
		case 'm': return 'b';
		case ',': return 'n';
		case '.': return 'm';
		case '/': return ',';
		case '2': return '`';
		case '3': return '1';
		case '4': return '2';
		case '5': return '3';
		case '6': return '4';
		case '7': return '5';
		case '8': return '6';
		case '9': return '7';
		case '0': return '8';
		case '-': return '9';
		case '=': return '0';
		default: return ' ';
	}
}


int main() {
	string s;
	for (getline(cin, s); s != ""; getline(cin, s))
	{
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c - 'A' > 0 && c - 'Z' <= 0) c += 32;
			cout << decode(c);
		}
		cout << endl;
	}
}