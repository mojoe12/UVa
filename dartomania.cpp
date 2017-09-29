#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool ifok (int i) {
	if (i == 50 || i <= 20) return true;
	if (i > 40) return i % 3 == 0;
	return i % 2 == 0 || i % 3 == 0;
}

int main() {
	
	int score;
	while (cin >> score) {
		if (score <= 0) break;
		
		int perms = 0, combs = 0;
		
		for (int i = 0; i <= 60; i++) {
			if (!ifok(i)) continue;
			for (int j = i; j <= 60; j++) {
				if (!ifok(j)) continue;
				for (int k = j; k <= 60; k++) {
					if (!ifok(k)) continue;
					if (i + j + k == score) {
						combs++;
						if (i == j && j == k) perms++;
						else if (i == j || j == k || i == k) perms += 3;
						else perms += 6;
					}
				}
			}
		}
		
		if (combs) {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << combs << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perms << ".\n";
		}
		else cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
		cout << "**********************************************************************\n";
	}

	cout << "END OF OUTPUT\n";


}


