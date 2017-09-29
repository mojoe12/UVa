#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		int beststreak = 0, currentstreak = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			beststreak = max(beststreak, x + currentstreak);
			if (currentstreak + x < 0) currentstreak = 0;
			else currentstreak += x;
			
		}
		if (beststreak < 1) cout << "Losing streak.\n";
		else cout << "The maximum winning streak is " << beststreak << ".\n";

	}




}


