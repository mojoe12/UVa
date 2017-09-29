#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int m, n, t;
		cin >> m >> n >> t;
		cout << m << ' ' << n << ' ' << t << endl;
		vector<vector<char> > nums (m, vector<char> (n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> nums[i][j];
			}
		}
		for (int t1 = 0; t1 < t; t1++) {
			int r, c;
			cin >> r >> c;
			int bestdist = 0;
			for (int d = 1; ; d++) {
				if ((r < d) || (r+d >= m)) break;
				if ((c < d) || (c+d >= n)) break;
				bool ifok = true;
				for (int x = r-d; ifok && x <= r+d; x++) {
					for (int y = c-d; ifok && y <= c+d; y++) {
						ifok = nums[x][y] == nums[r][c];
					}
				}
				if (ifok) bestdist = d;
			}
			cout << 2*bestdist+1 << endl;
		}
	}
}