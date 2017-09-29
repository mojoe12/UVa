#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string number = "";
		for (int i = 0; i < 4; i++) {
			string s;
			cin >> s;
			number += s;
		}
		int sum = 0;
		for (int i = 0; i < 16; i++) {
			int cnum = number[i] - '0';
			if (i % 2) sum += cnum;
			else sum += (cnum * 2) / 10 + (cnum * 2) % 10;
		}
		if (sum % 10) cout << "Invalid\n";
		else cout << "Valid\n";
	}
}