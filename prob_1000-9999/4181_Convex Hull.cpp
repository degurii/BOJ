/*
이 작업은 크게 두 단계의 과정으로 이루어진다.
첫 번째 단계는 볼록 껍질을 이루는 점들을 찾아내는 것이고, 두 번째 단계는 이 점들을 반시계 방향으로 순서를 매기는 것이다.
첫 번째 단계는 이미 완료되었다고 할 때, 두 번째 단계를 수행하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 점의 개수 n이 주어진다. (3 <= n <= 100,000)
두 번째 줄부터 n개의 줄에 걸쳐 각 점에 대한 정보 x, y, c가 주어진다. x, y는 정수이며 절댓값이 1,000,000,000을 넘지 않고, c는 Y 또는 N인 문자이다.
Y는 이 점이 볼록 껍질에 속해있음을, N이면 아님을 의미한다.

중복되는 점은 없으며, 모든 점이 한 직선 위에 있는 경우도 없다.

출력
첫 번째 줄에 볼록 껍질을 이루는 점의 개수를 출력한다.
이어서 한 줄에 하나씩 그 점들의 좌표를 x y 형태로 출력하는데, 이 점들은 반시계 방향으로 순서를 이루어야 한다.
첫 번째 좌표는 x좌표가 가장 작은 점이어야 하며, 만약 그런 좌표가 여러 개라면 그 중에서 y좌표가 가장 작은 점을 선택한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct Point {
	ll x, y;
	Point(ll x, ll y) :x(x), y(y) {}
};

int ccw(const Point &a, const Point &b, const Point &c) {
	ll res = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
	if (res > 0)return 1;
	else if (res == 0) return 0;
	else return -1;
}

ll dist(const Point &a, const Point &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
vector<Point> p;
int n, x, y;
char c;
Point s(0x3f3f3f3f, 0x3f3f3f3f);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> c;
		if (c == 'N') continue;
		p.emplace_back(x, y);
		if (s.x > x || (s.x == x && s.y > y)) {
			s.x = x;
			s.y = y;
		}
	}
	sort(p.begin(), p.end(), [&](const Point &a, const Point &b) {
		int res = ccw(s, a, b);
		return (res == 0) ? dist(s, a) <= dist(s, b) : res == 1;
	});

	int i = 1;
	for (; i < p.size() && p[i].x != s.x; i++);
	reverse(p.begin() + i, p.end());
	cout << p.size() << '\n';
	for (auto cur : p) {
		cout << cur.x << ' ' << cur.y << '\n';
	}
}
