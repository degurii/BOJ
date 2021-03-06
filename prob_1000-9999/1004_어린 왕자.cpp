/*
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트케이스에 대해 첫째 줄에 출발점 (x1, y1)과 도착점 (x2, y2)이 주어진다.
두 번째 줄에는 행성계의 개수 n이 주어지며, 세 번째 줄부터 n줄에 걸쳐 행성계의 중점과 반지름 (cx, cy, r)이 주어진다.
입력제한은 다음과 같다. (-1000 ≤ x1, y1, x2, y2, cx, cy ≤ 1000, 1 ≤ r ≤ 1000, 1 ≤ n ≤ 50)
좌표와 반지름은 모두 정수이다.

출력
각 테스트 케이스에 대해 어린 왕자가 거쳐야 할 최소의 행성계 진입/이탈 회수를 출력한다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet {
	int x, y;
	int rad;
	Planet() {}
	Planet(int x, int y, int r) :x(x), y(y), rad(r) {}
	bool operator == (Planet o) {
		return (x == o.x && y == o.y && rad == o.rad);
	}
	bool operator < (Planet o) {
		return rad < o.rad;
	}
}p[50];

int dist(Planet &a, Planet &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int t;
vector<Planet> s, e;
int sx, sy, ex, ey, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		sx = sy = ex = ey = n = 0;
		memset(p, 0, sizeof(p));
		s.clear();
		e.clear();

		cin >> sx >> sy >> ex >> ey >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y >> p[i].rad;
			if (dist(sx, sy, p[i].x, p[i].y) < p[i].rad*p[i].rad) {
				s.push_back(p[i]);
			}
			if (dist(ex, ey, p[i].x, p[i].y) < p[i].rad*p[i].rad) {
				e.push_back(p[i]);
			}
		}
		sort(s.begin(), s.end());
		sort(e.begin(), e.end());

		

		int a = 0, b = 0;
		int ans = 0;
		while (a < s.size() && b < e.size()) {
			if (s[a] == e[b]) {
				break;
			}
			else {
				ans++;
				if (s[a].rad <= e[b].rad) 
					a++;
				else if (s[a].rad > e[b].rad)
					b++;
			}
		}
		if (a == s.size()) ans += e.size() - b;
		if (b == e.size()) ans += s.size() - a;
		cout << ans << '\n';
	}
}