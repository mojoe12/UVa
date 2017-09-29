#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int todecimal(string s) {
	int n = s.size();
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int digit = s[i] - '0';
		ret += (pow(2, n-i) - 1) * digit;
	}
	return ret;
}


int main() {
	
	while (true) {
		string n;
		cin >> n;
		if (n == "0") break;
		
		cout << todecimal(n) << endl;
	}




}


