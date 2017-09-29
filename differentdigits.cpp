#include <iostream>

using namespace std;

// this is dank sorry

int main() {
	
	int n, m;
	while (cin >> n >> m) {
		int totalnum = 0;
		for (int i = n; i <= m; i++) {
			int dig1 = i / 1000, dig2 = i % 1000 / 100;
			int dig3 = i % 100 / 10, dig4 = i % 10;
			bool ifok = true;
			if (i >= 1000) ifok = ifok && (dig1 != dig2) && (dig1 != dig3) && (dig1 != dig4);
			if (i >= 100) ifok = ifok && (dig2 != dig3) && (dig2 != dig4);
			if (i >= 10) ifok = ifok && (dig3 != dig4);
			if (ifok) totalnum++;
		}
		cout << totalnum << endl;
	}
}