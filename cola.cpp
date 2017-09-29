#include <iostream>

using namespace std;

int sum (int n, int e) {
	if (!n) return 0;
	return n + sum( (n+e)/3, (n+e)%3 );
}
int main() {
	int n;
	while (cin >> n) {
		cout << sum(n, 2 * (1 - n % 2)) << endl;
	}
}