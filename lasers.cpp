#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int height, length;
		cin >> height;
		if (height == 0) break;
		cin >> length;
		int ncuts = 0;
		vector<int> incut (height+1);
		fill(incut.begin(), incut.end(), 0);
		for (int i = 0; i < length; i++) {
			int hcurr;
			cin >> hcurr;
			ncuts += count(incut.begin(), incut.begin() + hcurr + 1, 2);
			replace(incut.begin(), incut.begin() + hcurr + 1, 2, 1);
			fill(incut.begin() + hcurr + 1, incut.end(), 2);
		}
		ncuts += count(incut.begin(), incut.end(), 2);
		cout << ncuts << endl;
	}
}