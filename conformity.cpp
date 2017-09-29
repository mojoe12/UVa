#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<string> combos (n);
		for (int s = 0; s < n; s++) {
			vector<string> courses (5);
			for (int i = 0; i < 5; i++) cin >> courses[i];
			sort(courses.begin(), courses.end());
			
			string combo = courses[0];
			for (int i = 1; i < 5; i++) combo = combo + courses[i];
			combos[s] = combo;
		}
		map<string, int> mp;
		for (int c = 0; c < n; c++) {
			string combo = combos[c];
			if (mp.count(combo)) mp[combo]++;
			else mp.insert( make_pair(combo, 1) );
		}
		
		int bestcount = 0, nummost = 0;
		typedef map<string, int>::iterator it_type;
		for (it_type it = mp.begin(); it != mp.end(); it++) {
			if ((it->second) > bestcount) {
				bestcount = it->second;
				nummost = it->second;
			}
			else if ((it->second) == bestcount) {
				nummost += it->second;
			}
		}
		cout << nummost << endl; 
	}
}