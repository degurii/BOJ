#include <iostream>
using namespace std;
using ll = long long;

int n, q;
ll p[300000], s[300000];
ll ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		s[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			s[i] *= p[(i + j) % n];
		}
		ans += s[i];
	}
	int x;
	while (q--) {
		cin >> x;
		x--;
		for (int i = 0; i < 4; i++) {
			int idx = (x - i + n) % n;
			s[idx] *= -1;
			ans += 2 * s[idx];
		}
		cout << ans << '\n';
	}
}
