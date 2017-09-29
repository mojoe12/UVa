#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	string input;
	while (cin >> input) {
		int prevo = 0;
		for (int i = 0; i < input.length(); i++) {
			char c = input[i];
			int o = 0;
			if (c == 'B' || c == 'F' || c == 'P' || c == 'V') o = 1;
			else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') o = 2;
			else if (c == 'D' || c == 'T') o = 3;
			else if (c == 'L') o = 4;
			else if (c == 'M' || c == 'N') o = 5;
			else if (c == 'R') o = 6;
			else {
				prevo = 0;
				continue;
			}
			if (prevo == o) continue;
			cout << o;
			prevo = o;
		}
		cout << endl;
	}
}