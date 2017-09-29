#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int knapsack (int id, int remw, vector<int>& prices, vector<int>& weights, vector< vector<int> > arr) {
	
	if (id == prices.size() || !remw) return 0;
	
	int arrval = arr[id][remw-1];
	if (arrval == -1) {
		int x = 0, y = knapsack(id+1, remw, prices, weights, arr);
		if (weights[id] <= remw) x = prices[id] + knapsack(id+1, remw - weights[id], prices, weights, arr);
		arrval = max(x, y);
	}
	return arrval;

}

int main() {
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		
		vector<int> prices (n), weights(n);
		
		for (int i = 0; i < n; i++) {
			cin >> prices[i] >> weights[i];
		}
				
		int g;
		cin >> g;
		vector<int> input (g);
		int maxv = 0;
		for (int i = 0; i < g; i++) {
			cin >> input[i];
			maxv = max(maxv, input[i]);
		}
		
		int sumval = 0;
		vector< vector<int> > arr (n, vector<int> (maxv, -1));
		for (int i = 0; i < g; i++) {
			sumval += knapsack(0, input[i], prices, weights, arr);
		}
		cout << sumval << endl;
		
	}	




}


