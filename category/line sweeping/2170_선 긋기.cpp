/*
문제
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다.
선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.
이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

입력
첫째 줄에 선을 그은 횟수 N(1≤N≤1,000,000)이 주어진다.
다음 N개의 줄에는 선을 그을 때 선택한 두 점이 주어진다.
선택한 지점은 -1,000,000,000 이상 1,000,000,000 이하의 정수이다.

출력
첫째 줄에 그은 선의 총 길이를 출력한다.
*/






/*
solution:
선의 왼쪽 좌표를 기준으로 정렬한다
왼쪽좌표가 작은 순으로 보면서
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

int n;
vector<pair<int, int> > p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		p.push_back({ u, v });
	}
	sort(p.begin(), p.end());
	int ans = 0, last = -INF;
	for (auto &now : p) {
		int u = now.first;
		int v = now.second;
		if (u <= last && v > last) {
				ans += v - last;
		}
		else if (u > last) {
			ans += v - u;
		}
		if (v > last) last = v;
	}
	cout << ans;
}