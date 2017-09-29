#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(int x);
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		vector<int> mem (100); // type?
		fill(mem.begin(), mem.end(), 0);
		string coms;
		cin >> coms;
		int p = 0; // i think
		for (int i = 0; i < coms.length(); i++) {
			char c = coms[i];
			if (c == '>') {
				p++;
				if (p > 99) p = 0;
			}
			else if (c == '<') {
				p--;
				if (p < 0) p = 99;
			}
			else if (c == '+') {
				mem[p]++;
				if (mem[p] > 255) mem[p] = 0;
			}
			else if (c == '-') {
				mem[p]--;
				if (mem[p] < 0) mem[p] = 255;
			}
		}
		cout << "Case " << c << ":";
		for (int i = 0; i < 100; i++) {
			int x = mem[i];
			char r = '0' + (x/16);
			if (x / 16 > 9) r += 7;
			char s = '0' + (x % 16);
			if (x % 16 > 9) s += 7;
			cout << " " << r << s;
		}
		cout << endl;
	}
}