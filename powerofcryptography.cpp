#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int root (double b, int r) {
	return round(pow(b, 1.0/r));
}


int main() {
	
	int n;
	double p;
	while (cin >> n >> p) {
		cout << root(p, n) << endl;
	}



}


