#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	while (s != "") {
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			char d = s[i] - 7;
			cout << d;
		}
		cout << endl;
		getline(cin, s);
	}
}