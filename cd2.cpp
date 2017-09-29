#include <iostream>
#include <vector>

using namespace std;

void makeTape(int time, int i, const vector<int>& cds, vector<int>& currtape, int& currlen, vector<int>& besttape, int& bestlen) {
	if (i == cds.size()) {
		if (currlen > bestlen) {
			besttape = currtape;
			bestlen = currlen;
		}
		return;
	}
	if (currlen + cds[i] <= time) {
		currtape.push_back(cds[i]);
		currlen += cds[i];
		makeTape(time, i+1, cds, currtape, currlen, besttape, bestlen);
		currtape.pop_back();
		currlen -= cds[i];
	}
	makeTape(time, i+1, cds, currtape, currlen, besttape, bestlen);
}

int main(int argc, char *argv[]) {
	int time, n;
	while (cin >> time >> n) 
	{
		vector<int> cds (n);
		for (int i = 0; i < n; i++) cin >> cds[i];
		vector<int> besttape, currtape;
		int i = 0, currlen = 0, bestlen = 0;
		makeTape(time, i, cds, currtape, currlen, besttape, bestlen);
		if (besttape.size()) cout << besttape[0];
		for (int i = 1; i < besttape.size(); i++) 
		{
			cout << ' ' << besttape[i];
		}
		cout << " sum:" << bestlen << endl;
	}
}