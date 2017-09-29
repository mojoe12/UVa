#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct block {
	block (int L, int M) :
	l(L), m(M) {}
	block() :
	l(0), m(0) {}
	int l;
	int m;
};

bool comp (block b1, block b2) {
	if (b1.l == b2.l) return b1.m < b2.m;
	return b1.l < b2.l;
}

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		
		int n;
		cin >> n;
		
		vector<block> input (n);
		
		for (int i = 0; i < n; i++) {
			int l, m;
			cin >> l >> m;
			input[i] = block(l, m);
		}
		sort(input.begin(), input.end(), comp);
		
		int count = n;
		vector<int> arr (n);
		for (int i = 0; i < n; i++) {
			arr[i] = input[i].m;
		}
		
		for (int i = 0; i < n; i++) {			
			//for (int j = 0; j < n; j++) cout << arr[j] << ' '; cout << endl;
			int maxj = -1, maxm = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && arr[j] > maxm) {
					maxm = arr[j];
					maxj = j;
				}
			}
			if (maxj > -1) {
				arr[maxj] = 10000;
				count--;
			}
		}
		for (int i = 0; i < n; i++) {			
			//for (int j = 0; j < n; j++) cout << arr[j] << ' '; cout << endl;
			int maxj = -1, maxm = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && arr[j] > maxm) {
					maxm = arr[j];
					maxj = j;
				}
			}
			if (maxj > -1) {
				arr[maxj] = 10000;
				count--;
			}
		}
		
		cout << count << endl;
	}
}

// you have to get rid of the ones you used and start over
