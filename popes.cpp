#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {
	
	int y, p;
	while (cin >> y >> p) {
		vector<int> years (p);
		for (int i = 0; i < p; i++) cin >> years[i];
		
		int maxpopes = 0, besti = -1;
		for (int i = 0; i < p; i++) {
			int start = years[i];
			int numpopes = upper_bound(years.begin()+i, years.end(), start + y-1) - years.begin() - i;
			if (numpopes > maxpopes) {
				maxpopes = numpopes;
				besti = i;
			}
		}
		
		cout << maxpopes << ' ';
		cout << years[besti] << ' ';
		cout << years[besti + maxpopes-1] << endl;
	}




}


