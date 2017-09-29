#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

string tobase (int n, int b) {
	string s = "";
	while (n) {
		string news = "";
		news += '0' + n % b;
		s = news + s;
		n /= b;
	}
	return s;
}

int tonum (string n, int b) {
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		sum = sum * b + (n[i] - '0');
	}
	return sum;
}


int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int b1, b2, r1, r2;
		cin >> b1 >> b2 >> r1 >> r2;
		
		int num = 0;
		for (int r = r2-1; r > r1; r--) 
		{
			string rb1 = tobase(r, b1);
			int rb1b2 = tonum(rb1, b2);
			//cout << r << ' ' << rb1 << ' ' << rb1b2 << endl;
			
			if (rb1b2 % r == 0) {
				num = r;
				break;
			}
		}
		if (num) cout << num << endl;
		else cout << "Non-existent.\n";
	}




}


