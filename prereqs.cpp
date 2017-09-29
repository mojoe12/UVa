#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int ncors, ncats;
		cin >> ncors;
		if (ncors == 0) break;
		cin >> ncats;
		vector<int> cors (ncors);
		for (int i = 0; i < ncors; i++) cin >> cors[i];
		bool ifok = true;
		for (int i = 0; i < ncats; i++) {
			int current = 0;
			int total, needed;
			cin >> total >> needed;
			for (int j = 0; j < total; j++) {
				int course;
				cin >> course;
				for (int k = 0; k < ncors; k++) {
					if (course == cors[k]) current++;
				}
			}
			if (current < needed) ifok = false;
		}
		if (ifok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}