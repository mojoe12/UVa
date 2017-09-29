#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	string s;
	while (cin >> s) {
		if (s == "~") break;
		
		string number = "";
		int flag = 0;
		while (s != "#") {
			if (s.size() < 3) flag = 2 - s.size();
			else {
				for (int i = 0; i < s.size()-2; i++) number += ('0' + flag);
			}
			cin >> s;
		}
		int num = 0;
		for (int i = 0; i < number.size(); i++) {
			num = 2 * num + (number[i] - '0');
		}
		cout << num << endl;
		
	}



}


