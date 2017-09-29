#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int c = 0; c < k; c++) {
		long long x;
		cin >> x;
		vector<int> coes (x+1);
		for (int i = 0; i <= x; i++) cin >> coes[i];
		int d, k;
		cin >> d >> k;
		
		int n = ceil( (sqrt(8*k/d + 1) - 1) / 2 );
		
		long long sum = 0;
		for (int i = 0; i <= x; i++) {
			long long num = coes[i];
			for (int j = 0; j < i; j++) {
				num *= n;
			}
			sum += num;
		}
		
		cout << sum << endl;
	}
}