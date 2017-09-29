#include <iostream>
#include <map>
#include <cmath>
using namespace std;

bool isPrime (int n) {
	if (n == 1) return false;
	for (int i = 2; i <= floor(sqrt(n)); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	
	int k;
	cin >> k;
	
	string s;
	for (int c = 0; c < k; c++) {
		cin >> s;
		
		map<char, int> mp;
		for (int i = 0; i < s.length(); i++) {
			if (mp.count(s[i])) mp[s[i]]++;
			else mp.insert( pair<char, int> (s[i], 1));
		}
		
		cout << "Case " << c+1 << ": ";
		typedef map<char, int>::iterator it_type;
		bool ifused = false;
		for (it_type it = mp.begin(); it != mp.end(); it++) {
			if (isPrime(it -> second)) {
				cout << (it -> first);
				ifused = true;
			}
		}
		if (!ifused) cout << "empty";
		cout << endl;
	}
}