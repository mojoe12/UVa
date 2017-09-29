#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		vector< pair<int, int> > answers;
		for (int i = n+1; i <= 2 * n; i++) {
			if ( (i * n) % (i - n) == 0) {
				int j = (i * n) / (i - n);
				answers.push_back( make_pair(j, i) );
			}
		}
		
		cout << answers.size() << endl;
		for (int i = 0; i < answers.size(); i++) {
			cout << "1/" << n << " = ";
			cout << "1/" << answers[i].first << " + ";
			cout << "1/" << answers[i].second << endl;
		}
	}
}