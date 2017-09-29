#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int leading;
	
	while (cin >> leading) {
		vector< pair<int, int> > coes;
		coes.reserve(9);
		if (leading) coes.push_back( make_pair(leading, 8));
		for (int i = 7; i > -1; i--) {
			int coe;
			cin >> coe;
			if (coe) coes.push_back( make_pair(coe, i));
		}
		
		if (!coes.size()) {
			cout << "0\n";
			continue;
		}
		
		if (coes.size() == 1) {
			
		}
		
		
	}
	




}


