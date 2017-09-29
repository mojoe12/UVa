#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		string best = "";
		int bestrank = 0;
		for (int i = 0; i < 10; i++) {
			string wsi;
			cin >> wsi;
			int rank;
			cin >> rank;
			if (rank > bestrank) {
				bestrank = rank;
				best = wsi;
			}
			else if (rank == bestrank) {
				best += "\n";
				best += wsi;
			}
		}
		cout << "Case #" << c << ":" << endl <<  best << endl;
	}
}