/*
문제
각 도시에 있는 주유소의 기름 가격과, 각 도시를 연결하는 도로의 길이를 입력으로 받아
제일 왼쪽 도시에서 제일 오른쪽 도시로 이동하는 최소의 비용을 계산하는 프로그램을 작성하시오.

입력
표준 입력으로 다음 정보가 주어진다.
첫 번째 줄에는 도시의 개수를 나타내는 정수 N(2 ≤ N ≤ 100,000)이 주어진다.
다음 줄에는 인접한 두 도시를 연결하는 도로의 길이가 제일 왼쪽 도로부터 N-1개의 자연수로 주어진다.
다음 줄에는 주유소의 리터당 가격이 제일 왼쪽 도시부터 순서대로 N개의 자연수로 주어진다.
제일 왼쪽 도시부터 제일 오른쪽 도시까지의 거리는 1이상 1,000,000,000 이하의 자연수이다.
리터당 가격은 1 이상 1,000,000,000 이하의 자연수이다.

출력
표준 출력으로 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용을 출력한다.
*/




/*
solution:
처음부터 끝까지 선형으로 확인하는데,
현재까지의 최소가격보다 해당 노드의 가격이 더 적을 때
(이전최소가격 * 거기서부터의 거리)를 총 합에 더해주고, 최소가격을 업데이트한다.
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> cost(1), sum(2);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll x;
		cin >> x;
		sum.push_back(sum.back() + x);
	}
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		cost.push_back(x);
	}
	vector<int> pos;
	ll cur = 0x3f3f3f3f;
	for (int i = 1; i < n; i++) {
		if (cur > cost[i]) {
			cur = cost[i];
			pos.push_back(i);
		}
	}
	pos.push_back(n);
	ll ans = 0;
	for (int i = 0, l = pos.size(); i < l - 1; i++) {
		int u = pos[i], v = pos[i + 1];
		ans += cost[u] * (sum[v] - sum[u]);
	}
	cout << ans;
}