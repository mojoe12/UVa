#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		
		int bestscore = 0;
		int bestoff = 0, beston = 0;
		int currentscore = 0, currentoff = 1;
		for (int stop = 1; stop <= n; stop++) {
			
			bool longer = currentscore == bestscore && 
				(stop - currentoff > beston - bestoff);
			if (currentscore > bestscore || longer) {
				bestscore = currentscore;
				bestoff = currentoff;
				beston = stop; // get on at this stop
			}
			if (stop == n) break;
			
			int x;
			cin >> x;
			if (currentscore + x < 0) {
				currentscore = 0;
				currentoff = stop + 1;
			}
			else currentscore += x;
		}
		
		if (!bestscore) cout << "Route " << c << " has no nice parts\n";
		else {
			cout << "The nicest part of route " << c;
			cout << " is between stops " << bestoff;
			cout << " and " << beston << endl;
		}
	}



}


