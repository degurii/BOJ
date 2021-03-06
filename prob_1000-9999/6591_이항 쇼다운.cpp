/*
문제
n개의 원소 중에서 k개를 순서 없이 선택하는 방법의 수는 몇 가지 일까?

입력
입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 231-1 을 넘지 않는 두 자연수 n(n ≥ 1)과 k(0 ≤ k ≤n)로 이루어져 있다.
입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 정답을 출력한다. 항상 정답이 231보다 작은 경우만 입력으로 주어진다.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll d[2500][2500];
ll go(ll n, ll k) {
	if (n == k || k == 0) return 1;
	if (k == 1 || k == n - 1) return n;
	if (k == 2 || k == n - 2) return n * (n - 1) / 2;
	if (k == 3 || k == n - 3) return n * (n - 1)*(n - 2) / 6;

	ll &val = d[n][k];
	if (val) return val;
	return val = go(n - 1, k - 1) + go(n - 1, k);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	while (cin >> n >> m, n != 0) {
		cout << go(n, m) << '\n';
	}
}
