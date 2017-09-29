#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool allten (int a, int b) {
	vector<int> digs (10);
	for (int i = 0; i < 5; i++) {
		digs[a % 10] = 1;
		a /= 10;
		digs[b % 10] = 1;
		b/= 10;
	}
	return count(digs.begin(), digs.end(), 1) == 10;
}



int main(int argc, char *argv[]) {
	int n;
	bool ifspace = false;
	while (cin >> n) {
		if (!n) break;
		if (ifspace) cout << endl;
		else ifspace = true;
		 
		bool ifdone = false;
		for (int i = 1234; (n*i) <= 98765; i++) {
			if ( allten(i, n*i) ) {
				cout << n*i << " / ";
				if (i < 10000) cout << '0';
				cout << i << " = " << n << endl;
				ifdone = true;
			}
		}
		if (!ifdone) cout << "There are no solutions for " << n << ".\n";
	}
}