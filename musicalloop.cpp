#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		bool past = true;
		int peaks = 0;
		// true = up, false is down
		int first, second;
		cin >> first >> second;
		past = (second - first) > 0;
		int prev = second;
		for (int i = 2; i <= n+1; i++) {
			int next = 0;
			if (i == n) next = first;
			else if (i == n+1) next = second;
			else cin >> next;
			bool direc = (next - prev) > 0;
			if (direc != past) {
				past = direc;
				peaks++;
			}
			prev = next;
		}
		cout << peaks << endl;
	}
}