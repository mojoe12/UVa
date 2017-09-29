#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	// setup input
	int size;
	for (int c  = 1; cin >> size; c++) {
		if (!size) break;
		
		vector<int> speeds;
		
		int sumspeed = 0, newspeed;
		while (sumspeed < size) {
			cin >> newspeed;
			speeds.push_back(newspeed);
			sumspeed += newspeed;
		}
		
		cout << "Output for data set " << c << ", " << size << " bytes:\n";
		
		int numleft = sumspeed;
		for (int s = 5; s <= speeds.size(); s += 5) 
		{
			int sum = 0;
			for (int i = s-5; i < s; i++) sum += speeds[i];
			numleft -= sum;
			if (!sum) {
				cout << "   Time remaining: stalled\n";
			}
			else {
				int e = ceil(numleft * 5.0 / sum);
				cout << "   Time remaining: " << e << " seconds\n";
			}
		}
		
		cout << "Total time: " << speeds.size() << " seconds\n\n";
	}

}