#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input

	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		double tax = 0;
		if (n > 180000) {
			tax += .1 * min(300000, n - 180000);
		}
		if (n > 480000) {
			tax += .15 * min(400000, n - 480000);
		}
		if (n > 880000) {
			tax += .2 * min(300000, n - 880000);
		}
		if (n > 1180000) tax += .25 * (n - 1180000);
		
		//cout << tax << endl;
		int taxi = ceil(tax);
		if (taxi < 2000 && n > 180000) taxi = 2000;
		cout << "Case " << c << ": " << taxi << endl;
	}

	// loop through it, apply function


	// output answer


}

// function definitions

