#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			if (x == m || y == n) cout << "divisa" << endl;
			else if (x > m) {
				if (y > n) cout << "NE" << endl;
				else cout << "SE" << endl;
			}
			else {
				if (y > n) cout << "NO" << endl;
				else cout << "SO" << endl;
			}
		}
	}
}