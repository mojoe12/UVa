#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string str;
	getline(cin, str);
	for (int c = 0; c < k; c++) {
		getline(cin, str);
		int l = str.length();
		int s = floor(sqrt(l));
		if (s != sqrt(l) ) {
			cout << "INVALID\n";
			continue;
		}
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				cout << str[j * s + i];
			}
		}
		cout << endl;
	}
}