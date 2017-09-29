#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n, j, p;
		cin >> n >> j >> p;
		for (int i = 0; i < p; i++) {
			j++;
			if (j > n) j = 1;
		}
		cout << "Case " << c << ": " << j << endl;
	}
}