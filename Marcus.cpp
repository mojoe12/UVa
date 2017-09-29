#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
void findpath(vector<string> path, int ci, int cj, int x);

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int m, n;
		cin >> m >> n;
		vector<string> path (m);
		for (int i = 0; i < m; i++) cin >> path[i];
		int cj = 0;
		for (int j = 0; j < n; j++) {
			if (path[m-1][j] == '@') {
				cj = j;
				break;
			}
		}
		findpath(path, m-1, cj, 0);		
	}
}

void findpath(vector<string> path, int ci, int cj, int x) {
	string s = "IEHOVA#";
	
	if (ci > 0 && path[ci-1][cj] == s[x]) {
		cout << "forth";
		ci--;
	}
	else if (cj > 0 && path[ci][cj-1] == s[x]) {
		cout << "left";
		cj--;
	}
	else if (cj < path[ci].length()-1 && path[ci][cj+1] == s[x]) {
		cout << "right";
		cj++;
	}
	
	if (s[x] == '#') cout << endl;
	else {
		cout << ' ';
		findpath(path, ci, cj, x+1);
	}
}
