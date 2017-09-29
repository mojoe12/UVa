#include <iostream>
#include <vector>

using namespace std;
int pow2(int n) {
	int x = 1; 
	for (int i = 0; i < n; i++) x *= 2;
	return x;
}
int main(int argc, char *argv[]) {

	int n;
	while (cin >> n) {
		int size = pow2(n);
		vector<int> weights (size);
		for (int i = 0; i < size; i++) cin >> weights[i];
		int max = 0;
		for (int i = 0; i < size; i++) {
			int sum = 0;
			for (int d = 0; d < n; d++) {
				int index = (1 << d) ^ i;
				sum += weights[index];
			}
			int maxn = 0;
			for (int j = 0; j < n; j++) {
				int newi = (1 << j) ^ i, newsum = 0;
				for (int d = 0; d < n; d++) {
					int newindex = (1 << d) ^ newi;
					newsum += weights[newindex];
				}
				if (newsum > maxn) maxn = newsum;
			}
			sum += maxn;
			if (sum > max) max = sum;
		}
		cout << max << endl;
	}
}