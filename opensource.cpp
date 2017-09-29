#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp (pair<string, int> i, pair<string, int> j) {
	if (i.second == j.second) return i.first < j.first;
	return i.second > j.second;
}

int main(int argc, char *argv[]) {
	string name = "";
	while (1) {
		getline(cin, name);
		if (name[0] == '0') break;
		map<string, string> id2proj;
		vector<string> allprojs;
		while (name[0] != '1' && name[0] != '0') {
			string proj = name;
			allprojs.push_back(proj);
			while (getline(cin, name)) {
				if (name[0] - 'a' < 0 || name[0] - 'a' > 25) break;
				if (id2proj.count(name) && id2proj[name] != proj) id2proj[name] = "-1";
				else id2proj.insert( make_pair(name, proj) );
			}
		}
		
		map<string, int> counts;
		typedef map<string, string>::iterator it_type;
		for (it_type it = id2proj.begin(); it != id2proj.end(); it++) {
			if (it->second == "-1") continue;
			if ( counts.count(it->second) ) counts[it->second]++;
			else counts.insert( make_pair(it->second, 1) );
		}
		
		for (int i = 0; i < allprojs.size(); i++) {
			if ( !counts.count(allprojs[i]) ) counts.insert ( make_pair(allprojs[i], 0) );
		}
		
		vector< pair<string, int> > countsv;
		typedef map<string, int>::iterator it_type2;
		for (it_type2 it = counts.begin(); it != counts.end(); it++) {
			countsv.push_back( *it );
		}

		sort(countsv.begin(), countsv.end(), comp);
		
		for (int i = 0; i < countsv.size(); i++) {
			cout << countsv[i].first << ' ' << countsv[i].second << endl;
		}
		
	}
}