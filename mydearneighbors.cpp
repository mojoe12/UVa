#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	
	string s;
	int k;
	cin >> k;
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		
		if (c) getline(cin, s);
		
		int v;
		cin >> v;
		getline(cin, s);
		vector<int> bestindices;
		int minspaces = 10000;
		for (int i = 0; i < v; i++) {
			getline(cin, s);
			int nspaces = count(s.begin(), s.end(), ' ');
			if (nspaces == minspaces) {
				bestindices.push_back(i+1);
			}
			else if (nspaces < minspaces) {
				minspaces = nspaces;
				bestindices = vector<int>();
				bestindices.push_back(i+1);
			}
		}
		
		for (int i = 0; i < bestindices.size()-1; i++) {
			cout << bestindices[i] << ' ';
		}
		cout << bestindices[bestindices.size()-1] << endl;
	}
}