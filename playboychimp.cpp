#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	
	int n;
	cin >> n;
	vector<int> heights (n);
	for (int i = 0; i < n; i++) cin >> heights[i];
	sort(heights.begin(), heights.end());
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int h;
		cin >> h;
		
		vector<int>::iterator it;
		it = lower_bound(heights.begin(), heights.end(), h);
		if (it == heights.begin()) cout << "X ";
		else {
			it--;
			cout << *it << ' ';
		}
		
		it = upper_bound(heights.begin(), heights.end(), h);
		if (it == heights.end()) cout << "X\n";
		else cout << *it << endl;
	}
	




}


