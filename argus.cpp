#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


class CompareClass {
public:
	bool operator() (pair<int, int> i, pair<int, int> j) {
		if (i.second == j.second) return i.first > j.first;
		return i.second > j.second;
	}
};

int main(int argc, char *argv[]) {
	string s;
	priority_queue< pair<int, int>, vector< pair<int, int> >, CompareClass > queries;
	map<int, int> periods;
	while (cin >> s) {
		if (s == "#") break;
		int q, p;
		cin >> q >> p;
		queries.push( make_pair(q, p) );
		periods.insert( make_pair(q, p) );
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> newpair = queries.top();
		cout << newpair.first << endl;
		queries.pop();
		newpair.second += periods[newpair.first];
		queries.push(newpair);
	}
}