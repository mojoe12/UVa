#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	for (int c = 1; cin >> n; c++) {
		if (n < 0) break;
		int ans = ceil(log2(n));
		cout << "Case " << c << ": " << ans << endl;
	}
}


