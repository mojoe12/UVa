#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		vector<int> bookv (n);
		map<int, bool> books;
		for (int i = 0; i < n; i++) {
			cin >> bookv[i];
			if (books.count(bookv[i])) {
				books[bookv[i]] = true;
			}
			else books.insert( make_pair(bookv[i], false) ) ;
		}
		
		int m;
		cin >> m;
		int maxmon = 0;
		for (int i = 0; i < n; i++) {
			int mon = bookv[i];
			if (2 * mon > m) continue;
			bool ok = books.count(m - mon) && (2 * mon != m || books[m - mon]);
			if (ok) maxmon = max(maxmon, mon);
		}
		
		cout << "Peter should buy books ";
		cout << "whose prices are " << maxmon;
		cout << " and " << m - maxmon << ".\n\n";
	}




}


