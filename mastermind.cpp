#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool contains(vector<int> vec, int item) {
	return find(vec.begin(), vec.end(), item) != vec.end();
}

int main(int argc, char *argv[]) {
	for (int c = 1; true; c++) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> code (n);
		for (int i = 0; i < n; i++) cin >> code[i];
		cout << "Game " << c << ":\n";
		while (true) {
			int strong = 0;
			vector<int> strongs (0);// for guess
			vector<int> weaks (0); // for code
			vector<int> guess (n);
			
			for (int i = 0; i < n; i++) {
				cin >> guess[i];
				if (guess[i] == code[i]) {
					strong++;
					strongs.push_back(i);
					weaks.push_back(i);
				}
			}

			if (guess[0] == 0) break;
			int weak = 0;
			for (int i = 0; i < n; i++) {
				if (contains(strongs, i)) continue;
				for (int j = 0; j < n; j++) {
					if (contains(weaks, j)) continue;
					if (guess[i] == code[j]) {
						weaks.push_back(j);
						weak++;
						break;
					}
				}
			}
			cout << "    (" << strong << ',' << weak << ")\n";
		}
	}
}