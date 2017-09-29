#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1;; c++) {
		int n;
		cin >> n;
		if (n == 0) break;
		int balance = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 0) balance--;
			else balance++;
		}
		cout << "Case " << c << ": " << balance << endl;
	}
}