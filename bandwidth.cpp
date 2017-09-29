#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;



int main() {
	
	string s;
	while (cin >> s) {
		if (s == "#") break;
		vector< pair<char, int> > nodeindex;
		vector< vector<char> > neighbors;
		
		vector< pair<char, string> > parse;
		parse.push_back( make_pair(s[0], "") );
		for (int i = 2; i < s.length(); i++) {
			if (s[i] == ';') {
				parse.push_back( make_pair(s[i+1], ""));
				i += 2;
			}
			else {
				parse[parse.size()-1].second += s[i];
			}
		}
		
		map<char, int> nodetoindex;
		vector<char> indextonode;
		for (int i = 0; i < parse.size(); i++) {
			for (int j = -1; j < parse[i].second.size(); j++) {
				char c = i < 0 ? parse[i].first : parse[i].second[j];
				if (!nodetoindex.count(c)) {
					nodetoindex.insert(make_pair(c, indextonode.size()));
					indextonode.push_back(c);
				}
			}
		}
		
		int n = indextonode.size();
		
		vector< vector<int> > neighbors (n);
		for (int i = 0; i < parse.size(); i++) {
			int indexi = nodetoindex[parse[i].first];
			for (int j = 0; j < parse[i].second.size(); j++) {
				int indexj = nodetoindex[parse[i].second[j]];
				neighbors[indexi].push_back(indexj);
				neighbors[indexj].push_back(indexi);
			}
		}
		
		vector<char> ordering = indextonode;
		sort(ordering.begin(), ordering.end());
		
		string bestordering = ""; 
		int minorderingbw = -1;
		do {
			int maxbw = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < neighbors[i].size(); j++) {
					
				}
			}
			if (minorderingbw == -1 || maxbw < minorderingbw) {
				minorderingbw = maxbw;
				bestordering = "";
				for (int i = 0; i < n; i++) {
					ordering.push_back(ordering[i]);
				}
			}
		} while (next_permutation(ordering.begin(), ordering.end()));
		
	}




}


