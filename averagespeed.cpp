#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
double gettime(string &time, string &time2) {
	string hours = "";
	time2 = "";
	int i = 0;
	for (; hours.length() < 2; i++) {
		if (time[i] - '0' >= 0 && time[i] - '0' < 10) hours += time[i];
	}
	time2 += hours + ':';
	string mins = "";
	for (; mins.length() < 2; i++) {
		if (time[i] - '0' >= 0 && time[i] - '0' < 10) mins += time[i];
	}
	time2 += mins + ':';
	string secs = "";
	for (; secs.length() < 2; i++) {
		if (time[i] - '0' >= 0 && time[i] - '0' < 10) secs += time[i];
	}
	time2 += secs;
	int hour = stoi(hours), min = stoi(mins), sec = stoi(secs);
	string newtime = "";
	for (; i < time.length(); i++) if (time[i] != ' ') newtime += time[i];
	time = newtime;
	return hour + min / 60.0 + sec / 3600.0;
}

int getspeed(string spd) {
	if (spd.length() == 0) return -1;
	return stoi(spd);
}

int main(int argc, char *argv[]) {
	cout << fixed << setprecision(2);
	string s, t;
	double prevt;
	int prevs;
	while (1) {
		getline(cin,s);
		t = s;
		prevt = gettime(s,t);
		prevs = getspeed(s);
		if (prevs < 0) cout << t << " 0.00 km" << endl;
		else if (prevs != 0) break;
	}
	double sumdist = 0;
	for (getline(cin,s); s != ""; getline(cin,s)) {
		t = s;
		double currt = gettime(s,t);
		int currs = getspeed(s);
		sumdist += (currt - prevt) * prevs;
		if (currs < 0) {
			currs = prevs;
			cout << t << " " << sumdist << " km" << endl;
		}
		prevt = currt;
		prevs = currs;
	}
}
