#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n, b;
		cin >> n >> b;
		if (n == 0 && b == 0) break;
		vector<int> nums (b);
		for (int i = 0; i < b; i++) cin >> nums[i];
		bitset<128> bits;
		bits.reset();
		for (int i = 0; i < b; i++) {
			for (int j = i; j < b; j++) {
				bits[abs(nums[i] - nums[j])] = true;
			}
		}
		bool ifalltrue = true;
		for (int i = 0; i <= n; i++) {
			ifalltrue = ifalltrue && bits[i];
		}
		if (ifalltrue) cout << "Y\n";
		else cout << "N\n";
	}
}