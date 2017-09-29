#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void operation(int, vector< vector<int> >&, int);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector< vector<int> > matrix (n, vector<int> (n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> matrix[i][j];
		}
		for (int r = 0; r < n/2 + n%2; r++) {
			int t;
			cin >> t;
			for (int o = 0; o < t; o++) {
				int op;
				cin >> op;
				operation(op, matrix, r);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) cout << matrix[i][j] << ' ';
			cout << matrix[i][n-1] << endl;
		}
	}
}

void operation(int op, vector< vector<int> >& matrix, int ring) 
{
	int n = matrix.size();
	vector< vector<int> > newmat = matrix;
	int center = n/2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int xdist = (i < center) ? i : (n - i - 1);
			int ydist = (j < center) ? j : (n - j - 1);
			bool ifok = xdist == ring && ydist >= ring;
			ifok = ifok || (ydist == ring && xdist >= ring);
			if (ifok) {
				int newi = i;
				int newj = j;
				if (op == 1 || op == 4) newi = n - i - 1;
				if (op == 2 || op == 4) newj = n - j - 1;
				if (op > 2) swap(newi, newj);
				newmat[newi][newj] = matrix[i][j];
			}
		}
	}
	matrix = newmat;
}