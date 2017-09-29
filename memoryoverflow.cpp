#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int x;
	cin >> x;
	for (int c = 1; c <= x; c++) {
		
		int n, k;
		cin >> n >> k;
		vector<char> memory (k);
		fill (memory.begin(), memory.end(), ' ');
		int numrecs = 0;
		int index = 0;
		for (int i = 0; i < n; i++) {
			char name;
			cin >> name;
			if (find(memory.begin(), memory.end(), name) != memory.end()) numrecs++;
			memory[i % k] = name;
		}
		
		cout << "Case " << c << ": ";
		cout << numrecs << endl;
	}
}