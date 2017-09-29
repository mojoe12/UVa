#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	bool putline = false;
	for (int c = 0; c < k; c++) {
		int ncols;
		cin >> ncols;
		bool ifpossible = true;
		int height = -1;
		for (int i = 0; i < ncols; i++) {
			int y2, y1;
			cin >> y2 >> y1;
			int h = y2 - y1;
			if (height == -1) height = h;
			else if (height != h) ifpossible = false;
		}
		if (putline) cout << endl;
		else putline = true;
		if (ifpossible) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}