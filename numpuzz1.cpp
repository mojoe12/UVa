#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	string commands;
	for (int c = 1; getline(cin, commands); c++) {
		vector< vector<int> > nums (3, vector<int> (3));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) nums[i][j] = 0;
		}
		for (int i = commands.length()-1; i >= 0; i--) {
			switch (commands[i]) {
				case 'a': {
					nums[0][0]++;
					nums[1][0]++;
					nums[0][1]++;
					break;
				}
				case 'b': {
					nums[0][0]++;
					nums[0][1]++;
					nums[0][2]++;
					nums[1][1]++;
					break;
				}
				case 'c': {
					nums[0][2]++;
					nums[1][2]++;
					nums[0][1]++;
					break;
				}
				case 'd': {
					nums[1][0]++;
					nums[0][0]++;
					nums[1][1]++;
					nums[2][0]++;
					break;
				}
				case 'e': {
					nums[0][1]++;
					nums[1][0]++;
					nums[1][2]++;
					nums[1][1]++;
					nums[2][1]++;
					break;
				}
				case 'f': {
					nums[1][2]++;
					nums[0][2]++;
					nums[2][2]++;
					nums[1][1]++;
					break;
				}
				case 'g': {
					nums[2][0]++;
					nums[1][0]++;
					nums[2][1]++;
					break;
				}
				case 'h': {
					nums[2][0]++;
					nums[2][1]++;
					nums[2][2]++;
					nums[1][1]++;
					break;
				}
				case 'i': {
					nums[2][2]++;
					nums[1][2]++;
					nums[2][1]++;
					break;
				}
			}
		}
		cout << "Case #" << c << ":\n";
		for (int i = 0; i < 3; i++) {
			cout << nums[i][0] % 10 << ' ' << nums[i][1] % 10 << ' ';
			cout << nums[i][2] % 10 << endl;
		}
	}
}