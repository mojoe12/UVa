#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int sum = n;
		while (sum >= 10) {
			int newsum = 0;
			int sumcut = sum;
			while (sumcut > 0) {
				newsum += sumcut % 10;
				sumcut /= 10;
			}
			sum = newsum;
		}
		cout << sum << endl;
	}
}