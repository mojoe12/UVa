#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	vector<string> input;
	string s;
	while (getline(cin, s)) {
		input.push_back(s);
	}
	int maxl = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i].length() > maxl) maxl = input[i].length();
	}
	for (int i = 0; i < maxl; i++) {
		for (int j = input.size()-1; j >= 0; j--) {
			if (i < input[j].length()) cout << input[j][i];
			else if (j > 0) cout << ' ';
		}
		cout << endl;
	}
}