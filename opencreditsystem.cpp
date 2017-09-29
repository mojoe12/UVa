#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> gaps (n-1);
		int prev;
		cin >> prev;
		for (int i = 1; i < n; i++) {
			int score;
			cin >> score;
			gaps[i-1] = prev - score;
			prev = score;
		}
		
		int running = 0;
		int best = *max_element(gaps.begin(), gaps.end());
		for (int i = 0; i < n-1; i++) {
			if (gaps[i] >= 0) running += gaps[i];
			else if (running + gaps[i] > 0) {
				if (running) best = max(best, running);
				running += gaps[i];
			}
			else {
				if (running) best = max(best, running);
				running = 0;
			}
		}
		if (running) best = max(best, running);
		cout << best << endl;
	}
}