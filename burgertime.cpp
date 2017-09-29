#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int l;
		cin >> l;
		if (l == 0) break;
		string locs;
		cin >> locs;
		int mindist = 2000001;
		int closestR = -1, closestD = -1;
		for (int i = 0; i < l; i++) {
			char c = locs[i];
			if (c == '.') continue;
			else if (c == 'Z') {
				mindist = 0;
			}
			else if (c == 'R') {
				closestR = i;
				if (closestD == -1 || closestR == -1) continue;
				if (i - closestD < mindist) mindist = i - closestD;
			}
			else if (c == 'D') {
				closestD = i;
				if (closestD == -1 || closestR == -1) continue;
				if (i - closestR < mindist) mindist = i - closestR;
			}
		}
		cout << mindist << endl;
	}
}