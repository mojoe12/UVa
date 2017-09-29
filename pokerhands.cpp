#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector< pair<char, int> > vec;

bool byrank (pair<char, int> i, pair<char, int> j);
bool bysuit (pair<char, int> i, pair<char, int> j);
int toInt (char c);
int eval(vec& black, vec& white, int type);
int getPair(vec& black, int if2);
int compare(int ret, int check);
int straightflush( vec& black, vec& white );
int four( vec& black, vec& white );
int full( vec& black, vec& white );
int flushh ( vec& black, vec& white);
int straight( vec& black, vec& white );
int three( vec& black, vec& white );
int twopair( vec& black, vec& white );
int Pair( vec& black, vec& white );
int highcard( vec& black, vec& white );


int main(int argc, char *argv[]) {

	string s;
	while (getline(cin, s)) {
		
		vector< pair<char, int> > black;
		vector< pair<char, int> > white;
		for (int i = 0; i < 29; i += 3) {
			if (i < 14) black.push_back( make_pair(s[i+1], toInt(s[i])) );
			else white.push_back( make_pair(s[i+1], toInt(s[i])) );
		}
		
		string response = "Tie.";
		int evaluation = 0;
		for (int i = 0; i < 9; i++) {
			evaluation = eval(black, white, i);
			if (evaluation == 1 || evaluation == 2) break;
		}
		if (evaluation == 1) response = "Black wins.";
		else if (evaluation == 2) response = "White wins.";
		cout << response << endl;
	}
}

bool byrank (pair<char, int> i, pair<char, int> j) {
	if (i.second == j.second) return i.first < j.first;
	return i.second < j.second;
}

bool bysuit (pair<char, int> i, pair<char, int> j) {
	if (i.first == j.first) return i.second < j.second;
	return i.first < j.first;
}

int toInt (char c) {
	switch (c) {
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		case 'J': return 11;
		case 'T': return 10;
		default: return (c - '0');
	}
}

int eval(vec& black, vec& white, int type) {
	switch (type) {
		case 0: return straightflush(black, white);
		case 1: return four(black, white);
		case 2: return full(black, white);
		case 3: return flushh(black, white);
		case 4: return straight(black, white);
		case 5: return three(black, white);
		case 6: return twopair(black, white);
		case 7: return Pair(black, white);
		case 8: return highcard(black, white);
		default: return -1;
	}
}

int getPair(vec& black, int if2 = 0) {
	bool ifdoneyet = !if2;
	bool findlasta[5] = {true, true, true, true, true};
	vector<bool> findlast (findlasta, findlasta + 5);
	
	for (int i = 0; i < 4; i++) {
		if (black[i].second == black[i+1].second) {
			findlast[i] = false;
			findlast[i+1] = false;
			if (ifdoneyet) return black[i].second;
			else ifdoneyet = true;
		}
	}
	if (if2==2) return black[find(findlast.begin(), findlast.end(), true) - findlast.begin()].second;
	return -1;
}

int compare(int ret, int check) {
	if (check > ret || ret == -1) return 2;
	else if (check < ret) return 1;
	return 3;
}

int straightflush( vec& black, vec& white ) {
	sort(black.begin(), black.end(), bysuit);
	sort(white.begin(), white.end(), bysuit);
	int ret = -1;
	if (black[0].first == black[4].first && black[4].second - black[0].second == 4) {
		ret = black[4].second;
	}
	if (white[0].first == white[4].first && white[4].second - white[0].second == 4) {
		return compare(ret, white[4].second);
	}
	else if (ret != -1) return 1;
	return 0;
}

int four( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if (black[1].second == black[4].second || black[0].second == black[3].second) {
		ret = black[2].second;
	}
	if (white[1].second == white[4].second || white[0].second == white[3].second) {
		return compare(ret, white[2].second);
	}
	else if (ret != -1) return 1;
	return 0; 
}

int full( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if ((black[0].second == black[2].second && black[3].second == black[4].second) || (black[0].second == black[1].second && black[2].second == black[4].second)) {
		ret = black[2].second;
	}
	if ((white[0].second == white[2].second && white[3].second == white[4].second) || (white[0].second == white[1].second && white[2].second == white[4].second)) {
		return compare(ret, white[2].second);
	}
	else if (ret != -1) return 1;
	return 0;
}

int flushh ( vec& black, vec& white) {
	sort(black.begin(), black.end(), bysuit);
	sort(white.begin(), white.end(), bysuit);
	int ret = -1;
	if (black[0].first == black[4].first) {
		ret = black[4].second;
	}
	if (white[0].first == white[4].first) {
		if (ret == -1) return 2;
		return highcard(black, white);
	}
	else if (ret != -1) return 1;
	return 0;
}

int straight( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if (black[4].second - black[0].second == 4) {
		ret = black[4].second;
	}
	if (white[4].second - white[0].second == 4) {
		return compare(ret, white[4].second);
	}
	else if (ret != -1) return 1;
	return 0;
}

int three( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if (black[2].second == black[4].second || black[1].second == black[3].second || black[0].second == black[2].second) {
		ret = black[2].second;
	}
	if (white[2].second == white[4].second || white[1].second == white[3].second || white[0].second == white[2].second) {
		return compare(ret, white[2].second);
	}
	else if (ret != -1) return 1;
	return 0; 
}

int twopair( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if (getPair(black) != -1 && getPair(black, 1) != -1) {
		ret = getPair(black, true);
	}
	if (getPair(white) != -1 && getPair(white, 1) != -1) {
		if (ret != getPair(white, 1)) return compare(ret, getPair(white, 1));
		else if (getPair(black) != getPair(white)) return (getPair(black) > getPair(white)) ? 1 : 2;
		else if (getPair(black, 2) != getPair(white, 2)) return (getPair(black, 2) > getPair(white, 2)) ? 1 : 2;
		else return 3;
	}
	else if (ret != -1) return 1;
	return 0;
}

int Pair( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	int ret = -1;
	if (getPair(black) != -1 && getPair(black, 1) == -1) {
		ret = getPair(black);
	}
	if (getPair(white) != -1 && getPair(white, 1) == -1) {
		return compare(ret, getPair(white) );
	}
	else if (ret != -1) return 1;
	return 0;
}

int highcard( vec& black, vec& white ) {
	sort(black.begin(), black.end(), byrank);
	sort(white.begin(), white.end(), byrank);
	if (black[4].second != white[4].second) {
		return (black[4].second > white[4].second) ? 1 : 2;
	}
	if (black[3].second != white[3].second) {
		return (black[3].second > white[3].second) ? 1 : 2;
	}
	if (black[2].second != white[2].second) {
		return (black[2].second > white[2].second) ? 1 : 2;
	}
	if (black[1].second != white[1].second) {
		return (black[1].second > white[1].second) ? 1 : 2;
	}
	if (black[0].second != white[0].second) {
		return (black[0].second > white[0].second) ? 1 : 2;
	}
	return 3;
}