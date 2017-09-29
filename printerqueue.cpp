#include <iostream>
#include <queue>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n, p;
		cin >> n >> p;
		queue<int> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push(x);
			pq.push(x);
		}
		int totaltime = 0;
		while (1) {

			if (q.front() < pq.top()) {
				q.push(q.front());
				q.pop();
				if (p == 0) p = q.size();
				p--;
			}
			else {
				totaltime++;
				if (p == 0) break;
				pq.pop();
				q.pop();
				p--;
			}
		}
		cout << totaltime << endl;
	}
}