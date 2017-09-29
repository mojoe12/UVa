#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	
	int a, b;
	while (cin >> a >> b) {
		int rowa = floor(sqrt(a));
		double xa = .5 * (a - rowa * (rowa+1));
		double ya = rowa * 0.8660254037844386467637231707;
		if ((a+rowa) % 2) ya += 0.28867513459481288225457439;
		else ya += 0.577350269189625764509148780501;
		
		int rowb = floor(sqrt(b));
		double xb = .5 * (b - rowb * (rowb+1));
		double yb = rowb * 0.8660254037844386467637231707;
		if ((b+rowb) % 2) yb += 0.28867513459481288225457439;
		else yb += 0.577350269189625764509148780501;
		
		double dist = sqrt((yb - ya) * (yb - ya) + (xb - xa) * (xb - xa));
		cout << fixed << setprecision(3) << dist << endl;
	}

}
