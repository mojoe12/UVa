#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	int n, m;
	while (cin >> n) {
		if (n) cin >> m;
		else break;
		
		vector<vector<bool> > positions (n, vector<bool> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				positions[i][j] = (c == '1');
			}
		}
		
		int count = 0;
		// start at the top left and work your way down
		for (int tlx = 0; tlx < n; tlx++) {
			for (int tly = 0; tly < m; tly++) {
				for (int brx = tlx; brx < n; brx++) {
					for (int bry = tly; bry < m; bry++) {
						bool ifok = true;
						for (int i = tlx; ifok && i <= brx; i++) {
							for (int j = tly; ifok && j <= bry; j++) {
								ifok = positions[i][j];
							}
						}
						
						if (ifok) count++;
					}
				}
			}
		}
		cout << count << endl;
		
	}
}