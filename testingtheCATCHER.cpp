#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct LISelement {
	LISelement() :
	value(0), LIS(0), prev(0) {};
	LISelement (int v, int l, int p) :
	value(v), LIS(l), prev(p) {}
	int value;
	int LIS;
	int prev;
};


int main() {
	
	for (int c = 1; ; c++) {
		
		vector<LISelement> arr;
		int x;
		cin >> x;
		if (x == -1) break;
		while (x != -1) {
			arr.push_back(LISelement(x, 0, 0));
			cin >> x;
		}
		if (c > 1) cout << endl;

				
		int n = arr.size();
			
		for (int i = 0; i < n; i++) {
			int bestindex = -1, maxsubLIS = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j].value >= arr[i].value) { // maybe <=
					if (arr[j].LIS > maxsubLIS) {
						maxsubLIS = arr[j].LIS;
						bestindex = j;
					}
				}
			}
				
			arr[i].LIS = maxsubLIS + 1;
			arr[i].prev = bestindex;
		}
			
		/*for (int i = 0; i < n; i++) {
			cout << arr[i].value << ' ';
			cout << arr[i].LIS << ' ';
			cout << arr[i].prev << endl;
		}*/
			
		int maxlen = 0, maxlenindex = -1;
		for (int i = 0; i < n; i++) {
			if (arr[i].LIS > maxlen) {
				maxlen = arr[i].LIS;
				maxlenindex = i;
			}
		}
		cout << "Test #" << c << ":\n  maximum possible interceptions: ";
		cout << maxlen << endl;
		/*
		string output = "";
		int index = maxlenindex;
		while (index >= 0) {
			cout << FUNCTION(arr[index].val) << ' ';
			// perhaps reverse output
			index = arr[index].prev;
		}
		*/
	}

}
