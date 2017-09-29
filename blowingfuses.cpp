#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
int main(int argc, char *argv[]) {
	for (int j = 1; true; j++) {
		int nmach, nops, cap;
		cin >> nmach >> nops >> cap;
		if (nmach == 0 && nops == 0 && cap == 0) break;
		vector<int> cons (nmach);
		for (int i = 0; i < nmach; i++) cin >> cons[i];
		int maxcon = 0, con = 0;
		bitset<20> ifon;
		ifon.reset();
		for (int i = 0; i < nops; i++) {
			int m;
			cin >> m;
			m--;
			ifon[m] = !ifon[m];
			con += cons[m] * 2 * (ifon[m] - 0.5);
			if (con > maxcon) maxcon = con;
		}
		cout << "Sequence " << j << endl;
		if (maxcon > cap) cout << "Fuse was blown." << endl << endl;
		else cout << "Fuse was not blown." << endl << "Maximal power consumption was " << maxcon << " amperes." << endl << endl;
	}
}

