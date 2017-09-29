#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	bool ifspace = false;
	for (int c = 0; c < k; c++) {

		int n, w;
		cin >> n >> w;
		vector<bool> possible (n);
		fill(possible.begin(), possible.end(), true);
		
		for (int i = 0; i < w; i++) {
			int p;
			cin >> p;
			vector<int> weighed (2 * p);
			for (int j = 0; j < 2 * p; j++) cin >> weighed[j];
			string rel;
			cin >> rel;
			for (int j = 0; j < n; j++) {
				if (count(weighed.begin(), weighed.end(), j+1) == 1) {
					if (rel == "=") possible[j] = false;
				}
				else if (rel != "=") possible[j] = false;
			}
		}

		if (ifspace) cout << endl;
		else ifspace = true;
		if (count(possible.begin(), possible.end(), true) != 1) cout << "0\n";
		else cout << 1 + find(possible.begin(), possible.end(), true) - possible.begin() << endl;
	}
}