#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct block {
	block (int L, int M) :
	l(L), m(M) {}
	int l;
	int m;
};

struct LISelement {
	LISelement() :
	value(block(0,0)), LIS(0) {};
	
	LISelement (block v, int l) :
	value(v), LIS(l) {}
	
	block value;
	int LIS;
};

bool comp (LISelement e1, LISelement e2) {
	if (e1.value.l == e2.value.l) return e1.value.m < e2.value.m;
	return e1.value.l < e2.value.l;
}

int main() {
	
	int n;
	while (cin >> n) {
		
		if (!n) break;
		
		vector<LISelement> arr (n);
		for (int i = 0; i < n; i++) {
			int l, m;
			cin >> l >> m;
			arr[i].value = block(l, m);
		}
		sort(arr.begin(), arr.end(), comp);
		
		for (int i = 0; i < n; i++) {
			int maxsubLIS = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j].value.m <= arr[i].value.m) {
					maxsubLIS = max(maxsubLIS, arr[j].LIS); // maybe <=
				}
			}
			arr[i].LIS = maxsubLIS + 1;
		}
				
		int maxlen = 0;
		for (int i = 0; i < n; i++) {
			maxlen = max(maxlen, arr[i].LIS);
		}
		cout << maxlen << endl;
		
	}
	cout << "*\n";
}


// this shit is fucked up