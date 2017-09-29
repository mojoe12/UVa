#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		if (!n) break;
		
		vector<double> numbers;
		numbers.reserve(n);
		double sum = 0;
		for (int i = 0; i < n; i++) {
			double num;
			cin >> num;
			numbers.push_back(num);
			sum += num;
		}
		
		double maxx = 0;
		double average = sum / n;
		for (int i = 0; i < n; i++) {
			maxx = max(maxx, numbers[i] - average); 
		}
		
		cout << '$' << setprecision(2);
		cout << fixed << maxx << endl;
	}




}


