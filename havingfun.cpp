#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		vector< vector<int> > nums (n, vector<int> (n));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				char c = s[j];
				nums[i][j] = c - '0';
			}
		}
		int x;
		cin >> x;
		for (int z = 0; z < x; z++) {
			string command;
			cin >> command;
			switch (command[0]) {
				case 'i': {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							nums[i][j] = (nums[i][j] + 1) % 10;
						}
					}
					break;
				}
				case 'd': {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							if (nums[i][j] == 0) nums[i][j] = 10;
							nums[i][j]--;
						}
					}
					break;
				}
				case 't': {
					vector< vector<int> > newnums (n, vector<int> (n));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							newnums[i][j] = nums[j][i];
						}
					}
					nums = newnums;
					break;
				}
				case 'r': {
					int a, b;
					cin >> a >> b;
					for (int j = 0; j < n; j++) {
						int temp = nums[a-1][j];
						nums[a-1][j] = nums[b-1][j];
						nums[b-1][j] = temp;
					}
					break;
				}
				case 'c': {
					int a, b;
					cin >> a >> b;
					for (int i = 0; i < n; i++) {
						int temp = nums[i][a-1];
						nums[i][a-1] = nums[i][b-1];
						nums[i][b-1] = temp;
					}
					break;
				}
			}
		}
		cout << "Case #" << c << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << nums[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}