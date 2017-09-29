#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int x = 1; x <= k; x++) {
		int a, b;
		cin >> a >> b;
		int c = a/2, d = (b-1)/2;
		int sum = (d+1+c) * (d+1-c);
		cout << "Case " << x << ": ";
		cout << sum << endl;
	}
}