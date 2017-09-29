#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ifsame(vector<string> a, vector<string> b, bool &iff) {
	bool ifsame = true;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			ifsame = ifsame && a[i][j] == b[i][j];
		}
	}
	if (ifsame) iff = true;
	return ifsame;
}

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

int main(int argc, char *argv[]) {
	int n;
	for (int c = 1; cin >> n; c++) {
		vector<string> before (n), after (n);
		for (int i = 0; i < n; i++) {
			cin >> before[i] >> after[i];
		}
		
		bool same = false;
		if (ifsame(after, before, same)) cout << "Pattern " << c << " was preserved.\n";
		if (same) continue;
		
		vector<string> rotated = before;
		for (int i = 0; i < 3 && !same; i++) {
			rotated = rotate(rotated);	
			if (ifsame(after, rotated, same)) cout << "Pattern " << c << " was rotated " << 90 * (i+1) << " degrees.\n";
		}
		if (same) continue;
		
		vector<string> reflected (n);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) reflected[i] += '0';
		for (int b = 0; b < n; b++) {
			for (int a = 0; a < n; a++) {
				reflected[a][b] = before[n - a - 1][b];
			}
		}
		if (ifsame(after, reflected, same)) cout << "Pattern " << c << " was reflected vertically.\n";
		
		for (int i = 0; i < 3 && !same; i++) {
			reflected = rotate(reflected);
			if (ifsame(after, reflected, same)) cout << "Pattern " << c << " was reflected vertically and rotated " << 90 * (i+1) << " degrees.\n";
		}
		if (!same) cout << "Pattern " << c << " was improperly transformed.\n";
	}
}