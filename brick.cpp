#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		int answer = 0;
		int x;
		for (int i = 0; i < n; i++) { 
			cin >> x;
			if (i == (n/2)) answer = x;
		}
		cout << "Case " << c << ": " << answer << endl;
	}
}