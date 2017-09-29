#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1; true; c++) {
		int n;
		cin >> n;
		if (n == 0) break;
		int sum = 0;
		vector<int> heights (n);
		for (int i = 0; i < n; i++) {
			cin >> heights[i];
			sum += heights[i];
		}
		int mean = sum / n;
		int nmoves = 0;
		for (int i = 0; i < n; i++) {
			nmoves += abs(heights[i] - mean);
		}
		cout << "Set #" << c << endl;
		cout << "The minimum number of moves is " << nmoves/2 << ".\n\n";
	}
}