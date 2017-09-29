#include <iostream>
#include <vector>
using namespace std;

vector< vector<bool> > func (vector< vector<bool> > joe);
double sum (vector< vector<bool> > joe);
  
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		vector< vector<bool> > nums (3, vector<bool> (3));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				nums[i][j] = false;
				char c;
				cin >> c;
				if (c == '1') nums[i][j] = true;
			}
		}
		int x = -1;
		for (; sum(nums); x++) {
			nums = func(nums);
		}
		cout << x << endl;
	}
}

vector< vector<bool> > func (vector< vector<bool> > joe) {
	vector< vector<bool> > ret (3, vector<bool> (3));
	ret[0][0] = joe[0][1] xor joe[1][0];
	ret[0][1] = (joe[0][0] xor joe[0][2]) xor joe[1][1];
	ret[0][2] = joe[0][1] xor joe[1][2];
	
	ret[1][0] = (joe[0][0] xor joe[2][0]) xor joe[1][1];
	ret[1][1] = ((joe[0][1] xor joe[2][1]) xor joe[1][0]) xor joe[1][2];
	ret[1][2] = (joe[0][2] xor joe[2][2]) xor joe[1][1];
	
	ret[2][0] = joe[2][1] xor joe[1][0];
	ret[2][1] = (joe[2][0] xor joe[2][2]) xor joe[1][1];
	ret[2][2] = joe[2][1] xor joe[1][2];
	return ret;
}

double sum (vector< vector<bool> > joe) {
	double ret = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (joe[i][j]) ret++;
		}
	}
	return ret;
}