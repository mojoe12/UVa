#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function declarations
struct ticket {
	int start;
	int stop;
	int number;
};

bool comp(ticket i, ticket j);
int getprice (ticket i);
void maxearn(int n, vector<ticket>& tickets, int index, int cprice, vector<int>& cnumbers, int& maxprice);

int main() {
	
	// setup input
	
	int n, b, t;
	while (cin >> n >> b >> t) {
		if (!n && !b && !t) break;
		vector<ticket> tickets (t);
		for (int i = 0; i < t; i++) {
			cin >> tickets[i].start >> tickets[i].stop >> tickets[i].number;
		}
		
		sort(tickets.begin(), tickets.end(), comp);
		int me = 0;
		vector<int> cnumbers (b);
		maxearn (n, tickets, 0, 0, cnumbers, me);
		cout << me << endl;
	}

}

bool comp(ticket i, ticket j) {
	return getprice(i) > getprice(j);
}

int getprice (ticket i) {
	return i.number * (i.stop - i.start);
}

void maxearn(int n, vector<ticket>& tickets, int index, int cprice, vector<int>& cnumbers, int& maxprice) 
{
	for (int i = 0; i < cnumbers.size(); i++) {
		if (cnumbers[i] > n) return;
	}
	maxprice = max(maxprice, cprice);
	if (index == tickets.size()) return;
	
	ticket t = tickets[index];
	for (int i = t.start; i < t.stop; i++) cnumbers[i] += t.number;
	maxearn(n, tickets, index+1, cprice + getprice(t), cnumbers, maxprice);
	
	for (int i = t.start; i < t.stop; i++) cnumbers[i] -= t.number;
	maxearn(n, tickets, index+1, cprice, cnumbers, maxprice);
}