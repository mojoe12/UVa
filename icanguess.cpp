#include <iostream>
#include <stack>
#include <queue>


using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		
		bool ifs = true, ifq = true, ifp = true;
		
		for (int i = 0; i < n; i++) {
			int type, result;
			cin >> type >> result;
			if (ifs) {
				if (type == 1) s.push(result);
				else if (type == 2) {
					if (s.size() && result != s.top()) ifs = false;
					else if (s.size()) s.pop();
					else ifs = false;
				}
			}
			if (ifq) {
				if (type == 1) q.push(result);
				else if (type == 2) {
					if (q.size() && result != q.front()) ifq = false;
					else if (q.size()) q.pop();
					else ifq = false;
				}
			}
			if (ifp) {
				if (type == 1) p.push(result);
				else if (type == 2) {
					if (p.size() && result != p.top()) ifp = false;
					else if (p.size()) p.pop();
					else ifp = false;
				}
			}
		}
		
		if ( (ifs && ifq) || (ifs && ifp) || (ifq && ifp) ) cout << "not sure\n";
		else if (ifs) cout << "stack\n";
		else if (ifq) cout << "queue\n";
		else if (ifp) cout << "priority queue\n";
		else cout << "impossible\n";
		
	}
}