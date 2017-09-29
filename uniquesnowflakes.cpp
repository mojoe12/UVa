#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> i, pair<int, int> j) {
	if (i.first == j.first) return i.second < j.second;
	return i.first < j.first;
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;

		map<int, vector<int> > mp;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			if (mp.count(s)) mp[s].push_back(i);
			else {
				vector<int> newvec;
				newvec.push_back(i);
				mp.insert( make_pair(s, newvec) );
			}
		}
		
		vector< pair<int, int> > intervals;
		map<int, vector<int> >::iterator it = mp.begin();
		for (; it != mp.end(); it++) {
			for (int i = 1; i < (it->second).size(); i++) {
				intervals.push_back( make_pair((it->second)[i-1], (it->second)[i]) );
			}
		}
		
		sort(intervals.begin(), intervals.end(), comp);
		
		int maxdist = 0;
		for (int i = 0; i < intervals.size(); i++) {
			bool ifok = intervals[i].second - intervals[i].first > maxdist;
			for (int j = i+1; ifok && j < intervals.size(); j++) {
				if (intervals[j].second < intervals[i].second) {
					ifok = false;
				}
				else if (intervals[j].first > intervals[i].second) break;
			}
			if (ifok) maxdist = intervals[i].second - intervals[i].first;
			
			if (i < intervals.size()-1) maxdist = max(maxdist, intervals[i+1].first - intervals[i].second);
		}
		int otherdist;
		if (intervals.size()) otherdist = n - 1 - intervals[intervals.size()-1].first;
		else otherdist = n;
		
		maxdist = max(maxdist, otherdist);
		cout << maxdist << endl;
	}
}