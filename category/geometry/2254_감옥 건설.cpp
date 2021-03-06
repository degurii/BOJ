/*
문제
소들의 반란이 있은 뒤, 이 소들은 포로로 잡은 인간들을 감시해야 했다.
소들은 (Px, Py)의 위치에 감옥을 짓고, 감옥 둘레에 가능한 한 여러 겹으로 담을 쌓아 포로들이 도망가기 힘들도록 하려 한다. 감옥은 하나의 점으로 표현된다.
이러한 목적을 달성하기 위해, 소들은 감옥 주변에 N개의 담 기둥을 세웠다.
각각의 담은 감옥을 완전히 감싸야 하고, 담 안에 (부분적으로라도) 포함되는 담이 있다면 이러한 담도 완전히 감싸야 한다.
즉, 담벼락이 교차하거나 한 점에서 만나서는 안 된다. 담 기둥 중 어느 세 점도 일직선상에 있지 않다.

이러한 담 기둥들이 주어졌을 때, 겹치지 않는 최대의 중첩된 담의 겹 수를 구하는 프로그램을 작성하시오.
담은 여러 개의 담벼락이 연결된, 닫힌 다각형을 의미하고, 각각의 담벼락의 두 끝 점은 담 기둥 이어야 한다.
이러한 담 사이에는 반드시 약간이라도 공간이 있어야 한다. 즉, 서로 다른 두 담이 하나의 담벼락이나 담 기둥을 공유해서는 안 된다.

입력
첫째 줄에 N(1≤N≤1,000), Px, Py (-100,000≤Px, Py≤100,000)이 주어진다.
다음 N개의 줄에는 차례로 담 기둥의 좌표가 주어진다. 각각의 좌표는 절댓값이 100,000을 넘지 않는 정수이다.

출력
첫째 줄에 최대 겹 수를 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct Point {
	ll x, y;
	int idx;
	Point(ll x, ll y, int i) :x(x), y(y), idx(i){}
} s(0x3f3f3f3f, 0x3f3f3f3f, 0);

int n;
ll x, y, px, py;
vector<Point> p;
bool used[1001];
ll ccw(Point a, Point b, Point c) {
	return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

ll dist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> px >> py;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p.emplace_back(x, y, i);
	}

	
	int npoint = n;
	int ans = 0;
	while (npoint > 2) {
		vector<Point> st;
		
		for(auto cur: p){
			if (used[cur.idx]) continue;
			if (s.x > cur.x || (s.x == cur.x && s.y > cur.y)) {
				s = cur;
			}
		}
		sort(p.begin(), p.end(), [&](const Point &a, const Point &b) {
			ll res = ccw(s, a, b);
			if (used[a.idx]) return false;
			if (!used[a.idx] && used[b.idx]) return true;
			return (res == 0) ? dist(s, a) <= dist(s, b) : res > 0;
		});

		for (auto cur : p) {
			if (used[cur.idx]) break;
			while (st.size() >= 2 && ccw(st[st.size() - 2], st.back(), cur) <= 0) {
				st.pop_back();
			}
			st.push_back(cur);
		}
		
		for(auto cur: st){
			used[cur.idx] = true;
			npoint--;
		}

		bool c = false;
		for (int i = 0; i < st.size() - 1; i++) {
			if (ccw(Point(px, py, 0), st[i], st[i + 1]) <= 0) {
				c = true;
				break;
			}
		}
		if (ccw(Point(px, py, 0), st.back(), st[0]) <= 0) c = true;
		if (c) break;
		s = { 0x3f3f3f3f, 0x3f3f3f3f , -1};
		ans++;
	}
	cout << ans;
}