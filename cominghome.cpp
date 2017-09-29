#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int nbus;
		cin >> nbus;
		string cts;
		cin >> cts;
		int ch = 10 * (cts[0] - '0') + cts[1] - '0';
		int cm = 10 * (cts[3] - '0') + cts[4] - '0';
		int mintime = 100000;
		for (int i = 0; i < nbus; i++) {
			string gts;
			cin >> gts;
			int gh = 10 * (gts[0] - '0') + gts[1] - '0';
			int gm = 10 * (gts[3] - '0') + gts[4] - '0';
			int extra;
			cin >> extra;
			int time = extra + (gh - ch) * 60 + (gm - cm);
			if (ch > gh || (ch == gh && cm > gm)) time += 1440;
			if (time < mintime) mintime = time;
		}
		if (mintime == 100000) mintime = 2439;
		cout << "Case " << c << ": " << mintime << endl;
	}
}