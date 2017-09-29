#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> sales (n);
		for (int i = 0; i < n; i++) cin >> sales[i];
		
		int sum = 0;
		for (int i = 1; i < n; i++) {
			int x = sales[i];
			sum += count_if(sales.begin(), sales.begin() + i, [x] (int s) {return s <= x;});
		}
		cout << sum << endl;
	}
}