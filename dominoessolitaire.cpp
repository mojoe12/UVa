#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bool ifsolution(int n, pair<int, int> leftdom, pair<int, int> rightdom, vector< pair<int, int> >& doms, bitset<14> domsb ); 

int main() {
	
	int n, m;
	while (cin >> n) {
		if (!n) break;
		cin >> m;
		int x, y;
		cin >> x >> y;
		pair<int, int> leftdom (x, y);
		cin >> x >> y;
		pair<int, int> rightdom (x, y);
		vector< pair<int, int> > doms (m);
		bitset<14> domsb; // ifused
		for (int i = 0; i < m; i++) cin >> doms[i].first >> doms[i].second;
		
		if (ifsolution(n, leftdom, rightdom, doms, domsb)) cout << "YES\n";
		else cout << "NO\n";
	}
}

bool ifsolution(int n, pair<int, int> leftdom, pair<int, int> rightdom, vector< pair<int, int> >& doms, bitset<14> domsb ) {
	if (!n) {
		return leftdom.second == rightdom.first;
	}
	for (int i = 0; i < doms.size(); i++) {
		if (domsb[i]) continue;
		if (doms[i].first == leftdom.second) {
			domsb[i] = true;
			if (ifsolution(n-1, doms[i], rightdom, doms, domsb)) return true;
			domsb[i] = false;
		}
		else if (doms[i].second == leftdom.second) {
			domsb[i] = true;
			pair<int, int> switchdom (doms[i].second, doms[i].first);
			if (ifsolution(n-1, switchdom, rightdom, doms, domsb)) return true;
			domsb[i] = false;
		}
	}
	return false;
}