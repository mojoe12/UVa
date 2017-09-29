#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	string s;
	while (getline(cin, s)) {
		int ans = 0, csize = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') csize++;
			else {
				int nactions = 0;
				for (; csize > 1; nactions++) csize = ceil(csize/2.0);
				ans = max(ans, nactions);
				csize = 0;
			}
		}
		cout << ans << endl;
	}



}


