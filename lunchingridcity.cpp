#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int ns, na, f;
		cin >> ns >> na >> f;
		vector<int> streets (f), avenues (f);
		for (int i = 0; i < f; i++) {
			cin >> streets[i];
			cin >> avenues[i];
		}
		
		sort(streets.begin(), streets.end());
		sort(avenues.begin(), avenues.end());
		
		int bests = streets[(streets.size()-1)/2];
		int besta = avenues[(avenues.size()-1)/2];
		
		cout << "(Street: " << bests;
		cout << ", Avenue: " << besta << ")\n";
	}
}