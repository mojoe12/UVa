#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		string ret = "";
		if (s == "1" || s == "4" || s == "78") ret = "+";
		else if (s[s.length()-1] == '5' && s[s.length()-2] == '3') ret = "-";
		else if (s[s.length()-1] == '4' && s[0] == '9') ret = "*";
		else if (s[0] == '1' && s[1] == '9' && s[2] == '0') ret = "?";
		cout << ret << endl;
	}
}