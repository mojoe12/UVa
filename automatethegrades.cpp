#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

char getGrade (int num) {
	if (num >= 90) return 'A';
	if (num >= 80) return 'B';
	if (num >= 70) return 'C';
	if (num >= 60) return 'D';
	return 'F';	
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int x = 1; x <= k; x++) {
		vector<int> grades (5);
		for (int i = 0; i < 4; i++) cin >> grades[i];
		int a, b, c;
		cin >> a >> b >> c;
		grades[4] = (a + b + c - min(a, min(b, c)) ) / 2;
		char g = getGrade(accumulate(grades.begin(), grades.end(), 0));
		cout << "Case " << x << ": " << g << endl;
	}
	
}