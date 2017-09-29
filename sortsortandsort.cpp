#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod (int num, int m) {
	if (num >= 0) return num % m;
	else return -((-num) % m);
}

struct comp {
	int m;
	comp (int mi) {
		m = mi;
	}
	bool operator()(const int& i, const int& j) {
		if (m == 0) return true;
		if (mod(i, m) != mod(j, m)) return mod(i, m) < mod(j, m);
		if (mod(i, 2) != mod(j, 2)) return mod(i, 2);
		return mod(i, 2) != (i < j);
	}
};

int main(int argc, char *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		
		cout << n << ' ' << m << endl;
		if (!n && !m) break;
		
		vector<int> nums (n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		
		comp mycomp (m);
		sort(nums.begin(), nums.end(), mycomp);
		
		for (int i = 0; i < n; i++) cout << nums[i] << endl;
		
	}
	return 0;
}