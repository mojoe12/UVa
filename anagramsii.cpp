#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

bool ifequal (vector<int>& a, vector<int>& b) {
	for (int i = 0; i < 26; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		int n;
		cin >> n;
		vector< vector<int> > dict (n, vector<int> (26, 0));
		vector<string> words (n);
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			words[i] = s;
			for (int j = 0; j < s.length(); j++) {
				dict[i][s[j] - 'a']++; // if its uppercase
			}
		}
		
		while (cin >> s) {
			if (s == "END") break;
			
			string olds = s;
			
			cout << "Anagrams for: " << s << endl;
			
			vector<int> arr (26, 0);
			for (int j = 0; j < s.length(); j++) {
				arr[s[j] - 'a']++; // if its uppercase
			}
			
			int num = 0;
			for (int i = 0; i < dict.size(); i++) {
				
				if (ifequal(arr, dict[i])) {
					num++;
					cout.width(3);
					cout << right << num;
					cout << ") " << words[i] << endl;
				}
			}
			
			if (!num) cout << "No anagrams for: " << olds << endl;
		}
		
	}




}