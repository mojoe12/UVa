#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		if (!n) break;
		priority_queue<int, vector<int>, greater<int> > nums;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			nums.push(x);
		}

		long long totalcost = 0;
		for (int i = 1; i < n; i++) {
			int newnum = nums.top();
			nums.pop();
			newnum += nums.top();
			totalcost += newnum;
			nums.pop();
			nums.push(newnum);
		}

		cout << totalcost << endl;
	}
}