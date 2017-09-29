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

void parseInput (vector<int>& input, string s);
int toInt (string s);

int main() {
	
	string s;
	getline(cin, s);
	while (s != "") {
		int n = toInt(s);
		
		vector<int> indices (n);
		
		for (int i = 0; i < n; i++) {
			//int x;
			cin >> indices[i];
			//indices.insert(make_pair(x, i));
		}
		getline(cin, s);
		
		for (getline(cin, s); s != ""; getline(cin, s)) {
			vector<int> input;
			parseInput(input, s);
			if (input.size() <= 1) break;
			vector<LISelement> arr (n);
			for (int i = 0; i < n; i++) {
				arr[input[i]-1] = LISelement(indices[i], 0, 0);
			}
			
			arr[0].LIS = 1;
			arr[0].prev = -1;
			
			for (int i = 0; i < n; i++) {
				int bestindex = -1, maxsubLIS = 0;
				for (int j = 0; j < i; j++) {
					if (arr[j].value < arr[i].value) { // maybe <=
						if (arr[j].LIS > maxsubLIS) {
							maxsubLIS = arr[j].LIS;
							bestindex = j;
						}
						//if (arr[j].LIS == maxsubLIS && val )
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
	




}

int toInt (string s) {
	int x = 0;
	for (int i = 0; i < s.length(); i++) {
		x = 10 * x + (s[i] - '0');
	}
	return x;
}


void parseInput (vector<int>& input, string s) {
	input.resize(0);
	string currs = "";
	for (int i = 0; i <= s.length(); i++) {
		if (i == s.length() || s[i] == ' ') {
			input.push_back(toInt(currs));
			currs = "";
		}
		else currs.push_back(s[i]);
	}
}
