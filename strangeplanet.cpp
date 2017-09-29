#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// function declarations
pair<int, int> getpos(long long n) {
	
	if (n == 1) return make_pair(0, 1);
	
	int row = floor(sqrt(n/2));
	// getrow
	
	int minN = 2 * row * row;
	int edge = 0;
	int x = row, y = 0;
	
	for (int i = minN; i < n; i++) {
		if (edge == 0) {
			x--;
			y--;
			if (x == 0) edge++;
		}
		else if (edge == 1) {
			x--;
			y++;
			if (y == 0) edge++;
		}
		else if (edge == 2) {
			y++;
			edge++;
		}
		else if (edge == 3) {
			x++;
			y++;
			if (x == 0) edge++;
		}
		else if (edge == 4) {
			x++;
			y--;
		}
	}
	
	return make_pair(x, y);
	
	
}


int main() {
	
	// setup input


	// loop through it, apply function


	// output answer
	
	int a, b;
	while (cin >> a >> b) {
		if (a < 0) break;
		
		pair<int, int> ac = getpos(a);
		pair<int, int> bc = getpos(b);
		
		//cout << ac.first << ' ' << ac.second << ' ';
		//cout << bc.first << ' ' << bc.second << endl;
		
		int distsq = (ac.first - bc.first) * (ac.first - bc.first);
		distsq += (ac.second - bc.second) * (ac.second - bc.second);
		
		double dist = sqrt(distsq);
		cout << fixed << setprecision(2) << dist << endl;
	}


}

// function definitions

