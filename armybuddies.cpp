#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	while (true) {
		int nsoldiers, nreports;
		cin >> nsoldiers >> nreports;
		if (nsoldiers == 0) break;
		vector<pair<int, int> > soldiers (nsoldiers);
		
		for (int i = 0; i < nsoldiers; i++) {
			soldiers[i] = make_pair(i-1, i+1);
		}
		
		for (int x = 0; x < nreports; x++) {
			
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			
			int retl = 1 + soldiers[l].first;
			int retr = 1 + soldiers[r].second;
			
			if (retl > 0 && retl <= nsoldiers) 
				soldiers[retl-1].second = soldiers[r].second;
			if (retr > 0 && retr <= nsoldiers) 
				soldiers[retr-1].first = soldiers[l].first;
			
			if (retl < 1) cout << "* ";
			else cout << retl << ' ';
			if (retr > nsoldiers) cout << "*\n";
			else cout << retr << endl;
		}
		cout << "-\n";
 	}
}