#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int amp, freq;
		cin >> amp >> freq;
		for (int i = 0; i < freq; i++) {
			if (c > 0 || i > 0) cout << endl;
			for (int j = 1; j < amp; j++) {
				for (int k = 0; k < j; k++) cout << j;
				cout << endl;
			}
			for (int j = amp; j > 0; j--) {
				for (int k = 0; k < j; k++) cout << j;
				cout << endl;
			}
		}
	}
}