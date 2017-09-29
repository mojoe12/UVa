#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int tonum (string s, char c, int b) 
{
	int sum = 0; 
	for (int i = 0; i < s.length(); i++) {
		int dig = s[i] - c;
		sum = b * sum + dig;
	}
	return sum;
}



int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c  < k; c++) {
		string s;
		cin >> s;
		int a = tonum(s.substr(0, 3), 'A', 26);
		int b = tonum(s.substr(4, 4), '0', 10);
		bool ifnice = abs(a-b) <= 100;
		if (!ifnice) cout << "not ";
		cout << "nice\n";
	}




}


