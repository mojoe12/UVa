#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool if7 (int i) {
	if (i % 7 == 0) return true;
	if (i / 10000 == 7) return true;
	if (i % 10000 / 1000 == 7) return true;
	if (i % 1000 / 100 == 7) return true;
	if (i % 100 / 10 == 7) return true;
	if (i % 10 == 7) return true;
	return false;
}


int main() {
	
	int n, m, k;
	while (cin >> n >> m >> k) {
		if (!n && !m && !k) break;
		
		int counter = 0, cp = 1, cnum = 1;
		bool direction = true; // right
		while (counter < k) {
			
			if (cp == m && if7(cnum)) counter++;
			
			if (direction && cp == n) direction = false;
			if (!direction && cp == 1) direction = true;
			
			if (direction) cp++;
			else cp--;
			cnum++;
			
		}
		cout << cnum-1 << endl;
	}
}

// function definitions

