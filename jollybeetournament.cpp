#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int nrounds, nmissing;
		cin >> nrounds >> nmissing;
		int nplayers = 1 << nrounds;
		bitset<1024> players;
		players.set();
		for (int i = 0; i < nmissing; i++) {
			int misser;
			cin >> misser;
			players[misser-1] = false;
		}
		// 1 is a person
		// 0 is no person
		int count = 0;
		for (int round = nrounds; round > 0; round--) {
			for (int i = 0; i < (1 << round); i += 2) {
				bool a = players[i], b = players[i+1];
				if (a xor b) count++;
				players[i/2] = a || b;
			}
		}
		cout << count << endl;
	}
}