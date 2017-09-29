#include <iostream>
#include <string>
using namespace std;

bool isDouble(string str) {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (((c - '0' < 0) || (c - '0' > 9)) && c != '.') return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	string str;
	while (cin >> str) {
		cout << isDouble(str) << endl;
	}
}