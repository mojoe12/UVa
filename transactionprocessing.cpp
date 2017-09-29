#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



int main() {
	
	vector<string> accnames (1000);
	while (true) {
		char a, b, c;
		cin >> a >> b >> c;
		int accnum = 100 * (a - '0') + 10 * (b - '0') + (c - '0');
		string name;
		getline(cin, name);
		if (!accnum) break;
		accnames[accnum] = name;
	}
	
	int currtrans = -1;
	int currsum = 0;
	vector< pair<int, int> > transaction;
	while (true) {
		char a, b, c;
		cin >> a >> b >> c;
		int trans = 100 * (a - '0') + 10 * (b - '0') + (c - '0');
		
		if (currtrans != trans) {
			if (currsum) {
				cout << "*** Transaction ";
				cout << currtrans;
				cout << " is out of balance ***\n";
				for (int i = 0; i < transaction.size(); i++) {
					cout << transaction[i].first << ' ';
					cout.width(31);
					cout << left << accnames[transaction[i].first];
					cout.width(10);
					cout << right << fixed << setprecision(2) << transaction[i].second / 100.0;
					cout << endl;
				}
				cout << "999 Out of Balance";
				cout.width(27);
				cout << right << fixed << setprecision(2) << -currsum / 100.0;
				cout << endl << endl;
				
			}
			
			currtrans = trans;
			transaction = vector< pair<int, int> >();
			currsum = 0;
		}
		
		cin >> a >> b >> c;
		int accnum = 100 * (a - '0') + 10 * (b - '0') + (c - '0');
		int amount;
		cin >> amount;
		currsum += amount;
		transaction.push_back (make_pair(accnum, amount));
		if (!trans) break;
	}
	
	




}


