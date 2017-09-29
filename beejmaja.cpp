#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input
	int n;
	while (cin >> n) {
		
		int row = 0;
		int start = sqrt((n-1) / 3) - 1; // change
		for (int i = max(start, 0); ; i++) {
			if (3 * i * (i + 1) + 1 >= n) {
				row = i;
				break;
			}
		}
		
		int maxn = 3 * row * (row + 1) + 1;
		//cout << maxn << endl;
		
		int cx = row, cy = 0;
		int edge = 0, index = 0;
		for (int i = maxn; i > n; i--) {
			//cout << cx << ' ' << cy << endl;
			
			if (edge == 0) {
				cy--;
				if (cy == -row) edge++;
			}
			else if (edge == 1) {
				cx--;
				if (cx == 0) edge++;
			}
			else if (edge == 2) {
				cx--;
				cy++;
				if (cy == 0) edge++;
			}
			else if (edge == 3) {
				cy++;
				if (cy == row) edge++;
			}
			else if (edge == 4) {
				cx++;
				if (cx == 0) edge++;
			}
			else if (edge == 5) {
				cx++;
				cy--;
			}
 		}
		
		cout << cx << ' ' << cy << endl;
		
		
	}
	
	


	// loop through it, apply function


	// output answer


}

// function definitions

