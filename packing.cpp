#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		bool ok = true;
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			if (x > 20) ok = false;
		}
		string s = (ok) ? "good" : "bad";
		cout << "Case " << i << ": " << s << endl;
	}
}