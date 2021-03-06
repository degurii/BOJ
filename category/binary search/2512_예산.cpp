/*
문제
여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

입력
첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다.
다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다.
그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N 이상 1,000,000,000 이하이다.

출력
첫째 줄에는 배정된 예산들 중 최대값인 정수를 출력한다.
*/
#include <iostream>
using namespace std;
using ll = long long;

int n;
ll m, p[10001];

ll cal(ll x) {
	ll val = 0;
	for (int i = 0; i < n; i++)
		if (p[i] <= x) val += p[i];
		else val += x;
	return val;
}
ll foo(ll l, ll r) {
	ll ans = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll x = cal(mid);
		if (m < x)
			r = mid - 1;
		else {
			if (ans < mid) ans = mid;
			l = mid + 1;
		}
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll maxi = 0;
	for (int i = 0; i < n; i++)
		cin >> p[i], maxi = (maxi > p[i]) ? maxi : p[i];
	cin >> m;
	cout << foo(1, maxi);
}