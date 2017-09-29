#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (pair<int,int> i, pair<int, int> j) {
	return i.second < j.second;
}

int main(int argc, char *argv[]) {
	int n;
	int counter = 0;
	map <int, int> counts;
	map <int, int> index;
	
	while (cin >> n) {
		if (counts.count(n)) counts[n]++;
		else {
			counts.insert( make_pair (n, 1) );
			index.insert( make_pair (n, counter++));
		}
	}
	
	typedef map<int, int>::iterator it_type;
	vector< pair<int, int> > output;
	for (it_type it = index.begin(); it != index.end(); it++) {
		output.push_back( make_pair(it->first, it->second) );
	}
	sort(output.begin(), output.end(), comp);

	for (int i = 0; i < output.size(); i++) {
		cout << output[i].first << ' ';
		cout << counts[output[i].first] << endl;
	}
}