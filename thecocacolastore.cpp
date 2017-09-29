#include <iostream>

using namespace std;

int sum (int n, int e) {
	if (!n) return 0;
	return n + sum( (n+e)/3, (n+e)%3 );
}

int main() {
	int e;
	while (cin >> e) {
		if (!e) break;
		int n = e / 3 + e % 3;
		cout << sum(e / 3, e % 3 + 2 * (1 - n % 2)) << endl;
	}
}