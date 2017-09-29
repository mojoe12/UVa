#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int main(int argc, char *argv[]) {
	int a, b;
	for (cin >> a >> b; a != 0 || b != 0; cin >> a >> b) {
		set<int> jack;
		int cd;
		for (int i = 0; i < a; i++) {
			cin >> cd;
			jack.insert(cd);
		}
		set<int> jill;
		for (int i = 0; i < b; i++) {
			cin >> cd;
			jill.insert(cd);
		}
		set<int> both;
		
		set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), inserter(both,both.begin()) );
		
		cout << both.size() << endl;
	}
}