#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



int main() {
	/*
	int leftside = h * (h-1) / 2;
	int rightside = l * (l+1) / 2 - leftside - h;
	leftside = rightside;
	2h^2 = l * (l+1)
	*/
	
	int counter = 0;
	for (long long h = 2; counter < 10; h++) {
		long long leftside = 2*h*h;
		for (long long l = sqrt(leftside); counter < 10; l++) {
			if (l*l + l > leftside) break;
			if (l*l + l == leftside) {
				counter++;
				cout.width(10);
				cout << right << h;
				cout.width(10);
				cout << right << l << endl;
			}
		}
	}




}


