/*
문제
세준시에는 고층 빌딩이 많다. 세준시의 서민 김지민은 가장 많은 고층 빌딩이 보이는 고층 빌딩을 찾으려고 한다.
빌딩은 총 N개가 있는데, 빌딩은 선분으로 나타낸다. i번째 빌딩 (1부터 시작)은 (i,0)부터 (i,높이)의 선분으로 나타낼 수 있다.
고층 빌딩 A에서 다른 고층 빌딩 B가 볼 수 있는 빌딩이 되려면, 두 지붕을 잇는 선분이 A와 B를 제외한 다른 고층 빌딩을 지나거나 접하지 않아야 한다.
가장 많은 고층 빌딩이 보이는 빌딩을 구하고, 거기서 보이는 빌딩의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 빌딩의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
둘째 줄에 1번 빌딩부터 그 높이가 주어진다. 높이는 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째줄에 문제의 정답을 출력한다.
*/
#include <iostream>
using namespace std;
using ll = long long;

struct Point {
	ll x, y;
};

struct Line {
	Point u, v;
	Line(Point a = { 0, 0 }, Point b = { 0, 0 }) :u(a), v(b) {}
};

Line p[51];
int ccw(Point a, Point b, Point c) {
	ll product = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
	if (product > 0) return 1;
	else if (product < 0) return -1;
	else return 0;
}

bool isIntersect(Line a, Line b) {
	Point p1 = a.u, p2 = a.v;
	Point p3 = b.u, p4 = b.v;
	
	int x = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int y = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (x <= 0 && y <= 0)
		return true;
	else
		return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		ll x;
		cin >> x;
		p[i].u.x = p[i].v.x = i;
		p[i].u.y = 0;
		p[i].v.y = x;
	}
	int ans = 0;
	for (int i = 1; i < n + 1; i++) { // i 고정
		int cnt = 0;
		for (int j = 1; j < n + 1; j++) { // i에서 j를 볼 수 있는지 확인해야 한다. 즉, i와 j사이의 건물을 확인한다.
			if (i == j) continue;
			int a = (i < j ? i : j);
			int b = (i + j - a);
		
			bool c = true;
			for (int k = a + 1; k < b; k++) {
				if (isIntersect(p[k], Line(p[i].v, p[j].v))) {
					c = false;
					break;
				}
			}
			if (c) cnt++;
		}
		ans = ans > cnt ? ans : cnt;
	}

	cout << ans;
}