#include <iostream>
#include <vector>
using namespace std;

void correct (int &a, int &b) {
	if (a > b) {
		int temp = b;
		b = a;
		a = temp;
	}
}

int main(int argc, char *argv[]) {
	while (true) {
		int l, h, n;
		cin >> l >> h >> n;
		if (l == 0) break;
		vector< vector<bool> > rect (l, vector<bool> (h));
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			correct(x1, x2);
			correct(y1, y2);

			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					rect[x-1][y-1] = true;
				}
			}
		}
		int numtrue = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < h; j++) {
				if (!rect[i][j]) numtrue++;
			}
		}
		if (numtrue == 0) cout << "There is no empty spots.\n";
		else if (numtrue == 1) cout << "There is one empty spot.\n";
		else cout << "There are " << numtrue << " empty spots.\n";
	}
}
