#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int c = 1; ; c++) {
		int a, lim;
		cin >> a >> lim;
		if (a < 0 && lim < 0) break;
		int t = 0;
		int num = a;
		do {
			t++;
			if (num % 2 && num >= (lim-1)/3 ) break;
			num = (num % 2) ? 3*num+1 : num/2;
		} while (num <= lim && num != 1);
		if (num == 1) t++;
		cout << "Case " << c;
		cout << ": A = " << a;
		cout << ", limit = " << lim;
		cout << ", number of terms = " << t << endl;
	}
}