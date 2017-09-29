#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	typedef multiset<int>::iterator it_type;
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		
		int nbats, ngreen, nblue;
		cin >> nbats >> ngreen >> nblue;
		
		int warrior;
		multiset<int> green;
		for (int i = 0; i < ngreen; i++) {
			cin >> warrior;
			green.insert(warrior);
		}
		multiset<int> blue;
		for (int i = 0; i < nblue; i++) {
			cin >> warrior;
			blue.insert(warrior);
		}
		while (blue.size() && green.size()) {
			vector<int> woundedgreen;
			vector<int> woundedblue;
			for (int i = 0; i < nbats; i++) {
				if (!green.size() || !blue.size()) break;
				it_type itg = green.end();
				itg--;
				it_type itb = blue.end();
				itb--;
				if (*itg > *itb) {
					woundedgreen.push_back(*itg - *itb);
				}
				else if (*itb > *itg) {
					woundedblue.push_back(*itb - *itg);
				}
				green.erase(itg);
				blue.erase(itb);
			}
			for (int i = 0; i < woundedgreen.size(); i++) {
				green.insert(woundedgreen[i]);
			}
			for (int i = 0; i < woundedblue.size(); i++) {
				blue.insert(woundedblue[i]);
			}
		}
		if (blue.size()) {
			cout << "blue wins\n";
			for (it_type it = blue.end(); it != blue.begin();) {
				it--;
				cout << (*it) << endl;
			}
		}
		else if (green.size()) {
			cout << "green wins\n";
			for (it_type it = green.end(); it != green.begin();) {
				it--;
				cout << (*it) << endl;
			}
		}
		else {
			cout << "green and blue died\n";
		}
		
	}
}