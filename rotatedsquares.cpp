#include <iostream>
#include <vector>
using namespace std;

vector<string> rotate (vector<string> vec) {
	int n = vec.size();
	vector<string> ret (n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ret[i] += '0';
	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) {
			ret[b][n-a-1] = vec[a][b];
		}
	}
	return ret;
}

int count (vector<string> big, vector<string> fit) {
	int f = fit.size(), b = big.size(), num = 0;
	for (int si = 0; si <= b - f; si++) {
		for (int sj = 0; sj <= b - f; sj++) {
			bool ifsame = true;
			for (int i = 0; i < f; i++) {
				for (int j = 0; j < f; j++) {
					if (big[si+i][sj+j] != fit[i][j]) ifsame = false;
				}
			}
			if (ifsame) num++;
		}
	}
	return num;
}

int main(int argc, char *argv[]) {
	while (true) {
		int b, f;
		cin >> b >> f;
		if (b == 0 && f == 0) break;
		vector<string> big (b), fit (f);
		for (int i = 0; i < b; i++) cin >> big[i];
		for (int i = 0; i < f; i++) cin >> fit[i];
		
		for (int i = 0; i < 4; i++) {
			if (i) cout << " ";
			cout << count(big, fit);
			fit = rotate(fit);
		}
		cout << endl;
	}
}