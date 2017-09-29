#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		int clog2 = ceil(log2(n));
		int nc = n + clog2 - 2;
		cout << nc << endl;
	}


}


