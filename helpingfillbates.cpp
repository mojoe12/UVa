#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	string s;
	cin >> s;
	vector< vector<int> > positions (52);
	for (int i = 0; i < s.length(); i++) {
		int index = (s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
		positions[index].push_back(i);
	}
	
	int q;
	cin >> q;
	typedef vector<int>::iterator it_type;
	
	for (int i = 0; i < q; i++) {
		string sub;
		cin >> sub;
		
		bool ifok = true;
		int initialpos = 0, pos = -1;
		for (int j = 0; ifok && j < sub.length(); j++) {
			char c = sub[j];
			int index = (c <= 'Z') ? c - 'A' : c - 'a' + 26;
			it_type lb = lower_bound(positions[index].begin(), positions[index].end(), pos+1);
			if (lb == positions[index].end()) ifok = false;
			else pos = *lb;
			if (!j) initialpos = pos;
		}
		
		if (ifok) cout << "Matched " << initialpos << ' ' << pos << endl;
		else cout << "Not matched\n";

	}




}


