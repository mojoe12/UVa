#include <iostream>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	
	string addition;
	map<string, int> mp;
	int i = 1;
	
	for (char a = 'a'; a <= 'z'; a++) {
		addition = "";
		addition += a;
		mp.insert( pair<string, int> (addition, i++) );
	}
	
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			addition = "";
			addition += a;
			addition += b;
			mp.insert( pair<string, int> (addition, i++) );
		}
	}
	
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			for (char c = b+1; c <= 'z'; c++) {
				addition = "";
				addition += a;
				addition += b;
				addition += c;
				mp.insert( pair<string, int> (addition, i++) );
			}
		}
	}
	
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			for (char c = b+1; c <= 'z'; c++) {
				for (char d = c+1; d <= 'z'; d++) {
					addition = "";
					addition += a;
					addition += b;
					addition += c;
					addition += d;
					mp.insert( pair<string, int> (addition, i++) );
				}
			}
		}
	}
	
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			for (char c = b+1; c <= 'z'; c++) {
				for (char d = c+1; d <= 'z'; d++) {
					for (char e = d+1; e <= 'z'; e++) {
						addition = "";
						addition += a;
						addition += b;
						addition += c;
						addition += d;
						addition += e;
						mp.insert( pair<string, int> (addition, i++) );
					}
				}
			}
		}
	}
	
	string word;
	while (cin >> word) {
		if (mp.count(word)) cout << mp[word] << endl;
		else cout << "0\n";
	}
	
}