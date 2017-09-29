#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		int milecost = 0, juicecost = 0;
		for (int i = 0; i < n; i++) {
			int duration;
			cin >> duration;
			milecost += 10 * (1 + (duration / 30));
			juicecost += 15 * (1 + (duration / 60));
		}
		if (milecost < juicecost) {
			cout << "Case " << c << ": Mile " << milecost << endl;
		}
		else if (juicecost < milecost) {
			cout << "Case " << c << ": Juice " << juicecost << endl;
		}
		else {
			cout << "Case " << c << ": Mile Juice " << juicecost << endl;
		}
	}
}