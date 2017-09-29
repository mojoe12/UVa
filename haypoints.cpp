#include <iostream>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int m, n;
	cin >> m >> n;
	map<string, double> mp;
	for (int i = 0; i < m; i++) {
		
		string word;
		double n;
		cin >> word >> n;
		mp.insert( make_pair(word, n) );
		
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		string word;
		while (cin >> word) {
			if (word == ".") break;
			else if (mp.count(word)) sum += mp[word];
		}
		cout << sum << endl;
		
	}
}