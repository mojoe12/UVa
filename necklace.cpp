#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int total, cost;
	while (cin >> total >> cost) {
		if (!total && !cost) break;
		int best = 0, bestn = 0;
		for (int n = 1; total >= n * cost; n++) {
			int dist = total * n - cost * n * n;
			
			//cout << n << ' ' << dist << endl;
			
			if (dist > best) {
				best = dist;
				bestn = n;
			}
			else if (best == dist) {
				bestn = 0;
			}
		}
		cout << bestn << endl;
	}
}