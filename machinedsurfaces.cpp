#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> numBs (n);
		string input;
		getline(cin, input);
		for (int i = 0; i < n; i++) {
			getline(cin, input);
			numBs[i] = count(input.begin(), input.end(), ' ');
		}
		int min = *min_element(numBs.begin(), numBs.end());
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += numBs[i] - min;
		}
		cout << sum << endl;
	}
}