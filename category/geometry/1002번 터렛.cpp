#include <iostream>
#include <cmath>
using namespace std;

int t;
int main() {
	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2, ans = 0;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double ab = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

		if (x1 == x2 && y1 == y2)
			ans = (r1 == r2) ? -1 : 0;
		else if (ab == r1 + r2 || ab == abs(r2 - r1))
			ans = 1;
		else if (ab<r1 + r2 && ab>abs(r2 - r1))
			ans = 2;
		else
			ans = 0;
		cout << ans << '\n';
	}
}