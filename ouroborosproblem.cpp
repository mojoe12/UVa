#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>


using namespace std;

// function declarations

int power (int b, int e);
int getnum (string substring, int b);
void getouroboros(string& s, vector<bool>& ifused, int count, int n, int b, bool& ready);

int main() {
	
	// setup input


	// loop through it, apply function
	
	int n, b;
	while (cin >> n >> b) {
		string s (n, '0');
		vector<bool> ifused (power(b, n));
		ifused[0] = true;
		
		bool ready = false;
		
		getouroboros(s, ifused, 0, n, b, ready);
		
		cout << s << endl;
		
	}


	// output answer


}

// function definitions

int power (int b, int e) {
	int num = 1;
	for (int i = 0; i < e; i++) num *= b;
	return num;
}

int getnum (string substring, int b) {
	int sum = 0;
	for (int i = 0; i < substring.length(); i++) {
		sum = b * sum + (substring[i] - '0');
	}
	return sum;
}

void getouroboros(string& s, vector<bool>& ifused, int count, int n, int b, bool& ready) {
	//cout << s << endl;
	
	int sl = s.length();
	if (count == ifused.size()) ready = true;
	if (ready) return;
	
	if (ifused.size() - count <= n) {
		
		for (int i = 1; i < n; i++) {
			string substring = s.substr(sl - i, i);
			substring = substring + s.substr(0, n-i);
			ifused[getnum(substring, b)] = true;
		}
		if (find(ifused.begin(), ifused.end(), false) == ifused.end()) {
			ready = true;
			return;
		}
		for (int i = 1; i < n; i++) {
			string substring = s.substr(sl - i, i);
			substring = substring + s.substr(0, n-i);
			ifused[getnum(substring, b)] = true;
		}
	}
	
	string ssubstring = s.substr(sl-n+1, n-1);
	//cout << ssubstring << endl;
	for (int i = 0; i < b; i++) {
		ssubstring += ('0' + i);
		int num = getnum(ssubstring, b);

		if (!ifused[num]) {
			s += ('0' + i);
			ifused[num] = true;
			
			getouroboros(s, ifused, count+1, n, b, ready);
			if (ready) return;
			s.pop_back();
			ifused[num] = false;
		}
		ssubstring.pop_back();
	}
}
























