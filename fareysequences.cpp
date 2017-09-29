#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool comp (pair<int, int> i, pair<int, int> j) {
	return i.first * j.second < i.second * j.first;
}

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	
	int n, k;
	while (cin >> n >> k) {
		vector< pair<int, int> > fracs; 
		for (int num = 1; num < n; num++) {
			for (int den = n; den > 0; den--) {

				if (gcd(num, den) > 1) continue;
				if (num > den) continue;
				fracs.push_back( make_pair(num, den));
			}
		}
		sort(fracs.begin(), fracs.end(), comp);
		cout << fracs[k-1].first << '/';
		cout << fracs[k-1].second << endl;
	}




}


