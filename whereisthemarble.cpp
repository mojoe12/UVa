#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;



int main() {
	
	int n, q;
	for (int c = 1; cin >> n >> q; c++) {
		
		if (!n && !q) break;
		map<int, int> marbles;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (marbles.count(x)) marbles[x]++;
			else marbles.insert(make_pair(x, 1));
		}
		
		int prev = 1;
		for (map<int, int>::iterator it = marbles.begin(); it != marbles.end(); it++) {
			int temp = prev;
			prev += it->second;
			it->second = temp;
		}
		
		cout << "CASE# " << c << ":\n";
		
		for (int i = 0; i < q; i++) {
			int num;
			cin >> num;
			if (marbles.count(num)) {
				cout << num << " found at " << marbles[num] << endl;
			}
			else cout << num << " not found\n";
		}
	}




}


