/*
문제
여러분은 크기 w×h인 격자 공간에서 처음에 (p,q)에서 출발하는 개미의 t시간 후의 위치 (x,y)를 계산하여 출력해야 한다.
개미는 절대 지치지 않고 같은 속력으로 이동한다고 가정한다.

문제에서 w와 h는 자연수이며 범위는 2 ≤ w,h ≤ 40,000이다.
그리고 개미의 초기 위치 p와 q도 자연수이며 범위는 각각 0 < p < w과 0 < q < h이다.
그리고 계산할 시간 t의 범위는 1 ≤ t ≤ 200,000,000이다.

입력
첫줄에는 w와 h가 공백을 사이에 두고 주어진다.
그 다음 줄에는 초기 위치의 좌표값 p와 q가 공백을 사이에 두고 주어진다.
3번째 줄에는 개미가 움직일 시간 t가 주어진다.

출력
출력은 t 시간 후에 개미의 위치 좌표 (x,y)의 값 x와 y를 공백을 사이에 두고 출력한다.
*/

#include <iostream>
using namespace std;
using ll = long long;

ll w, h, x, y, t;
int dx = 1, dy = 1;
ll min(ll a, ll b) { return a < b ? a : b; }
int main() {
	int d = 0;
	cin >> w >> h >> x >> y >> t;
	while (1) {
		ll a = (dx > 0) ? w - x : x;
		ll b = (dy > 0) ? h - y : y;
		ll k = min(a, b);
		if (t < k) {
			x += dx * t;
			y += dy * t;
			cout << x << ' ' << y;
			return 0;
		}
		t -= k;
		x += dx * k;
		y += dy * k;
		(a < b) ? dx *= -1 : dy *= -1;
	}
}
