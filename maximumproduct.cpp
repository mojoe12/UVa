#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	
	vector<long long> maxims;
	for (int c = 1; cin >> n; c++) {
		vector<long long> finalNums;
		finalNums.push_back(0);
		vector<long long> currentNums;
		currentNums.push_back(1);
		
		bool usethis = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x > 0) {
				usethis = true;
				for (int j = 0; j < currentNums.size(); j++) {
					currentNums[j] *= x;
				}
			}
			else if (x == 0) {
				finalNums.insert(finalNums.end(), currentNums.begin(), currentNums.end());
				currentNums = vector<long long> (0);
				currentNums.push_back(1);
			}
			else if (x < 0) {
				finalNums.insert(finalNums.end(), currentNums.begin(), currentNums.end());
				for (int j = 0; j < currentNums.size(); j++) {
					currentNums[j] *= x;
				}
				currentNums.push_back(1);
			}
		}
		long long maxim = *max_element(currentNums.begin(), currentNums.end());
		maxim = max(maxim, *max_element(finalNums.begin(), finalNums.end()));
		if (maxim == 1 && !usethis) maxim = 0;
		maxims.push_back(maxim);
	}
	for (int i = 0; i < maxims.size(); i++) {
		cout << "Case #" << i+1 << ": The maximum product is ";
		cout << maxims[i] << '.' << endl << endl;
	}
}