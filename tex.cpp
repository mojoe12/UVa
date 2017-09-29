#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	bool iffirst = true;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "") break;
		string retval = "";
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c != '"') {
				retval += c;
				continue;
			}
			if (iffirst) {
				iffirst = false;
				retval += "``";
			}
			else {
				iffirst = true;
				retval += "''";
			}
		}
		cout << retval << endl;
	}
}