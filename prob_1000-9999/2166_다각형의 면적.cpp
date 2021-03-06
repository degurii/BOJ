/*
문제
2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절대값이 100,000을 넘지 않는 정수이다.

출력
첫째 줄에 면적을 출력한다. 면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.
*/
#include <iostream>
#include <cmath>
using namespace std;
using ll = double;

int n;
pair<ll, ll> p[10000];
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1*y2 + x2 * y3 + x3 * y1 - (y1*x2 + y2 * x3 + y3 * x1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	ll x = p[0].first, y = p[0].second;
	ll ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += ccw(x, y, p[i].first, p[i].second, p[i + 1].first, p[i + 1].second);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans)/2;
}