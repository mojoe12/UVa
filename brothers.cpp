#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int bros, rows, cols, bats;
		cin >> bros >> rows >> cols >> bats;
		if (bros == 0) break;
		vector< vector<int> > land (rows, vector<int> (cols));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> land[i][j];
			}
		}
		for (int i = 0; i < bats; i++) {
			vector< vector<int> > newland = land;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					int bro = land[i][j], hated = (bro + 1) % bros;
					
					// check move left
					if (j != 0 && land[i][j-1] == hated) newland[i][j-1] = bro;
					if (j != cols-1 && land[i][j+1] == hated) newland[i][j+1] = bro;
					if (i != 0 && land[i-1][j] == hated) newland[i-1][j] = bro;
					if (i != rows-1 && land[i+1][j] == hated) newland[i+1][j] = bro;
				}
			}
			land = newland;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols-1; j++) {
				cout << land[i][j] << ' ';
			}
			cout << land[i][cols-1] << endl;
		}
	}
}