// SUUUUUUUUPER GROSS I KNOW
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int x = 1; x <= k; x++) {
		// INPUT
		
		int ac, bc, cc;
		cin >> ac;
		vector<int> a (ac);
		for (int i = 0; i < ac; i++) cin >> a[i];
		cin >> bc;
		vector<int> b (bc);
		for (int i = 0; i < bc; i++) cin >> b[i];
		cin >> cc;
		vector<int> c (cc);
		for (int i = 0; i < cc; i++) cin >> c[i];
		
		// SORT	
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		// REMOVE DUPLICATES
		a.erase( unique( a.begin(), a.end() ), a.end() );
		b.erase( unique( b.begin(), b.end() ), b.end() );
		c.erase( unique( c.begin(), c.end() ), c.end() );

		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				for (int k = 0; k < c.size(); k++) {
					if (a[i] == b[j] && b[j] == c[k]) {
						a[i] = -1;
						b[j] = -1;
						c[k] = -1;
					}
					
				}
			}
		}
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				for (int k = 0; k < c.size(); k++) {
					if (a[i] == b[j]) {
						a[i] = -1;
						b[j] = -1;
					}
				 	if (b[j] == c[k]) {
						b[j] = -1;
						c[k] = -1;
					}
					if (a[i] == c[k]) {
						a[i] = -1;
						c[k] = -1;
					}
				}
			}
		}	
		// GET RID OF DUPS
		
		for (int i = 0; a.size() != 0 && i < a.size();) {
			if (a[i] == -1) a.erase(a.begin() + i);
			else i++;
		}
		for (int i = 0; b.size() != 0 && i < b.size();) {
			if (b[i] == -1) b.erase(b.begin() + i);
			else i++;
		}
		for (int i = 0; c.size() != 0 && i < c.size();) {
			if (c[i] == -1) c.erase(c.begin() + i);
			else i++;
		}
		
		cout << "Case #" << x << ":\n";

		// FIND MAX
		if (a.size() >= b.size() && a.size() >= c.size()) {
			cout << "1 " << a.size();
			for (int i = 0; i < a.size(); i++) cout << " " << a[i];
			cout << endl;
		}
		if (b.size() >= a.size() && b.size() >= c.size()) {
			cout << "2 " << b.size();
			for (int i = 0; i < b.size(); i++) cout << " " << b[i];
			cout << endl;
		}
		if (c.size() >= a.size() && b.size() <= c.size()) {
			cout << "3 " << c.size();
			for (int i = 0; i < c.size(); i++) cout << " " << c[i];
			cout << endl;
		}
	}
}