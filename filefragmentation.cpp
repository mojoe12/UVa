#include <iostream>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string num;
	getline(cin, num);
	
	getline(cin, num);
	
	for (int c = 0; c < k; c++) {
		if (c > 0) cout << endl;
		map<int, string> pieces;
		int sumlength = 0, numpieces = 0;
		while (getline(cin, num)) {
			if (num == "") break;
			int l = num.length();
			
			sumlength += l;
			numpieces++;
			
			if (pieces.count(2*l) && pieces[2*l] != num) {
				pieces.insert( make_pair(2*l+1, num) );
			}
			else pieces.insert( make_pair(2*l, num) );
		}
		map<string, int> counter;
		typedef map<int, string>::iterator it_type;
		int length = 2 * sumlength / numpieces;
		for (it_type it = pieces.begin(); it != pieces.end(); it++) {
			int l = (it -> first) / 2, ol = length - l;
			if ( !(pieces.count(2*ol+1)) && pieces.count(2*ol)) {
				string combo = (it->second) + pieces[2*ol];
				if (counter.count(combo)) counter[combo]++;
				else counter.insert( make_pair(combo, 1) );
			}
			if ( (pieces.count(2*ol)) && pieces.count(2*ol+1)) {
				string combo = (it->second) + pieces[2*ol+1];
				if (counter.count(combo)) counter[combo]++;
				else counter.insert( make_pair(combo, 1) );
			}
		}
		typedef map<string, int>::iterator it_type2;
		string beststring = "sadplane.jpg";
		int bestcount = 0;
		for (it_type2 it = counter.begin(); it != counter.end(); it++) {

			if ((it->second) > bestcount) {
				bestcount = it->second;
				beststring = it->first;
			}
		}

		cout << beststring << endl;
	}
}