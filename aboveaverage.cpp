#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
	cout << fixed << setprecision(3);
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<int> grades (n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> grades[i];
			sum += grades[i];
		}
		double average = (double) sum / n;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (grades[i] > average) count++;
		}
		double percent = 100 * (double) count / n;
		cout << percent << "%\n";
	}
}