#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int a, b;
		cin >> a >> b;
		int sumsize = a + b;
		multiset<int> l1, l2;
		int newnum;
		for (int i = 0; i < a; i++) {
			cin >> newnum;
			l1.insert(newnum);
		}
		for (int i = 0; i < b; i++) {
			cin >> newnum;
			l2.insert(newnum);
		}
		multiset<int> unionn;
		set_union(l1.begin(), l1.end(), l2.begin(), l2.end(), inserter(unionn, unionn.begin()));
		multiset<int> inters;
		set_intersection(l1.begin(), l1.end(), l2.begin(), l2.end(), inserter(inters, inters.begin()));
		cout << unionn.size() - inters.size() << endl;
	}
}