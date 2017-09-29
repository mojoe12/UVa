#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	while (cin >> n) {
		vector <int> ifused (n);
		fill(ifused.begin(), ifused.end(), 0);
		int previous = 0;
		cin >> previous;
		for (int i = 1; i < n; i++) {
			int current = 0;
			cin >> current;
			int diff = abs(current - previous);
			if (diff < n && diff > 0) ifused[diff] = 1;
			previous = current;
		}
		bool ifjolly = true;
		for (int i = 1 ; i < n; i++) ifjolly = ifjolly && ifused[i];
		if (ifjolly) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}