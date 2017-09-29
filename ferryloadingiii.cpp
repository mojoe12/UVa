#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void ferry (queue< pair<int, int> >& cside, queue< pair<int, int> >& oside, int m, vector<int>& droptimes, int time, int t) 
{
	//cout << time << endl;
	if (!cside.size() && !oside.size()) return;
	
	if (!cside.size()) {
		ferry(oside, cside, m, droptimes, max(oside.front().first + t, time+t), t);
		return;
	}

	if (cside.front().first > time && oside.size() && oside.front().first < cside.front().first) {
		ferry(oside, cside, m, droptimes, max(oside.front().first + t, time+t), t);
		return;
	}

	int load = 1;
	if (cside.front().first > time) time = cside.front().first;
	droptimes[cside.front().second] = time+t;
	cside.pop();

	while (load < m && cside.size() && cside.front().first <= time) {
		load++;
		droptimes[cside.front().second] = time+t;
		cside.pop();
	}

	ferry(oside, cside, m, droptimes, time + t, t);
}

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		
		if (c) cout << endl;
		//input
		int m, t, n;
		cin >> m >> t >> n;
		queue< pair<int, int> > l, r;
		for (int i = 0; i < n; i++) {
			int x;
			string s;
			cin >> x >> s;
			if (s == "left") l.push( make_pair(x, i) );
			else if (s == "right") r.push( make_pair(x, i) );
		}
		
		// prepvars
		vector<int> droptimes (n);
		
		ferry(l, r, m, droptimes, 0, t);
		for (int i = 0; i < n; i++) cout << droptimes[i] << endl;
	}
}