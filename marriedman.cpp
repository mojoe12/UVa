#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		string wifestart, wifeend, meetstart, meetend;
		cin >> wifestart >> wifeend >> meetstart >> meetend;
		int wsh, wsm, weh, wem, msh, msm, meh, mem;
		wsh = 10 * (wifestart[0] - '0') + wifestart[1] - '0';
		wsm = 10 * (wifestart[3] - '0') + wifestart[4] - '0';
		weh = 10 * (wifeend[0] - '0') + wifeend[1] - '0';
		wem = 10 * (wifeend[3] - '0') + wifeend[4] - '0';
		msh = 10 * (meetstart[0] - '0') + meetstart[1] - '0';
		msm = 10 * (meetstart[3] - '0') + meetstart[4] - '0';
		meh = 10 * (meetend[0] - '0') + meetend[1] - '0';
		mem = 10 * (meetend[3] - '0') + meetend[4] - '0';
		bool ifbefore, ifafter; // referring to meeting
		ifbefore = meh < wsh || (meh == wsh && mem < wsm);
		ifafter = weh < msh || (weh == msh && wem < msm);
		cout << "Case " << c << ": ";
		if (ifbefore || ifafter) cout << "Hit";
		else cout << "Mr";
		cout << "s Meeting\n";
	}
}