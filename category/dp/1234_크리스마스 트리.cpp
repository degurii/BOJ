/*
N과, 장난감의 수가 주어질 때, 트리를 장식하는 경우의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 트리의 크기 N, 빨강의 개수, 초록의 개수, 파랑의 개수가 주어진다. N은 10보다 작거나 같다.
빨강, 초록, 파랑의 개수는 0보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 경우의 수를 출력한다.
이 값은 int범위를 넘어가는 long long범위이고, 만약 주어진 장난감으로 트리를 장식할 수 없으면 0을 출력한다.
*/
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

int n;
ll d[101][101][101]; // D[R][G][B]
ll fac(ll x) {
	ll r = 1;
	for (ll i = 2; i <= x; i++)
		r *= i;
	return r;
}
ll foo(int lev, int r, int g, int b) {
	if (lev > n)
		return 1LL;

	ll &cur = d[r][g][b];
	if (cur != -1) return cur;
	cur = 0;
	if (r >= lev) cur += foo(lev + 1, r - lev, g, b);
	if (g >= lev) cur += foo(lev + 1, r, g - lev, b);
	if (b >= lev) cur += foo(lev + 1, r, g, b - lev);
	if (lev % 3 == 0) {
		int x = lev / 3;
		ll mul = fac(lev) / fac(lev / 3) / fac(lev / 3) / fac(lev / 3);
		if (r >= x && g >= x && b >= x)
			cur += mul*foo(lev + 1, r - x, g - x, b - x);
	}
	if (!(lev & 1)) {
		int x = lev / 2;
		ll mul = fac(lev) / fac(lev / 2) / fac(lev / 2);
		if (r >= x && g >= x)
			cur += mul*foo(lev + 1, r - x, g - x, b);
		if (r >= x && b >= x)
			cur += mul*foo(lev + 1, r - x, g, b - x);
		if (g >= x && b >= x)
			cur += mul*foo(lev + 1, r, g - x, b - x);
	}
	return cur;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, g, b;
	cin >> n >> r >> g >> b;
	memset(d, -1, sizeof(d));
	cout << foo(1, r, g, b);
}