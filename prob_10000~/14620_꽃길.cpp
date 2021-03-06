/*
돈이 많지 않은 진아를 위하여 진아가 꽃을 심기 위해 필요한 최소비용을 구해주자!

입력
입력의 첫째줄에 화단의 한 변의 길이 N(6≤N≤10)이 들어온다.
이후 N개의 줄에 N개씩 화단의 지점당 가격(0≤G≤200)이 주어진다.

출력
꽃을 심기 위한 최소 비용을 출력한다.
*/
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

int n, p[10][10];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool bar(pair<int, int> x) {
	if (0 <= x.first && x.first < n && 0 <= x.second && x.second < n)
		return true;
	return false;
}
int foo(int x1, int x2, int x3, int y1, int y2, int y3) {
	pair<int, int> d1[5] = {}, d2[5] = {}, d3[5] = {};
	d1[4] = { x1, y1 };
	d2[4] = { x2, y2 };
	d3[4] = { x3, y3 };
	for (int i = 0; i < 4; i++) {
		d1[i] = { x1 + dx[i], y1 + dy[i] };
		d2[i] = { x2 + dx[i], y2 + dy[i] };
		d3[i] = { x3 + dx[i], y3 + dy[i] };
	}

	for (int i = 0; i < 5; i++) {
		auto a = d1[i];
		for (int j = 0; j < 5; j++) {
			auto b = d2[j];
			for (int k = 0; k < 5; k++) {
				auto c = d3[k];
				if (!(bar(a) && bar(b) && bar(c)))
					return INF;
				if (!(a != b && b != c && c != a))
					return INF;
			}
		}
	}
	int val = 0;
	for (int i = 0; i < 5; i++) {
		val += p[d1[i].first][d1[i].second];
		val += p[d2[i].first][d2[i].second];
		val += p[d3[i].first][d3[i].second];
	}
	return val;
}
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}

	int ans = INF;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < n; y2++) {
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < n; y3++) {
							ans = min(ans, foo(x1, x2, x3, y1, y2, y3));
						}
					}
				}
			}
		}
	}
	cout << ans;
}