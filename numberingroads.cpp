#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1; true; c++) {
		int s, n;
		cin >> s >> n;
		if (s == 0 || n == 0) break;
		int x = ceil((double)s / n) - 1;
		cout << "Case " << c << ": ";
		if (x > 26) cout << "impossible" << endl;
		else cout << x << endl;
	}
}