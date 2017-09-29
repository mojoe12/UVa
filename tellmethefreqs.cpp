#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (pair<int, int> i, pair<int, int> j) {
	if (i.second == j.second) return i.first > j.first;
	return i.second < j.second;
}

int main(int argc, char *argv[]) {
	string s;
	bool iffirst = true;
	while (getline(cin, s)) {
		
		if (!iffirst) cout << endl;
		else iffirst = false;
		
		map<int, int> mp;
		
		for (int i = 0; i < s.length(); i++) {
			int ascii = (s[i]  - ' ') + 32;
			if (mp.count(ascii)) mp[ascii]++;
			else mp.insert( pair<int, int> (ascii, 1));
		}
		
		vector<pair<int, int> > vec;
		typedef map<int, int>::iterator it_type;
		for (it_type it = mp.begin(); it != mp.end(); it++) {
			pair<int, int> newpair ( (it -> first), (it -> second) );
			vec.push_back(newpair);
		}
		
		sort(vec.begin(), vec.end(), comp);
		
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].first << ' ' << vec[i].second << endl;
		}
		
	}
}