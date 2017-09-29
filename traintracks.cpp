#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string pset;
	getline(cin, pset);
	for (int c = 0; c < k; c++) {
		getline(cin, pset);
		int mm = 0, ff = 0;
		for (int i = 0; i < pset.length(); i += 3) {
			if (pset[i] == 'M' && pset[i+1] == 'M') mm++;
			else if (pset[i] == 'F' && pset[i+1] == 'F') ff++;
		}
		if (mm != ff || pset.length() <= 3) cout << "NO ";
		cout << "LOOP" << endl;
	}
}