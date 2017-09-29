#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void findpath(vector< bitset<25> >& graph, int cn, int csize, int& bestsize);

int main(int argc, char *argv[]) {
	int m, n; // nedges, nnodes
	while (cin >> n >> m) {
		if (!m && !n) break;
		
		vector< bitset<25> > graph (n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = graph[y][x] = true;
		}
		
		int bestsize = 0;
		for (int i = 0; i < n; i++) {
			findpath(graph, i, 0, bestsize);
		}
		cout << bestsize << endl;	
	}
}

void findpath(vector< bitset<25> >& graph, int cn, int csize, int& bestsize) {
	for (int i = 0; i < graph.size(); i++) {
		if (!graph[i][cn]) continue;
		bestsize = max(bestsize, csize+1);
		graph[cn][i] = graph[i][cn] = false;
		findpath(graph, i, csize+1, bestsize);
		graph[cn][i] = graph[i][cn] = true;
	}
}