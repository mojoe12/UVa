#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool powerof2 (int x) {
	while (x > 1) {
		if (x & 1) return false;
		x = x >> 1;
	}
	return x == 1;
}

int main() {
	
	while (true) {
		int x;
		cin >> x;
		cout << powerof2(x) << endl;
	}



}


