#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		int numhigh = 0, numlow = 0;
		int currentheight;
		cin >> currentheight;
		for (int i = 1; i < n; i++) {
			int nextheight;
			cin >> nextheight;
			if (nextheight > currentheight) numhigh++;
			else if (nextheight < currentheight) numlow++;
			currentheight = nextheight;
		}
		cout << "Case " << c << ": " << numhigh << " " << numlow << endl;
	}
}