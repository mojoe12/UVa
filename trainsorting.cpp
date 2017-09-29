#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> lis (n), lds (n), weights (n);
		
		for (int i = 0; i < n; i++) {
			cin >> weights[i];
			
			int maxlis = -1, maxlds = -1;
			for (int j = 0; j < i; j++) {
				if (weights[i] > weights[j]) maxlis = max(maxlis, lis[j]);
				if (weights[i] < weights[j]) maxlds = max(maxlds, lds[j]);
			}
			lis[i] = 1 + maxlis;
			lds[i] = 1 + maxlds;
			
		}
		
		int maxsum = 0;
		for (int i = 0; i < n; i++) {
			int sum = lis[i] + lds[i] + 1;
			maxsum = max(maxsum, sum);
		}
		
		cout << maxsum << endl;
		
	}



}


