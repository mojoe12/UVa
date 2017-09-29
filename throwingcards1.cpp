#include <iostream>
#include <queue>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		
		vector<int> discarded;
		while (q.size() > 1) {
			discarded.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		
		cout << "Discarded cards:";
		if (discarded.size()) cout << ' ';
		for (int i = 0; i < discarded.size(); i++) {
			if (i) cout << ", ";
			cout << discarded[i];
		}
		cout << endl << "Remaining card: " << q.front() << endl;
	}
}