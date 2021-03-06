/*
문제
이 경우 함수 f(x)는 위 그림과 같이 그려질 겁니다.
조가희는 구간 [0,n]에서 정의되는 함수 y=f(x)와 y=kx가 (0,0) 말고 또 다른 점에서 만나는지 궁금해졌습니다. 여러분이 궁금증을 해결해 주세요.

입력
첫 줄에 n이 주어집니다. 
두번째 줄에 n개의 수가 주어집니다.
세 번째 줄에 k가 주어집니다. 1 ≤ n ≤ 105이고,
n을 제외한 나머지 수들은 0보다 크거나 같고, 2^30보다 작거나 같다는 것이 보장됩니다.

출력
(0,0) 말고 또 다른 점에서 만나면 T를, 그렇지 않다면 F를 출력하세요.
*/


/*
solution:
y = kx위의 가능한 가장 큰 점(x', y')을 찾아 (0, 0), (x', y')과 y[i-1], y[i]사이 교차를 확인한다.
(0, y[0]), (1, y[1])의 경우 (0, 0), (1, k)와 일치하는 직선이 아닌이상 (0, 0)이 아닌 점에서 만나지 않는다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
ll p[200000], k;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll res = x1 * y2 + x2 * y3 + x3 * y1 - (y1*x2 + y2 * x3 + y3 * x1);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	return 0;
}
bool intersect(ll x1, ll y1, ll x2, ll y2, ll a1, ll a2, ll b1, ll b2) {
	int r1 = ccw(x1, y1, x2, y2, a1, a2);
	int r2 = ccw(x1, y1, x2, y2, b1, b2);
	int r3 = ccw(a1, a2, b1, b2, x1, y1);
	int r4 = ccw(a1, a2, b1, b2, x2, y2);
	int res1 = r1 * r2;
	int res2 = r3 * r4;
	if (res1 <= 0 && res2 <= 0)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	cin >> k;
	if (p[1] == k) {
		cout << "T";
		return 0;
	}
	ll x = (1LL << 31) / k;
	ll y = k * x;
	for (int i = 2; i < n + 1; i++) {
		if (intersect(0, 0, x, y, i - 1, p[i - 1], i, p[i])) {
			cout << "T";
			return 0;
		}
	}
	cout << "F";
}