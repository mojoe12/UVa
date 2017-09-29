#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

// this is actually "is bigger smarter" rip

using namespace std;

struct elephant {
	elephant (int W, int S, int ii) :
	w(W), s(S), i(ii) {}
	int w;
	int s;
	int i;
};

struct LISelement {
	LISelement() :
	value(elephant(0,0,0)), LIS(0), prev(0) {};
	LISelement (elephant v, int l, int p) :
	value(v), LIS(l), prev(p) {}
	
	elephant value;
	int LIS;
	int prev;
};

bool comp (LISelement e1, LISelement e2) {
	return e1.value.s > e2.value.s;
}

string tostr (int i) {
	if (!i) return "0";
	
	string s = "";
	bool negative = i < 0;
	if (negative) i *= -1;
	while (i) {
		string toadd = "";
		toadd.push_back('0' + i % 10);
		s = toadd + s;
		i /= 10;
	}
	if (negative) s = "-" + s;
	return s;
}

int main() {
	
	vector<LISelement> arr;
	int w, s;
	for (int i = 1; cin >> w >> s; i++) {
		arr.push_back(LISelement(elephant(w, s, i), 0, 0));
	}
	sort(arr.begin(), arr.end(), comp);
	
	int n = arr.size();
	/*
	for (int i = 0; i < n; i++) {
		cout << arr[i].value.w << ' ' << arr[i].value.s << ' ' << arr[i].value.i << endl;
	}*/
	
	for (int i = 0; i < n; i++) {
		int bestindex = -1, maxsubLIS = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j].value.w < arr[i].value.w && arr[j].value.s != arr[i].value.s) { // maybe <=
				if (arr[j].LIS >= maxsubLIS) {
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
	cout << maxlen << endl;
		
	string output = "";
	int index = maxlenindex;
	while (index >= 0) {
		//cout << index << endl;
		string toadd = tostr(arr[index].value.i);
		toadd.push_back('\n');
		output = toadd + output;
		index = arr[index].prev;
	}
	cout << output;

}
