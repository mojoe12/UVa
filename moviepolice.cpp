#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	int d, t;
	cin >> d >> t;
	
	vector<string> db (d);
	for (int i = 0; i < d; i++) {
		cin >> db[i];
	}
	
	for (int c = 0; c < t; c++) {
		string s;
		cin >> s;
		
		int besti = -1, mindiff = -1;
		for (int i = 0; i < d; i++) {
			if (db[i].size() < s.size()) continue;
			for (int j = 0; j <= db[i].size() - s.size(); j++) {
				int diff = 0;
				for (int k = 0; k < s.size(); k++) {
					if (db[i][j + k] != s[k]) diff++;
				}
				if (mindiff == -1 || diff < mindiff) {
					mindiff = diff;
					besti = i;
				}
			}
		}
		
		cout << besti+1 << endl;
		
	}


}


