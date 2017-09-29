#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		int ans = 1 + floor(sqrt(b)) - ceil(sqrt(a));
		cout << ans << endl;
	}
}