#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	string name;
	int year;
	int month;
	int day;
};

bool comp(person i, person j) {
	if (i.year != j.year) return i.year > j.year;
	if (i.month != j.month) return i.month > j.month;
	return i.day > j.day;
}

int main(int argc, char *argv[]) {
	
	int n;
	cin >> n;
	vector<person> people (n);
	for (int i = 0; i < n; i++) {
		cin >> people[i].name >> people[i].day;
		cin >> people[i].month >> people[i].year;
	}
	
	sort(people.begin(), people.end(), comp);
	
	cout << people[0].name << endl;
	cout << people[n-1].name << endl;
}