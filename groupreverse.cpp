#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int g;
		cin >> g;
		if (g == 0) break;
		string input;
		cin >> input;
		int cpg = input.length() / g;
		for (int i = 0; i < g; i++) {
			for (int j = (i + 1) * cpg - 1; j >= i * cpg; j--) {
				cout << input[j];
			}
		}
		cout << endl;
	}
}