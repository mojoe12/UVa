#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	bool toprint = false;
	for(int c = 1; true; c++) {
		int nreqs, nprops;
		cin >> nreqs >> nprops;
		if (nreqs == 0 && nprops == 0) break;
		if (toprint) cout << endl;
		else toprint = true;
		string blank;
		for (int i = 0; i <= nreqs; i++) getline(cin, blank);
		float mincost = 1000000.00;
		int mostreqs = 0;
		string bestname = "";
		for (int i = 0; i < nprops; i++) {
			string name;
			getline(cin, name);
			int checks;
			float cost;
			cin >> cost >> checks;
			for (int j = 0; j <= checks; j++) getline(cin, blank);
			if (checks > mostreqs) {
				mostreqs = checks;
				mincost = cost;
				bestname = name;
			}
			if (checks == mostreqs && cost < mincost) {
				mincost = cost;
				bestname = name;
			}
		}
		cout << "RFP #" << c << endl << bestname << endl;
	}
}