#include <iostream>
#include <set>

using namespace std;
int main(int argc, char *argv[]) {
	typedef multiset<int>::iterator it_type;
	
	int n;
	while (cin >> n) {
		if (n == 0) break;
		multiset<int> urn;
		long long paid = 0;
		for (int d = 0; d < n; d++) {
			int k;
			cin >> k;
			for (int i = 0; i < k; i++) {
				int bill;
				cin >> bill;
				urn.insert(bill);
			}
			it_type it = urn.begin();
			int smallest = *it;
			urn.erase(it);
			
			it = urn.end();
			it--;
			int biggest = *it;
			urn.erase(it);
			
			paid += (biggest - smallest);
		}
		cout << paid << endl;
	}
}