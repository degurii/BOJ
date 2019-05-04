#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int p[200][30];
bool chk[30];
int foo() {
	int cnt[30] = { 0 };
	for (int i = 0; i < n; i++) {
		int *cur = p[i];
		int j = 0;
		while (chk[cur[j]]) j++;
		cnt[cur[j]]++;
	}

	int val = -1, ans = 0;
	for (int i = 1; i <= m; i++) {
		if (val < cnt[i]) {
			val = cnt[i];
			ans = i;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}
	cout << foo() << '\n';
	int ans = 0x3f3f3f3f;
	for (int t = 0; t < (1 << m); t++) {
		memset(chk, 0, sizeof(chk));
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			chk[i+1] = t & (1 << i);
			cnt = chk[i+1] ? cnt + 1 : cnt;
		}
		if (chk[k]) continue;

		if (foo() == k) {
			ans = ans < cnt ? ans : cnt;
		}
	}

	cout << ans;
}