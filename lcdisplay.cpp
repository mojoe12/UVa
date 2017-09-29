#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	
	int x;
	string s;
	while (cin >> x >> s) {
		if (!x && s == "0") break;
		
		vector<bool> t (s.size(), false);
		vector<bool> m (s.size(), false);
		vector<bool> b (s.size(), false);

		vector<bool> lt (s.size(), false);
		vector<bool> rt (s.size(), false);
		vector<bool> lb (s.size(), false);
		vector<bool> rb (s.size(), false);

		for (int i = 0; i < s.size(); i++) {
			switch (s[i] - '0') {
				case 0: t[i] = b[i] = lt[i] = rt[i] = lb[i] = rb[i] = true; break;
				case 1: rt[i] = rb[i] = true; break;
				case 2: t[i] = b[i] = m[i] = lb[i] = rt[i] = true; break;
				case 3: t[i] = b[i] = m[i] = rt[i] = rb[i] = true; break;
				case 4: m[i] = lt[i] = rt[i] = rb[i] = true; break;
				case 5: t[i] = b[i] = m[i] = lt[i] = rb[i] = true; break;
				case 6: t[i] = b[i] = m[i] = lt[i] = lb[i] = rb[i] = true; break;
				case 7: t[i] = rt[i] = rb[i] = true; break;
				case 8: t[i] = b[i] = m[i] = lt[i] = rt[i] = lb[i] = rb[i] = true; break;
				case 9: t[i] = b[i] = m[i] = lt[i] = rt[i] = rb[i] = true; break;
			}
		}
		
		for (int i = 0; i < s.size(); i++) {
			cout << ' ';
			for (int j = 0; j < x; j++) cout << (t[i] ? '-' : ' ');
			cout << ' ';
			if (i < s.size()-1) cout << ' ';
		}
		cout << endl;
		
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < s.size(); j++) {
				if (j) cout << ' ';
				cout << (lt[j] ? '|' : ' ');
				for (int k = 0; k < x; k++) cout << ' ';
				cout << (rt[j] ? '|' : ' ');
			}
			cout << endl;
		}
		
		for (int i = 0; i < s.size(); i++) {
			cout << ' ';
			for (int j = 0; j < x; j++) cout << (m[i] ? '-' : ' ');
			cout << ' ';
			if (i < s.size()-1) cout << ' ';
		}
		cout << endl;
		
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < s.size(); j++) {
				if (j) cout << ' ';
				cout << (lb[j] ? '|' : ' ');
				for (int k = 0; k < x; k++) cout << ' ';
				cout << (rb[j] ? '|' : ' ');
			}
			cout << endl;
		}
		
		for (int i = 0; i < s.size(); i++) {
			cout << ' ';
			for (int j = 0; j < x; j++) cout << (b[i] ? '-' : ' ');
			cout << ' ';
			if (i < s.size()-1) cout << ' ';
		}
		cout << endl;
		cout << endl;
	}
}


