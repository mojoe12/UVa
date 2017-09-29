#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string input;
	for (getline(cin, input); input != ""; getline(cin, input)) {
		string output = "";
		for (int i = 0; i < input.length(); i++) {
			char c = input[i];
			if (c == ' ') output += c;
			else output += s[s.find(c)-1];
		}
		cout << output << endl;
	}
}