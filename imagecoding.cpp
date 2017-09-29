#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int ca = 1; ca <= k; ca++) {
		int c, r, m, n;
		cin >> c >> r >> m >> n;
		
		map<char, int> mapp;
		for (int i = 0; i < c * r; i++) {
			char ch;
			cin >> ch;
			if (mapp.count(ch)) mapp[ch]++;
			else mapp.insert(make_pair(ch, 1));
		}
		
		map<char, int>::iterator it = mapp.begin();
		int maxx = 0, numlets = 1; 
		for (; it != mapp.end(); it++) {
			if (it->second > maxx) {
				maxx = it->second;
				numlets = 1;
			}
			else if (it->second == maxx) numlets++;
		}
		
		int nbytes = maxx * numlets * m + (c * r - maxx * numlets) * n;
		cout << "Case " << ca << ": " << nbytes << endl;
	}
}