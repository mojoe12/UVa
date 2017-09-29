#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

struct tie {
	int i;
	int j;
	int k;
	tie (int ii, int ji, int ki) :
	i(ii), j(ji), k(ki) {}
};

void print(const tie& t) {
	cout << t.i+1 << ' ' << t.j+1;
	cout << ' ' << t.k+1 << endl;
}

int main() {
	
	int n;
	while (cin >> n) {
		vector< vector<bool> > ifbeat (n, vector<bool> (n, false)); // i beats j
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				if (x) ifbeat[i][j] = true;
			}
		}
		
		vector<tie> ties;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < j; k++) {
					bool chain = ifbeat[i][j] && ifbeat[j][k] && ifbeat[k][i];
					
					if (chain) {
						tie t (i, j, k);
						ties.push_back(t);
					}
				}
			}
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					
					bool alldraw = !(ifbeat[i][j] || ifbeat[j][i] ||
						ifbeat[j][k] || ifbeat[k][j] ||
						ifbeat[i][k] || ifbeat[k][i]);
					
					bool chain = ifbeat[i][j] && ifbeat[j][k] && ifbeat[k][i];
					
					if (alldraw || chain) {
						tie t (i, j, k);
						ties.push_back(t);
					}
				}
			}
		}
		
		cout << ties.size() << endl;
		for (int i = 0; i < ties.size(); i++) {
			print(ties[i]);
		}
		
	}




}


