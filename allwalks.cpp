#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
void findpath(vector< bitset<10> >& graph, vector<int>& path, int w, bool& found);

int main() {
	
	bool iffirst = true;
	int n, w;
	while (cin >> n) {
		if (!iffirst) {
			if (!(cin >> n)) break;
			cout << endl;
		}
		iffirst = false;
		cin >> w;
		
		vector< bitset<10> > graph (n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				graph[i][j] = (x);
			}
		}
		
		vector<int> path;
		path.push_back(0);
		bool found = false;
		findpath(graph, path, w, found);
		if (!found) cout << "no walk of length " << w << endl;
	}

}

void findpath(vector< bitset<10> >& graph, vector<int>& path, int w, bool& found) {
	if (path.size() == w+1) {
		found = true;
		cout << '(';
		for (int i = 0; i < path.size()-1; i++) {
			cout << (path[i] + 1) << ',';
		}
		cout << (path[path.size()-1]+1) << ")\n";
		return;
	}
	
	for (int i = 0; i < graph.size(); i++) {
		if (!graph[i][path[path.size()-1]]) continue;
		bool ifused = false;
		for (int j = 0; !ifused && j < path.size(); j++) {
			if (path[j] == i) ifused = true;
		}
		if (ifused) continue;
		path.push_back(i);
		findpath(graph, path, w, found);
		path.pop_back();

	}
}
