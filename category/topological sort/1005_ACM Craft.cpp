/*
문제
특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램을 작성해주자.

입력
첫째 줄에는 테스트케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다.
첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다)
둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다.
셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다)

마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다. (1 ≤ N ≤ 1000, 1 ≤ K ≤ 100000 , 1≤ X,Y,W ≤ N, 0 ≤ D ≤ 1000)

출력
건물 W를 건설완료 하는데 드는 최소 시간을 출력한다. 편의상 건물을 짓는 명령을 내리는 데는 시간이 소요되지 않는다고 가정한다.
모든 건물을 지을 수 없는 경우는 없다.
*/




/*
solution:
평범한 위상정렬 문제

위상정렬을 하면서 총 시간의 합이 큰 쪽으로 업데이트를 한다
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n, k, w;
vector<vector<int> > p;
vector<int> dist, times, indeg;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		dist.clear();
		times.clear();
		indeg.clear();
		p.clear();
		
		cin >> n >> k;
		dist.resize(n + 1);
		times.resize(n + 1);
		indeg.resize(n + 1);
		p.resize(n + 1);
		for (int i = 1; i < n + 1; i++) {
			cin >> times[i];
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			indeg[v]++;
		}
		cin >> w;
		
		queue<int> q;
		for (int i = 1; i < n + 1; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				dist[i] = times[i];
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (now == w) break;
			
			for (int &next : p[now]) {
				if (--indeg[next]== 0)
					q.push(next);
				if (dist[next] < dist[now] + times[next]) {
					dist[next] = dist[now] + times[next];
				}
			}
		}
		cout << dist[w] << '\n';
	}
}