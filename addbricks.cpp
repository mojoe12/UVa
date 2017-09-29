#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int x = 0; x < k; x++) {
		vector< vector<int> > books;
		for (int i = 9; i > 0; i--) {
			vector<int> addition (i);
			books.push_back(addition);
		}
		for (int i = 8; i> -1; i -= 2) {
			for (int j = 0; j < 9-i; j += 2) {
				cin >> books[i][j];
			}
		}
		bool cont = true;
		books[0][1] = (books[2][0] - books[0][0] - books[0][2]) / 2;
		books[0][3] = (books[2][2] - books[0][2] - books[0][4]) / 2;
		books[0][5] = (books[2][4] - books[0][4] - books[0][6]) / 2;
		books[0][7] = (books[2][6] - books[0][6] - books[0][8]) / 2;

		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < 9-i; j++) {
				int sum = books[i-1][j] + books[i-1][j+1];
				if (i%2 || j%2) books[i][j] = sum;
			}
		}
		for (int i = 8; i > -1; i--) {
			for (int j = 0; j < 9-i; j++) {
				if (j != 0) cout << " ";
				cout << books[i][j];
			}
			cout << endl;
		}
	}
}