#include <iostream>
using namespace std;

int n, m, k;
int ans;
int p[2000];
void foo(int x) {
	for (int i = (x - k >= 1 ? x - k : 1); i < (x + k + 1 <= n ? x + k + 1 : n + 1); i++) {
		p[i] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		foo(x);
	}
	/*
	for (int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl << endl << endl;
	*/
	for (int i = 1; i < n + 1; i++) {
		if (p[i] == 0) {
			if (i + k <= n) {
				i += k;
				foo(i);
				ans++;
			}
			else {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}