#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int n, d;
	while (cin >> n >> d) {
		vector<int> bs;
		while (n && d) {
			bs.push_back(n / d);
			n %= d;
			swap(n, d);
		}
		cout << '[' << bs[0] << ';';
		for (int i = 1; i < bs.size()-1; i++) {
			cout << bs[i] << ',';
		}
		cout << bs[bs.size()-1] << "]\n";
	}
}