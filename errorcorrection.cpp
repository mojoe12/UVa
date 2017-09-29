#include <iostream>
#include <vector>
using namespace std;
bool ifeven (vector < vector<int> > bits, int size);
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector < vector<int> > bits (n, vector<int> (n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c == ' ') cin >> c;
				bits[i][j] = c - '0';
			}
		}
		if (ifeven(bits, n)) {
			cout << "OK\n";
			continue;
		}
		bool fixable = false;
		for (int i = 0; i < n && !fixable; i++) {
			for (int j = 0; j < n && !fixable; j++) {
				if (bits[i][j]) bits[i][j]--;
				else bits[i][j]++;
				if (ifeven(bits, n)) {
					cout << "Change bit (" << i+1 << ',' << j+1 << ")\n";
					fixable = true;
				}
				if (bits[i][j]) bits[i][j]--;
				else bits[i][j]++;
			}
		}
		if (!fixable) cout << "Corrupt\n";
	}
}

bool ifeven (vector < vector<int> > bits, int size) {
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += bits[i][j];
		}
		if (sum % 2) return false;
	}
	for (int j = 0; j < size; j++) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += bits[i][j];
		}
		if (sum % 2) return false;
	}
	return true;
}