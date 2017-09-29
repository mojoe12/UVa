#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int ndays;
		cin >> ndays;
		int np;
		cin >> np;
		vector<int> hartals (np);
		for (int i = 0; i < np; i++) {
			cin >> hartals[i];
		}
		vector<int> hmeter (np);
		fill (hmeter.begin(), hmeter.end(), 0);
		int nhartals = 0;
		for (int i = 0; i < ndays; i++) {
			bool ifhartal = false;
			for (int p = 0; p < np; p++) {
				hmeter[p]++;
				if (hmeter[p] == hartals[p]) {
					ifhartal = true;
					hmeter[p] = 0;
				}
			}
			if (i % 7 > 4) continue;
			if (ifhartal) nhartals++;
		}
		cout << nhartals << endl;
	}
}