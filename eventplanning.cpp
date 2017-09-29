#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int x; cin >> x;) {
		int n = x, b, nh, nw;
		cin >> b >> nh >> nw;
		//
		
		int mincost = 500001;
		for (int h = 0; h < nh; h++) {
			int price;
			cin >> price;
			int ifroom = false;
			for (int w = 0; w < nw; w++) {
				int numb;
				cin >> numb;
				if (numb >= n) ifroom = true;
			}
			int cost = n * price;
			if (ifroom && cost < mincost) mincost = cost;
		}
		if (mincost > b) cout << "stay home" << endl;
		else cout << mincost << endl;
	}
}
/*string input;
getline(cin, input);
if (input == "") break;

string currentnum;
for (int i = 0; i < input.length(); i++) {
	char c = input[i];
	if (c == ' ') {
		int num = stoi(currentnum);
		currentnum = "";
		if (n == -1) n = num;
		else if (b == -1) b = num;
		else if (nh == -1) nh = num;
	}
	else currentnum += c;
}
nw = stoi(currentnum);*/