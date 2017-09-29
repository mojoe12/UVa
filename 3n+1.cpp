#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int i, j;
	while (cin >> i >> j) {
		string print = to_string(i) + " " + to_string(j) + " ";
		int max = 0;
		if (i > j) {
			int temp = j;
			j = i;
			i = temp;
		}
		for (int k = i; k <= j; k++) {
			int num = k;
			int l = 1;
			while (num != 1) {
				l++;
				if (num % 2 == 0) num /= 2;
				else num = num * 3 + 1;
			}
			if (l > max) max = l;
		}
		cout << print << max << endl;
	}
}