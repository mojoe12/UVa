#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	for (int c = 1; s != ""; c++) {
		int size = (s.length() + 1) / 3;
		vector<int> cycles (size);
		for (int i = 0; i < size; i++) {
			cycles[i] = 10 * (s[3*i] - '0') + s[3*i+1] - '0';
		}
		
		int time = *min_element(cycles.begin(), cycles.end()) - 5;
		for (; time <= 3600; time++) {
			bool ifgreen = true;
			for (int i = 0; ifgreen && i < size; i++) {
				int x = time % (2 * cycles[i]);
				ifgreen = ifgreen && x < cycles[i] - 5;
			}
			if (ifgreen) break;
		}
		
		if (time > 3600) cout << "Set " << c << " is unable to synch after one hour.\n";
		else {
			cout << "Set " << c << " synchs again at " << time / 60;
			cout << " minute(s) and " << time % 60 << " second(s) after all turning green.\n";
		}
		getline(cin, s);
	}
}