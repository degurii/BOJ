/*
문제
아우으 우아으이야!! 으어아아아아아아아ㅏㅏㅏ아아앙ㅇ아아ㅏ
수직선 위에 선분을 여러 개 그릴 거 야아아앙ㅇ아아아ㅏㅏ아아ㅏㅏ!!
선분을 겹치게 그리는 것도 가능하다아어으우어우으아아아아아아아아아이야!!!!1
선분을 모두 그렸을 때, 수직선 위에 그려진 선분 길이의 총합은 얼마아아으으우어으이으야이야!!!!

입력
첫째 줄에 수직선 위에 그릴 선분의 개수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄 부터 N개의 줄에 좌표를 나타내는 정수쌍 (x, y)가 주어진다.
이는 [x, y] 구간 (x와 y를 포함하는 구간)에 선분을 그린다는 의미이다.
좌표는 x가 증가하는 순으로, x가 같다면 y가 증가하는 순으로 주어진다. (-1,000,000,000 ≤ x < y ≤ 1,000,000,000)

출력
N개의 선분을 모두 그렸을 때, 수직선 위에 그어진 선분 길이의 총합을 출력한다아아어으잉에애야우아으아이아야아아아아아아이야!!!
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f;

int n;
vector<pair<ll, ll>> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		p.emplace_back(s, e);
	}
	sort(p.begin(), p.end());
	ll ans = 0;
	s = -INF, e = -INF;
	for(int i=0;i<p.size(); i++){
		auto cur = p[i];
		ll ns = cur.first, ne = cur.second;
		if (s <= ns && ne <= e)continue;
		ans += ne - ns;
		if (ns < e) {
			ans -= (e - ns);
		}
		s = ns;
		e = ne;
	}
	cout << ans;
}