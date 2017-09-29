#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int n; cin >> n;
		int max = 0;
		for (int j = 0; j < n; j++) {
			int speed;
			cin >> speed;
			if (speed > max) max = speed;
		}
		cout << "Case " << i << ": " << max << endl;
	}
}