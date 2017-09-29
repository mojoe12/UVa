#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1; true; c++) {
		int s;
		cin >> s;
		if (s < 0) break;
		vector<int> creations (12);
		for (int i = 0; i < 12; i++) cin >> creations[i];
		cout << "Case " << c << ":\n";
		
		int currentnum = s;
		for (int i = 0; i < 12; i++) {
			int required;
			cin >> required;
			if (required > currentnum) cout << "No problem. :(\n";
			else {
				cout << "No problem! :D\n";
				currentnum -= required;
			}
			currentnum += creations[i];
		}
	}
}