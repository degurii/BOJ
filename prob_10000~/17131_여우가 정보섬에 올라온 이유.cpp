#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
using ll = long long;
const ll MOD = 1e9 + 7;
const int addCor = 200001;
const int corMax = 200000 + addCor;

int n;
ll tree[500000];
pair<int, int> p[300000];
ll ans;
ll query(int i) {
	ll val = 0;
	while (i > 0) {
		val += tree[i];
		i -= (i&-i);
	}
	return val;
}
void update(int i, ll diff) {
	while (i <= corMax) {
		tree[i] += diff;
		i += (i&-i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].snd >> p[i].fst;
		update(p[i].snd + addCor, 1);
	}
	sort(p, p + n, [&](auto &a, auto &b) {
		return (a.fst == b.fst) ? a.snd < b.snd : a.fst < b.fst;
	});
	
	int l = 0x3f3f3f3f;
	for (int i = 0; i < n;i++) {
		if (l != p[i].fst) {
			l = p[i].fst;
			for (int j = i; p[j].fst == l; j++) {
				update(p[j].snd + addCor, -1);
			}
		}
		int x = p[i].snd + addCor;
		ll left = query(x - 1) % MOD;
		ll right = (query(corMax) - query(x)) % MOD;
		ans += (left*right) % MOD;
		ans %= MOD;
	}
	cout << ans;
}
