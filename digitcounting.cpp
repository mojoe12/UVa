#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> digcounts (10);
		for (int i = 0; i < 10; i++) digcounts[i] = 0;
		for (int i = 1; i <= n; i++) {
			int num = i;
			int numdigs = floor(log10(num))+1;
			int dig = num % 10;
			digcounts[dig]++;
			num /= 10;
			dig = num % 10;
			if (dig != 0 || numdigs > 2) digcounts[dig]++;
			num /= 10;
			dig = num % 10;
			if (dig != 0 || numdigs > 3) digcounts[dig]++;
			num /= 10;
			dig = num % 10;
			if (dig != 0 || numdigs > 4) digcounts[dig]++;
		}
		for (int i = 0; i < 9; i++) cout << digcounts[i] << ' ';
		cout << digcounts[9] << endl;
	}
}