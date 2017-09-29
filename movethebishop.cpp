#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2 && y1 == y2) cout << 0 << endl;
			else if (abs(x2-x1) == abs(y2-y1)) cout << 1 << endl;
			else if ((x1+y1) % 2 != (x2+y2) % 2) cout << "no move\n";
			else cout << 2 << endl;
		}
	}
}