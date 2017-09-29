#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int divide (const vector<int>& coins, int i, int value, vector< vector<int> >& minvalues, int sum) {
	if (i == 0) return 0;
	int x = divide(coins, i-1, value, minvalues, sum);
	if (coins[i] > sum / 2 - value) return x;
	
	return min(x, abs(sum / 2 - coins[i] - divide(coins, i-1, value + coins[i], minvalues, sum)));
}


int main() {
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> coins (n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
			sum += coins[i];
		}
		
		vector< vector<int> > minvalues (n, vector<int> (sum + 1, -1));
		
		cout << divide(coins, n, 0, minvalues, sum) << endl;
	}
	




}


