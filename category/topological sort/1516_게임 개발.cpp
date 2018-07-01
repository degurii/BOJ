/*
문제
게임 플레이에 들어가는 시간은 상황에 따라 다를 수 있기 때문에, 모든 건물을 짓는데 걸리는 최소의 시간을 이용하여 근사하기로 하였다.
물론, 어떤 건물을 짓기 위해서 다른 건물을 먼저 지어야 할 수도 있기 때문에 문제가 단순하지만은 않을 수도 있다.
예를 들면 스타크래프트에서 벙커를 짓기 위해서는 배럭을 먼저 지어야 하기 때문에, 배럭을 먼저 지은 뒤 벙커를 지어야 한다.
편의상 자원은 무한히 많이 가지고 있고, 건물을 짓는 명령을 내리기까지는 시간이 걸리지 않는다고 가정하자.

입력
첫째 줄에 건물의 종류 수 N(1≤N≤500)이 주어진다.
다음 N개의 줄에는 각 건물을 짓는데 걸리는 시간과 그 건물을 짓기 위해 먼저 지어져야 하는 건물들의 번호가 주어진다.
건물의 번호는 1부터 N까지로 하고, 각 줄은 -1로 끝난다고 하자.

출력
N개의 각 건물이 완성되기까지 걸리는 최소 시간을 출력한다.
*/









/*
solution:
boj 1005번 acm craft와 같은 문제
https://github.com/degurii/BOJ/blob/master/prob_1000-9999/1005_ACM%20Craft.cpp

다른점은 indgree의 수를 알려주지 않고
줄의 끝에 -1이 들어가기 때문에 적당히 처리해줘야함
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n;
vector<vector<int> > p(501);
int cost[501], dist[501], ind[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> cost[i];
		int x;
		while (cin >> x, x != -1) {
			p[x].push_back(i);
			ind[i]++;
		}
	}
	vector<bool> check(n + 1);
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (ind[i] == 0) {
			check[i] = true;
			q.push(i);
			dist[i] = cost[i];
		}
	}
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i];
			if (check[next] == false) {
 				dist[next] = max(dist[next], dist[now] + cost[next]);
				if (--ind[next] == 0) {
					check[next] = true;
					q.push(next);
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << dist[i] << '\n';
	}
}