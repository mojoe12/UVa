#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int m;
	while (cin >> m) {
		vector< pair<int, int> > ones, threes;
		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == '1') ones.push_back( make_pair(i, j) );
				else if (s[j] == '3') threes.push_back( make_pair(i, j) );
			}
		}
		
		int maxdist = 0;
		for (int i = 0; i < ones.size(); i++) {
			int mindist = 2*m;
			for (int j = 0; j < threes.size(); j++) {
				int xdist = abs(threes[j].second - ones[i].second);
				int ydist = abs(threes[j].first - ones[i].first);
				//cout << xdist << ' ' << ydist << endl;
				mindist = min(mindist, xdist + ydist);
			}
			//cout << mindist << endl;
			maxdist = max(maxdist, mindist);
		}
		
		cout << maxdist << endl;
	}



}


