#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>&, vector< vector<int> >&, vector<int>&, int, int, int);
bool comp(vector<int> i, vector<int> j);
bool ifsame(vector<int> i, vector<int> j);

int main() {
	
	int sum, n;
	while (cin >> sum >> n) {
		if (!sum && !n) break;
		
		vector<int> nums(n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		
		vector< vector<int> > psums;
		vector<int> csums;
		backtrack(nums, psums, csums, 0, 0, sum);
		
		for (int i = 0; i < psums.size(); i++) {
			sort(psums[i].begin(), psums[i].end(), greater<int>());
		}
		sort(psums.begin(), psums.end(), comp);
		
		for (int i = 1; i < psums.size(); i++) {
			if (ifsame(psums[i-1], psums[i])) {
				psums[i-1] = vector<int>();
			}
		}
		
		cout << "Sums of " << sum << ":\n";
		for (int i = 0; i < psums.size(); i++) {
			if (!psums[i].size()) continue;
			cout << psums[i][0];
			for (int j = 1; j < psums[i].size(); j++) {
				cout << '+' << psums[i][j];
			}
			cout << endl;
		}
		if (!psums.size()) cout << "NONE\n";
		
	}
}

void backtrack(vector<int>& nums, vector< vector<int> >& psums, vector<int>& csums, int cindex, int csum, int isum) {
	
	if (csum == isum) {
		psums.push_back(csums);
		return;
	}
	
	if (cindex == nums.size()) return;
	
	backtrack(nums, psums, csums, cindex+1, csum, isum);
	csums.push_back(nums[cindex]);
	backtrack(nums, psums, csums, cindex+1, csum + nums[cindex], isum);
	csums.pop_back();
	
}

bool comp(vector<int> i, vector<int> j) {
	for (int x = 0; x < min(i.size(), j.size()); x++) {
		if (i[x] != j[x]) return i[x] > j[x];
	}
	return false;
}

bool ifsame(vector<int> i, vector<int> j) {
	if (i.size() != j.size()) return false;
	for (int x = 0; x < i.size(); x++) {
		if (i[x] != j[x]) return false;
	}
	return true;
}
