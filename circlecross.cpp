#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("circlecross.in");
	ofstream fout ("circlecross.out");
	
	int n;
	cin >> n;
	vector<int> points (2*n);
	for (int i = 0; i < 2*n; i++) cin >> points[i];
	
	int numcross = 0;
	for (int num = 1; num <= n; num++) {
		int numseen = 0;
		set<int> outside;
		set<int> inside;
		
		for (int i = 0; i < 2*n; i++) {
			if (points[i] == num) {
				numseen++;
			}
			else if (numseen == 1) {
				inside.insert(points[i]);
			}
			else {
				outside.insert(points[i]);
			}
		}
		
		for (int i = 0; i < outside.size(); i++) {
			if ( inside.count(outside[i]) ) numcross++;
		}
		
	}
	
	cout << numcross/2 << endl;
}






































/*
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

bool ifok (int a, int b, int c, int d) {
	if (c > a && a > d && d > b) return true;
	if (a > c && d > a && b > d) return true;
	return false;
}

int main(int argc, char *argv[]) {
	ifstream fin ("circlecross.in");
	ofstream fout ("circlecross.out");
	
	int n;
	fin >> n;
	map<int, pair<int,int> > indices;
	for (int i = 0; i < 2*n; i++) {
		int x;
		fin >> x;
		if (indices.count(x)) indices[x].second = i;
		else indices.insert(make_pair(x, make_pair(i,0)));
	}
	
	int numcross = 0;
	typedef map<int, pair<int, int> >:: iterator it_type;
	it_type it = indices.begin();
	for (; it != indices.end(); it++) {
		it_type it2 = it;
		for (it2++; it2 != indices.end(); it2++) {
			if (ifok(it->second.first, it->second.second, it2->second.first, it2->second.second)) numcross++;
		}	
	}
	
	fout << numcross << endl;
}*/