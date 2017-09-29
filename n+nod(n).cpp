#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int numdiv (int n) {
	if (n == 1) return 1;
	int count = 2;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) count += 2;
	}
	int x = sqrt(n);
	if (x * x == n) count++;
	return count;
}


int main() {
		
	vector<int> numbers (65000);
	numbers[0] = 1;
	numbers[1] = 2;
	for (int i = 2; i < 65000; i++) {
		numbers[i] = numbers[i-1] + numdiv(numbers[i-1]);
	}

	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int a, b;
		cin >> a >> b;
		int num = upper_bound(numbers.begin(), numbers.end(), b) - lower_bound(numbers.begin(), numbers.end(), a);
		cout << "Case " << c << ": " << num << endl;
	}
}