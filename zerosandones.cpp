#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1; true; c++) {
		string bitstring;
		getline(cin, bitstring);
		if (bitstring == "") break;
		cout << "Case " << c << ":" << endl;
		int numqs;
		cin >> numqs;
		for (int i = 0; i < numqs; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			char c = ' ';
			bool ifsame = true;
			for (int p = a; p <= b && ifsame; p++) {
				if (c == ' ') c = bitstring[p];
				else if (c != bitstring[p]) ifsame = false;
			}
			if (ifsame) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		getline(cin, bitstring);
	}
}