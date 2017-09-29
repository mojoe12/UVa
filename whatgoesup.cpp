#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

bool comp (vector<int> i, vector<int> j) {
	return i.back() < j.back();
}


int main() {
	
	int x;
	vector<int> input;
	while (cin >> x) input.push_back(x);
	
	int n = input.size();
	vector< vector<int> > arr;
	vector<int> newinsert (1, input[0]);
	arr.push_back(newinsert);
	for (int i = 1; i < n; i++) {
		//cout << arr.size() << endl;
		/*
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr[j].size(); k++) {
				cout << arr[j][k] << ' ';
			}
			cout << endl;
		} cout << endl;*/
		
		x = input[i];
		if (x > arr.back().back()) {
			arr.push_back(arr.back());
			arr.back().push_back(x);
		}
		else if (x < arr.front().back()) {
			arr.front().front() = x;
		}
		else {
			vector<int> newinsert (1, x);
			int index = lower_bound(arr.begin(), arr.end(), newinsert, comp) - arr.begin();
			arr[index] = arr[index-1];
			arr[index].push_back(x);
		}
	}
	
	vector<int>& answer = arr.back();
	cout << answer.size() << "\n-\n";
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}

