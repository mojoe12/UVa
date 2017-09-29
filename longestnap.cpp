#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	for (int c = 1; cin >> n; c++) {
		bitset<480> inmeeting;
		for (int i = 0; i <= n; i++) {
			string start, end, activity;
			if (i < n) {
				cin >> start >> end;
				getline(cin, activity);
			}
			else {
				start = "18:00";
				end = "18:00";
			}
			int starti = 60 * (start[1] - '0') + 10 * (start[3] - '0') + (start[4] - '0');
			int endi = 60 * (end[1] - '0') + 10 * (end[3] - '0') + (end[4] - '0');
			for (int j = starti; j < endi; j++) {
				inmeeting[j] = true;
			}
		}
		int maxmins = 0;
		string beststart = "10:00";
		for (int i = 0; i < 480; i++) {
			int start = i, nmins = 0;
			while (!inmeeting[i] && i < 480) {
				i++;
				nmins++;
			}
			if (nmins > maxmins) {
				maxmins = nmins;
				beststart = '1' + to_string(start / 60) + ':';
				if (start % 60 < 10) beststart += '0';
				beststart += to_string(start % 60);
			}
		}
		cout << "Day #" << c << ": the longest nap starts at ";
		cout << beststart << " and will last for ";
		if (maxmins / 60) cout << maxmins / 60 << " hours and ";
		cout << maxmins % 60 << " minutes.\n";
	}
}