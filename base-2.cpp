#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

string tonega (int n) {
	string s = "";
	while (n) {
		string news = "";
		news += '0' + n % 2;
		s = news + s;
		n /= -2;
	}
	return s;
}


int main() {
	
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		cout << "Case #" << c << ": ";
		cout << tonega(n) << endl;
	}




}


