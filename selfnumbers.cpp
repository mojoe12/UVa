#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

int d(int n) {
	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	
	bitset<1000000> isSelf;
	isSelf.reset();
	
	for (int i = 1; i < 1000000; i++) {
		isSelf[d(i)-1] = true;
	}
	
	for (int i = 0; i < 1000000; i++) {
		if (!isSelf[i]) cout << i+1 << endl;
	}



}


