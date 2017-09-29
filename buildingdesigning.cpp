#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	// basically sort it and then alternate from each end, but only go as far as the absolute of the previous
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		
		vector<int> red, blue;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x < 0) red.push_back(-x);
			else blue.push_back(x);
		}
		
		int rsize = red.size(), bsize = blue.size();
		
		if (!rsize || !bsize) {
			cout << (rsize || bsize) << endl;
			continue;
		}
		
		sort(red.begin(), red.end(), greater<int>());
		sort(blue.begin(), blue.end(), greater<int>());
		
		
		// red first
		int r = 0, b = 0, sum1 = 1;
		if (red[0] > blue[0]) sum1++; // maybe + 2?
		while (true) {
			for (; r < rsize; r++) {
				if (red[r] < blue[b]) break;
			}
			if (r == rsize) break;
			else sum1++;
			for (; b < bsize; b++) {
				if (blue[b] < red[r]) break;
			}
			if (b == bsize) break;
			else sum1++;
		}
		
		// blue first
		
		r = 0;
		b = 0;
		int sum2 = 1;
		if (blue[0] > red[0]) sum2++; // maybe + 2?
		while (true) {
			for (; b < bsize; b++) {
				if (blue[b] < red[r]) break;
			}
			if (b == bsize) break;
			else sum2++;
			for (; r < rsize; r++) {
				if (red[r] < blue[b]) break;
			}
			if (r == rsize) break;
			else sum2++;
		}
		
		cout << max(sum1, sum2) << endl;
		
		
		
		// bfirst

		
		
	}
}