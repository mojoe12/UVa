#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

char output (int d) {
	switch (d) {
		case 0: return ' ';
		case 1: return '.';
		case 2: return 'x';
		default: return 'W';
	}
}


int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		
		vector<int> changes (10);
		for (int i = 0; i < 10; i++) cin >> changes[i];
		
		vector<int> dishes (40, 0);
		dishes[19] = 1;
		for (int d = 0; d < 50; d++) {
			
			for (int i = 0; i < 40; i++) cout << output(dishes[i]);
			cout << endl;
			
			vector<int> newdishes (40);
			for (int i = 0; i < 40; i++) {
				int sum = dishes[i];
				if (i > 0) sum += dishes[i-1];
				if (i < 39) sum += dishes[i+1];
				newdishes[i] = changes[sum];
			}
			
			dishes = newdishes;
		}
	}




}


