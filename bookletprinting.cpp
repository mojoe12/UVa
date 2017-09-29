#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		if (!n) break;
		
		cout << "Printing order for " << n << " pages:\n";
		
		if (n == 1) {
			cout << "Sheet 1, front: Blank, 1\n";
			continue;
		}
				
		int max = n, min = 3;

		cout << "Sheet 1, front: ";
		if (n%4) cout << "Blank, 1\n";
		else cout << (max--) << ", 1\n";
		
		cout << "Sheet 1, back : 2, ";
		if (n%4 == 1 || n%4 == 2) cout << "Blank\n";
		else cout << (max--) << endl;
		
		for (int i = 1; i <= (n-1)/4; i++) 
		{
			cout << "Sheet " << i+1 << ", front: ";
			if (i == 1 && n%4 == 1) cout << "Blank";
			else cout << (max--);
			cout << ", " << (min++) << endl;
			
			cout << "Sheet " << i+1 << ", back : ";
			cout << (min++) << ", " << (max--) << endl;
		}
	}
}


