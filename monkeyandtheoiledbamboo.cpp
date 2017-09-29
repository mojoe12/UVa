#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int t;
	cin >> t;
	
	for (int c = 1; c <= t; c++) {
		
		int n;
		cin >> n;
		int mink = 0, maxk = 0;
		vector<int> jumps (n);
		int prev = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			jumps[i] = x - prev;
			mink = max(mink, jumps[i]);
			maxk = max(maxk, jumps[i] + i + 1);
			prev = x;
		}
		
		while (mink != maxk) {
			//cout << mink << ' ' << maxk << endl;
			
			int mid = (mink + maxk) / 2;
			
			int k = mid;
			int prev = 0;
			bool ok = true;
			for (int i = 0; ok && i < n; i++) {
				if (jumps[i] > k) ok = false; 
				else if (jumps[i] == k) k--;
			}
			
			if (ok) {
				if (maxk == mid) break;
				maxk = mid;
			}
			else {
				if (mink == mid) break;
				mink = mid;
			}
		}
		
		cout << "Case " << c << ": " << maxk << endl;
	}




}


