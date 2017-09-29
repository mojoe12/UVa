#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n, k;
	while (cin >> n >> k) {
		int nbutts = n, nsmokes = n;
		while (nbutts >= k) {
			int add = nbutts / k;
			nsmokes += add;
			nbutts = add + nbutts % k;
		}
		cout << nsmokes << endl;
	}
}