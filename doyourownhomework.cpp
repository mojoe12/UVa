#include <iostream>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		map<string, int> subjects;
		for (int i = 0; i < n; i++) {
			string subject;
			int duration;
			cin >> subject >> duration;
			subjects.insert( make_pair(subject, duration) );
		}
		int d;
		cin >> d;
		string subjectdue;
		cin >> subjectdue;
		cout << "Case " << c << ": ";
		if (subjects.count(subjectdue)) {
			int time = subjects[subjectdue];
			if (time <= d) cout << "Yesss\n";
			else if (time <= d+5) cout << "Late\n";
			else cout << "Do your own homework!\n";
		}
		
		else cout << "Do your own homework!\n";
	}
}