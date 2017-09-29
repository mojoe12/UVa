#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		string s;
		cin >> s;
		cout << "Case " << c << ": ";
		for (int i = 0; i < s.length();) {
			char c = s[i++];
			int numtimes = s[i++] - '0';
			
			int x = s[i] - '0';
			if (x >= 0 && x < 10) {
				numtimes = numtimes * 10 + x;
				i++;
			}
			x = s[i] - '0';
			if (x >= 0 && x < 10) {
				numtimes = numtimes * 10 + x;
				i++;
			}
			
			for (int j = 0; j < numtimes; j++) {
				cout << c;
			}
		}
		cout << endl;
	}
}