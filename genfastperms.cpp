#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string input;
		cin >> input;
		sort(input.begin(), input.end()); // lol idk
		do {
			cout << input << endl;
		} while (next_permutation(input.begin(), input.end()));
		cout << endl;
	}
}