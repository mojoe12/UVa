#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	while (true) {
		int dur, nrecs;
		float down, amount;
		cin >> dur >> down >> amount >> nrecs;
		if (dur < 0) break;
		vector<float> deps (dur+1);
		fill(deps.begin(), deps.end(), 0);
		float prevdep = 0;
		int cmonth = 0;
		for (int i = 0; i <= nrecs; i++) {
			int month = dur;
			float dep = prevdep;
			if (i != nrecs) cin >> month >> dep;
			for (; cmonth < month && cmonth < dur; cmonth++) {
				deps[cmonth] = 1-prevdep;
			}
			if (cmonth <= dur) deps[cmonth] = 1-dep;
			prevdep = dep;
			cmonth++;
		}
		if (dur == 0) {
			cout << "0 months" << endl;
			continue;
		}
		float lefttopay = amount;
		float value = (amount + down) * deps[0];
		float payment = lefttopay;
		if (dur != 0) payment /= dur;
		
		if (lefttopay < value) {
			cout << "0 months" << endl;
			continue;
		}
		int m = 1;
		for (; m <= dur; m++) {
			value *= deps[m];
			lefttopay -= payment;
			if (lefttopay < value) break;
		}
		if (m == 1) cout << m << " month" << endl;
		else cout << m << " months" << endl;
	}
	return 0;
}
