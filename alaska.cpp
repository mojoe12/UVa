#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> loc (n);
		for (int i = 0; i < n; i++) {
			cin >> loc[i];
		}
		sort(loc.begin(), loc.end());
		int prev = loc[0];
		bool ifpos = true;
		for (int i = 1; i < n && ifpos; i++) {
			if (loc[i] - prev > 200) ifpos = false;
			prev = loc[i];
		}
		if (1422 - prev > 100) ifpos = false;
		if (!ifpos) cout << "IM";
		cout << "POSSIBLE\n";
	}
}