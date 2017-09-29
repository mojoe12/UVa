#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getPeriod (string s) {
	int l = s.length(), x = l/2;
	for (int i = 1; i <= x; i++) {
		if (l % i) continue;
		bool ifequal = true;
		for (int j = 0; ifequal && j < l; j++) {
			if (s[j] != s[j % i]) ifequal = false;
		}
		if (ifequal) return i;
	}
	return l;
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	for (int i = 0; i < k; i++) {
		cin >> s;
		if (i > 0) cout << endl;
		cout << getPeriod(s) << endl;
	}
}