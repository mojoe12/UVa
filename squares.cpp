#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool isSquare (string s, int b) {
	int n = s.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int digit = s[i] - '0';
		if (digit >= b) return false;
		sum = b * sum + digit;
	}
	int sqrroot = sqrt(sum);
	return sqrroot * sqrroot == sum;
}


int main() {
	
	
	while (true) {
		string s;
		cin >> s;
		if (s == "0") break;
		
		int i = 2;
		while (!isSquare(s, i)) {
			i++;
		}
		
		cout << i << endl;
	}




}


