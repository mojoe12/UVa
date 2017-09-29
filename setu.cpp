#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		string action;
		cin >> action;
		if (action == "report") cout << sum << endl;
		else if (action == "donate") {
			int donation;
			cin >> donation;
			sum += donation;
		}
	}
}