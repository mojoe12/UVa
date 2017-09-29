#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < k; i++) {
		bool ifordered = true, ifbw = false;
		int previous;
		cin >> previous;
		int n;
		cin >> n;
		if (n < previous) ifbw = true;
		previous = n;
		for (int j = 2; j < 10; j++) {
			cin >> n;
			if ((n < previous && !ifbw) || 
(n > previous && ifbw)) ifordered = false;
			previous = n;
		}
		string start = (ifordered) ? "O" : "Uno";
		cout << start << "rdered" << endl;
	}
}