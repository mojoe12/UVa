#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int n, c;
	while (cin >> n >> c) {
		vector<int> vessels (n);
		int maxv = 0, minv = -1;
		for (int i = 0; i < n; i++) {
			cin >> vessels[i];
			minv = max(minv, vessels[i]);
			maxv += vessels[i];
		}
		
		while (true) {
			//cout << minv << ' ' << maxv << endl;
			
			int mid = (minv + maxv) / 2;
			
			vector<int> capacities (c, 0);
			int ci = 0;
			bool ifok = true;
			
			//cout << mid << endl;
			for (int i = 0; ifok && i < n; i++) {
				//cout << capacities[ci] << endl;
				if (capacities[ci] + vessels[i] <= mid) {
					capacities[ci] += vessels[i];
				}
				else {
					ci++;
					if (ci == c) ifok = false;
					else capacities[ci] += vessels[i];
				}
			}
			
			if (ifok) {
				if (maxv == mid) break;
				maxv = mid;
			}
			else {
				if (minv == mid) break;
				minv = mid;
			}
		}
		
		cout << maxv << endl;
		
	}




}


