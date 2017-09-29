#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	cout << fixed << setprecision(4);
	for (int c = 0; c < k; c++) {
		if (c > 0) cout << endl;
		int total = 0;
		map<string, int> mp;
		while (getline(cin, s)) {
			if (s == "") break;
			total++;
			if (mp.count(s)) mp[s]++;
			else mp.insert( make_pair (s, 1) );
		}
		typedef map<string, int>::iterator it_type;
		for (it_type it = mp.begin(); it != mp.end(); it++) {
			cout << (it -> first) << ' ';
			double ratio = (100 * it -> second) / (total * 1.0);
			cout << ratio << endl;
		}
	}
}