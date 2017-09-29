#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool nolose (vector<int>& x) {
	string s1 = "012", s2 = "012";
	do {
		do {
			int wincount = 0;
			for (int i = 0; i < 3; i++) {
				if (x[s1[i] - '0'] > x[3 + (s2[i] - '0') ]) wincount--;
				else wincount++;
			}
			if (wincount < 1) return false;
		} while (next_permutation(s2.begin(), s2.end()));
	} while (next_permutation(s1.begin(), s1.end()));
	return true;
}

int main(int argc, char *argv[]) {
	while (1) {
		
		vector<int> x (6);
		for (int i = 0; i < 5; i++) cin >> x[i];
		if (x[0] == 0) break;
		
		x[5] = 1;
		for (; x[5] < 53; x[5]++) {
			if ( find(x.begin(), x.begin()+5, x[5]) != x.begin()+5 ) continue;
			if ( nolose(x) ) break;
		}
		
		if (x[5] == 53) x[5] = -1;
		cout << x[5] << endl;
	}
}