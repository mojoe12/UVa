#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

string tostr (int n) {
	string s = "";
	while (n) {
		string s1 = "";
		char c = '0' + n % 10;
		s1 += c;
		s = s1 + s;
		n /= 10;
	}
	//s = "0" + s;
	return s;
}

int main() {
	
	const int ssize = 31268;
	vector<int> starts (ssize);
	starts[0] = 0;
	for (int k = 1; k < ssize; k++) {
		int addition = 0;
		if (k < 10) addition = k;
		else if (k < 100) addition = 9 + 2 * (k - 9);
		else if (k < 1000) addition = 189 + 3 * (k - 99);
		else if (k < 10000) addition = 2889 + 4 * (k - 999);
		else if (k < 100000) addition = 38889 + 5 * (k - 9999);
		starts[k] = starts[k-1] + addition;
	}
	
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int>::iterator ub = upper_bound(starts.begin(), starts.end(), n-1);
		ub--;
		int dist = n - *ub;
		int i = 1;
		for (int counter = 0; true; i++) {
			counter += floor(log10(i)) + 1;
			if (counter >= dist) {
				int newdist = counter - dist;
				string s = tostr(i);
				cout << s[s.length() - newdist - 1] << endl;
				break;
			}
		}
	}




}


