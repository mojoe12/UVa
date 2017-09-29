#include <iostream>
using namespace std;

bool ifpal(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i-1]) return false;
	}
	return true;
}

bool ifms(string s) {
	int l = s.length();
	for (int i = 0; i < l/2 + l%2; i++) {
		char c = s[i];
		char rev = ' ';
		switch (c) {
			case 'A': {rev = 'A'; break;}
			case 'E': {rev = '3'; break;} 
			case '3': {rev = 'E'; break;} 
			case 'H': {rev = 'H'; break;} 
			case 'I': {rev = 'I'; break;} 
			case 'J': {rev = 'L'; break;} 
			case 'L': {rev = 'J'; break;} 
			case 'M': {rev = 'M'; break;} 
			case 'O': {rev = 'O'; break;} 
			case 'T': {rev = 'T'; break;} 
			case 'U': {rev = 'U'; break;} 
			case 'V': {rev = 'V'; break;} 
			case 'W': {rev = 'W'; break;} 
			case 'X': {rev = 'X'; break;} 
			case 'Y': {rev = 'Y'; break;} 
			case 'Z': {rev = '5'; break;} 
			case '5': {rev = 'Z'; break;} 
			case '1': {rev = '1'; break;} 
			case '2': {rev = 'S'; break;} 
			case 'S': {rev = '2'; break;} 
			case '8': {rev = '8'; break;} 
			default: rev = ':';
		}
		if (s[l-i-1] != rev) return 0;
	}
	return true;
}

int main(int argc, char *argv[]) {
	string s;
	while (cin >> s) {
		cout << s << " -- is ";
		bool p = ifpal(s), m = ifms(s);
		if (p && m) cout << "a mirrored palindrome.";
		else if (p && !m) cout << "a regular palindrome.";
		else if (!p && m) cout << "a mirrored string.";
		else cout << "not a palindrome.";
		cout << endl << endl;
	}
}

