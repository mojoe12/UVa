#include <iostream>
#include <vector>
#include <algorithm>

class bound {
	public:
		int l, r;
		bound () {}
		bound (int L, int R) {
			l = L;
			r = R;
		}
};

bool comp (bound a, bound b) {
	return a.l < b.l;
}
// MIGHT GET ARMY BUDDIES SYNDROME
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int once, peat;
		cin >> once >> peat;
		if (once + peat == 0) break;
		vector <bound> bounds (once);
		for (int i = 0; i < once; i++) {
			int L, R;
			cin >> L >> R;
			bounds[i].l = min(L,R);
			bounds[i].r = max(L,R);
		}
		// we could try checking here, might save some time
		// or continuously checking in the loop below
		for (int i = 0; i < peat; i++) {
			int l, r, interval;
			cin >> l >> r >> interval;
			for (int L = min(l,r), R = max(l,r); R <= 1000000; L += interval, R += interval) {
				bound newbound (L, R);
				bounds.push_back(newbound);
			}
		}
		// input over
		sort(bounds.begin(), bounds.end(), comp);
		bool conflict = false;
		for (int i = 0; i < bounds.size()-1; i++) {
			if (bounds[i].r > bounds[i+1].l) {
				conflict = true;
				break;
			}
		}
		if (conflict) cout << "CONFLICT\n";
		else cout << "NO CONFLICT\n";
	}
}