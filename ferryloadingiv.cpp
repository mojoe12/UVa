#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int len, n;
		cin >> len >> n;
		len *= 100;
		queue<int> l, r;
		for (int i = 0; i < n; i++) {
			int x;
			string s;
			cin >> x >> s;
			if (s == "left") l.push(x);
			else if (s == "right") r.push(x);
		}
		
		bool side = 0; // left
		int nswitch = 0;
		
		while (l.size() || r.size()) {
			int load = 0;
			if (side) {
				while (r.size() && load + r.front() <= len) {
					load += r.front();
					r.pop();
				}
			}
			else {
				while (l.size() && load + l.front() <= len) {
					load += l.front();
					l.pop();
				}
			}
			nswitch++;
			side = !side;
		}
		
		cout << nswitch << endl;
	}
}