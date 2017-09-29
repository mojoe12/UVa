#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	
	string s;
	while (cin >> s) {
		
		int n = stoi(s);
		if (!n) break;

		vector<int> nums (n);
		map<int, int> numsm;
		
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			numsm.insert(make_pair(nums[i], i));
		}
		

		bool ifari = false;
		
		for (int i = 0; !ifari && i < n; i++) {
			for (int j = i+1; !ifari && j < n; j++) {
				int next = 2 * nums[j] - nums[i];
				if (numsm.count(next) && numsm[next] > j) {
					ifari = true;
				}
			}
		}
		
		if (ifari) cout << "no\n";
		else cout << "yes\n";
	}
}

// connection to the 2 sum problem?
// where when you want to find two numbers that sum to S
// so you hash every element, and then you go through the
// array once more and check for (S - that element) in the hash 