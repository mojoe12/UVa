#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {
	
	int x;
	while (cin >> x) {
		int y = 0;
		for (int i = 0; i < 4; i++) {
			y = (y << 8) | (255 & (x >> (8*i)) );
		}
		cout << x << " converts to " << y << endl;
	}



}


