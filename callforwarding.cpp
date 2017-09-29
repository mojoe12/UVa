#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct request {
	vector<string> target;
	vector<int> start;
	vector<int> duration;
	request () {
		;
	}
	request (string t, int s, int d) {
		target.push_back(t);
		start.push_back(s);
		duration.push_back(d);
	}
};

void addToRequest(request& r, string t, int s, int d);
int toint (string s);
string findext(map<string, request>& requests, int t, string ext, string orig, bool iffirst);

int main() {
	
	int k;
	cin >> k;
	cout << "CALL FORWARDING OUTPUT\n";
	for (int c = 1; c <= k; c++) {
		cout << "SYSTEM " << c << endl;
		
		map<string, request> requests; 
		string source, target;
		while (cin >> source) {
			if (source == "0000") break;
			int start, duration;
			cin >> start >> duration >> target;
			if (requests.count(source)) {
				addToRequest(requests[source], target, start, duration);
			}
			else {
				request nr (target, start, duration);
				requests.insert( make_pair(source, nr) );
			}
		}
		
		string st;
		while (cin >> st) {
			if (st == "9000") break;
			int t = toint(st);
			string ext;
			cin >> ext;
			cout << "AT " << st << " CALL TO " << ext << " RINGS ";
			cout << findext(requests, t, ext, ext, true) << endl;
		}
	}
	cout << "END OF OUTPUT\n";
}

void addToRequest(request& r, string t, int s, int d) {
	r.target.push_back(t);
	r.start.push_back(s);
	r.duration.push_back(d);
}

int toint (string s) {
	int x = 0;
	for (int i = 0; i < s.length(); i++) {
		x = x * 10 + (s[i] - '0');
	}
	return x;
}

string findext(map<string, request>& requests, int t, string ext, string orig, bool iffirst) {
	if (!iffirst && ext == orig) return "9999";
	if (requests.count(ext)) {
		request r = requests[ext];
		for (int i = 0; i < r.target.size(); i++) {
			if (t >= r.start[i] && t <= r.start[i] + r.duration[i]) {
				return findext(requests, t, r.target[i], orig, false);
			}
		}
	}
	
	return ext;
}