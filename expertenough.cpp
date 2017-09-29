#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		int d;
		cin >> d;
		vector<string> names (d);
		vector< pair<int, int> > prices (d);
		for (int i = 0; i < d; i++) {
			cin >> names[i] >> prices[i].first >> prices[i].second;
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int p;
			cin >> p;
			int count = 0;
			string name;
			for (int j = 0; count < 2 && j < d; j++) {
				if (p >= prices[j].first && p <= prices[j].second) {
					if (count) count++; 
					else count = 1;
					name = names[j];
				}
			}
			if (count != 1) cout << "UNDETERMINED\n";
			else cout << name << endl;
		}
	}
}