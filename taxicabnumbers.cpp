#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	
	vector<int> alltax;
	map<int, int> allsums;
	for (int a = 1; a <= 1000; a++) {
		for (int b = a; b <= 1000; b++) {
			int sum = a*a*a + b*b*b;
			if (allsums.count(sum)) allsums[sum]++;
			else allsums.insert(make_pair(sum, 0));
			if (allsums[sum] == 1) alltax.push_back(sum);
		}
	}
	//cout << alltax[alltax.size()-1] << endl;
	sort(alltax.begin(), alltax.end());
	//for (int i = 0; i < alltax.size(); i++) cout << alltax[i] << endl;
	
	int start, range;
	while (cin >> start >> range) {
		bool ifany = false;
		for (int i = 0; i < alltax.size(); i++) {
			if (alltax[i] >= start && alltax[i] <= start + range) {
				cout << alltax[i] << endl;
				ifany = true;
			}
		}
		if (!ifany) cout << "None\n";
	}




}


