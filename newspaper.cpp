#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<char> chars (n);
		vector<int> prices (n);
		for (int i = 0; i < n; i++) {
			cin >> chars[i];
			cin >> prices[i];
		}
		int nl;
		cin >> nl;
		string input;
		getline(cin, input);
		int sumcents = 0;
		for (int i = 0; i < nl; i++) {
			string input;
			getline(cin, input);
			for (int i = 0; i < input.length(); i++) {
				char c = input[i];
				for (int j = 0; j < chars.size(); j++) {
					if (c == chars[j]) {
						sumcents += prices[j];
						break;
					}
				}
			}
		}
		cout << fixed << setprecision(2);
		cout << sumcents / 100.0 << "$\n";
	}
}