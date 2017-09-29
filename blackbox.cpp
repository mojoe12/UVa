#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c > 0) cout << endl;
		int m, n;
		cin >> m >> n;
		vector<int> numbers (m);
		for (int i = 0; i < m; i++) cin >> numbers[i];
		
		int i = 0;
		multiset<int> box;
		multiset<int>::iterator it = box.begin();
		
		for (int j = 0; j < n; j++) {
			
			int u;
			cin >> u;
			int adv = 0;
			for (; i < u; i++) {
				box.insert(numbers[i]);
				if (numbers[i] < (*it)) adv--;
			}
			adv++;
			
			if (j == 0) it = box.begin();
			else advance(it, adv);
			
			cout << *(it) << endl;
		}
		
	}
}