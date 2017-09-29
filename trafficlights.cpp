#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>


using namespace std;



int main() {
	
	int x;
	for (bool iffirst = true; ; iffirst = false) {
		if (iffirst) cin >> x;
		
		vector<int> lights;
		
		int minl = INT_MAX;
		while (x) {
			minl = min(minl, x);
			lights.push_back(x);
			cin >> x;
		}
		
		
		int time = minl;
		int maxtime = 5 * 60 * 60;
		for (; time <= maxtime; time++) {
			bool ifok = true;
			for (int i = 0; ifok && i < lights.size(); i++) 
			{
				ifok = time % (2 * lights[i]) < (lights[i] - 5);
			}
			if (ifok) break;
		}
		
		if (time > maxtime) cout << "Signals fail to synchronise in 5 hours\n";
				
		else {
			cout << '0' << time / 3600 << ':';
			int minutes = ((time / 60) % 60), seconds = time % 60;
			if (minutes < 10) cout << '0';
			cout << minutes << ':';
			if (seconds < 10) cout << '0';
			cout << seconds << endl;
		}
		cin >> x;
		if (!x) break;
	}
	cin >> x >> x;

}


