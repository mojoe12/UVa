#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int c = 1; c <= k; c++) {
		getline(cin, s);
		string code = "";
		while (s != "") {
			int i = 0;
			string word = "";
			bool ifword = true;
			for (int j = 0; j < s.length(); j++) {
				if (ifword && word.length() == i && s[j] != ' ') {
					code += s[j];
					i++;
					ifword = false;
				}
				if (s[j] == ' ') {
					word = "";
					ifword = true;
				}
				else word += s[j];
			}
			code += '\n';
			getline(cin, s);
		}
		
		if (c>1) cout << endl;
		cout << "Case #" << c << ":\n" << code;
	}
	
}