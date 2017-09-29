#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
	}
}