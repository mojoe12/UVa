#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;

struct event {
	event (int s, char w, int l) :
	spot(s), what(w), liters(l) {}
	int spot;
	char what;
	int liters;
};


int main() {
	
	int n, l;
	string s, nothing;
	while (true) {
		bool end = false;
		vector<event> events;
		while (!end) {
			cin >> n >> s;
			if (s == "Fuel" || s == "Gas") cin >> nothing;
			l = 0;
			if (s[0] == 'F') cin >> l;
			if (s == "Goal") s[0] = 'O';
			events.push_back(event (n, s[0], l));
			if (s == "Fuel" && l == 0) end = true;
			if (s[0] == 'O') break;
		}
		if (end) break;
		
		double minv = 0, maxv = events.size() * n;
		double totalvol = 0;
		while (abs(maxv - minv) >= 1e-4) {
			
			totalvol = (minv + maxv) / 2.0;
			int cons = 0, nleaks = 0;
			
			//cout << totalvol << endl;
			
			bool ok = true;
			int prev = 0;
			double currvol = totalvol;
			for (int i = 0; ok && i < events.size(); i++) {
				int dist = events[i].spot - prev;
				prev = events[i].spot;
				double fuelloss = dist * (cons / 100.0 + nleaks);
				//cout << fuelloss << endl;
				if (currvol < fuelloss) ok = false;
				else currvol -= fuelloss;
				
				switch (events[i].what) {
					case 'F':
						cons = events[i].liters;
						break;
					case 'L':
						nleaks++;
						break;
					case 'G':
						currvol = totalvol;
						break;
					case 'M':
						nleaks = 0;
				}
			}
			
			if (ok) maxv = totalvol;
			else minv = totalvol;
			
		}
		
		cout << setprecision(3) << fixed << totalvol << endl;
		
	}




}


