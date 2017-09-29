#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k; 
	for (int ca = 1; ca <= k; ca++) {
		
		
		int r, c;
		cin >> r >> c;
		vector<string> mall (r);
		
		for (int i = 0; i < r; i++) {
			cin >> mall[i];
		}
		
		int minmoves = -1;
		for (int j = 0; j < c; j++) {
			//cout << j << endl;
			
			int nmoves = 0;
			bool ifpossible = true;
			for (int i = 0; ifpossible && i < r; i++) {
				//cout << 'i' << i<< endl;
				if (mall[i][j] == '1') {
					bool canmoveleft = false;
					int leftmoves = 0;
					for (int x = j-1; x >= 0; x--) {
						if (mall[i][x] == '0') {
							canmoveleft = true;
							leftmoves = abs(x - j);
							break;
						}
					}
					bool canmoveright = false;
					int rightmoves = 0;
					for (int x = j+1; x < c; x++) {
						if (mall[i][x] == '0') {
							canmoveright = true;
							rightmoves = abs(x - j);
							break;
						}
					}
					//cout << canmoveleft << ' ' << canmoveright << endl;
					
					if (canmoveright && canmoveleft) {
						nmoves += min(leftmoves, rightmoves);
					}
					else if (canmoveright) {
						nmoves += rightmoves;
					}
					else if (canmoveleft) {
						nmoves += leftmoves;
					}
					else {
						ifpossible = false;
					}
				}
			}
			if (ifpossible) {
				if (minmoves == -1) minmoves = nmoves;
				else minmoves = min(minmoves, nmoves);
			}
		}
		
		cout << "Case " << ca << ": ";
		cout << minmoves << endl;
	}




}


