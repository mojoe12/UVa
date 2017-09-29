#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	// setup input
	int n, m;
	for (int c = 1; cin >> n; c++) {
		if (!n) break;
		cin >> m;
		
		vector<string> puzzle (n);
		for (int i = 0; i < n; i++) {
			cin >> puzzle[i];
		}
		
		vector< vector<int> > starts (n, vector<int> (m, 0));
		vector< vector<int> > which (n, vector<int> (m, 0));
		
		int count = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (puzzle[i][j] != '*' && (!i || !j || puzzle[i-1][j] == '*' || puzzle[i][j-1] == '*')) {
					starts[i][j] = count++;
					if (!i || puzzle[i-1][j] == '*')  {
						which[i][j] = 1 + 2 * (!j || puzzle[i][j-1] == '*');
					}
					else which[i][j] = 2;
				}
			}
		}
		
		if (c > 1) cout << endl;
		
		//for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << starts[i][j];
		
		cout << "puzzle #" << c << ":\n";
		cout << "Across\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (starts[i][j] && which[i][j] > 1) {
					cout.width(3);
					cout << right << starts[i][j];
					cout << '.';
					for (int index = j; index < m; index++) {
						if (puzzle[i][index] == '*') break;
						cout << puzzle[i][index];
					}
					cout << endl;
				}
			}
		}
		
		cout << "Down\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (starts[i][j] && which[i][j] % 2) {
					cout.width(3);
					cout << right << starts[i][j];
					cout << '.';
					for (int index = i; index < n; index++) {
						if (puzzle[index][j] == '*') break;
						cout << puzzle[index][j];
					}
					cout << endl;
				}
			}
		}
	}
}