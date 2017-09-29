#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

char translate (string s) {
	if (s == ".-") return 'A';
	if (s == "-...") return 'B';
	if (s == "-.-.") return 'C';
	if (s == "-..") return 'D';
	if (s == ".") return 'E';
	if (s == "..-.") return 'F';
	if (s == "--.") return 'G';
	if (s == "....") return 'H';
	if (s == "..") return 'I';
	if (s == ".---") return 'J';
	if (s == "-.-") return 'K';
	if (s == ".-..") return 'L';
	if (s == "--") return 'M';
	if (s == "-.") return 'N';
	if (s == "---") return 'O';
	if (s == ".--.") return 'P';
	if (s == "--.-") return 'Q';
	if (s == ".-.") return 'R';
	if (s == "...") return 'S';
	if (s == "-") return 'T';
	if (s == "..-") return 'U';
	if (s == "...-") return 'V';
	if (s == ".--") return 'W';
	if (s == "-..-") return 'X';
	if (s == "-.--") return 'Y';
	if (s == "--..") return 'Z';
	if (s == "-----") return '0';
	if (s == ".----") return '1';
	if (s == "..---") return '2';
	if (s == "...--") return '3';
	if (s == "....-") return '4';
	if (s == ".....") return '5';
	if (s == "-....") return '6';
	if (s == "--...") return '7';
	if (s == "---..") return '8';
	if (s == "----.") return '9';
	if (s == ".-.-.-") return '.';
	if (s == "--..--") return ',';
	if (s == "..--..") return '?';
	if (s == ".----.") return '\'';
	if (s == "-.-.--") return '!';
	if (s == "-..-.") return '/';
	if (s == "-.--.") return '(';
	if (s == "-.--.-") return ')';
	if (s == ".-...") return '&';
	if (s == "---...") return ':';
	if (s == "-.-.-.") return ';';
	if (s == "-...-") return '=';
	if (s == ".-.-.") return '+';
	if (s == "-....-") return '-';
	if (s == "..--.-") return '_';
	if (s == ".-..-.") return '\"';
	if (s == ".--.-.") return '@';
	return ' ';

}

int main() {
	
	// setup input
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	for (int c = 1; c <= k; c++) {
		getline(cin, s);
		string message = "", cword = "";
		for (int i = 0; i <= s.length(); i++) {
			if (s[i] == ' ' || i == s.length()) {
				message += translate(cword);
				cword = "";
			}
			else if (s[i] != '\n') cword += s[i];
		}
		if (c > 1) cout << endl;
		cout << "Message #" << c << endl;
		cout << message << endl;
	}
}