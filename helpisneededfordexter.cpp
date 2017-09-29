#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	while (cin >> n) {
		int ans = ceil(log2(n+1));
		cout << ans << endl;
	}
}


