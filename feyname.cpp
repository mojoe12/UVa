#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += (n - i + 1) * (n - i + 1);
		}
		cout << sum << endl;
	}
}