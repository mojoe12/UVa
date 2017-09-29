#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		double sum = 0;
		for (int i = 1; i <= n; i++) sum += log10(i);
		int numdigs = 1 + floor(sum);
		cout << numdigs << endl;

	}




}


