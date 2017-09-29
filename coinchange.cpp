#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 

// this code works for pretty much half of the coin change problems
// for "dollars", divide by 5


using namespace std;

long long nways (int type, int value, const int* coins, vector< vector<long long> >& precomputed) {
	if (value == 0) return 1;
	if (value < 0 || type >= 21) return 0;
	
	long long& arrval = precomputed[type][value-1];
	if (arrval == -1) arrval = nways(type+1, value, coins, precomputed) + nways(type, value - coins[type], coins, precomputed);
	return arrval;
}


int main() {
	
	int value = 10000;
	const int coins[] = {9261, 8000, 6859, 5832, 4913, 4096, 3375, 2744, 2197, 1728, 1331, 1000, 729, 512, 343, 216, 125, 64, 27, 8, 1};
	vector< vector<long long> > precomputed (21, vector<long long> (value, -1));
	for (int i = 0; i < value; i++) {
		nways(0, i, coins, precomputed);
	}
	
	int input;
	while (cin >> input) {
		cout << nways(0, input, coins, precomputed) << endl;
	}
}