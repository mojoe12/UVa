#include <iostream>
#include <bitset>

using namespace std;
int main(int argc, char *argv[]) {
	for (int count = 1; true; count++) {
		int r, c, n;
		cin >> r >> c >> n;
		if (r == 0 && c == 0 && n == 0) break;
		bitset<10000> rows, cols;
		rows.set(); // sets all values to 1
		cols.set(); // .reset() to 0
		
		for (int x = 0; x < n; x++) {
			int row, col;
			cin >> row >> col;
			rows[row] = false;
			cols[col] = false;
		}
		int row, col;
		cin >> row >> col;
		bool found = (rows[row] && cols[col]);
		if (row < r-1) found = found || (rows[row+1] && cols[col]);
		if (col < c-1) found = found || (rows[row] && cols[col+1]);
		if (row > 0) found = found || (rows[row-1] && cols[col]);
		if (col > 0) found = found || (rows[row] && cols[col-1]);
		if (found) cout << "Case " << count << ": Escaped again! More 2D grid problems!\n";
		else cout << "Case " << count << ": Party time! Let's find a restaurant!\n";
	}
}