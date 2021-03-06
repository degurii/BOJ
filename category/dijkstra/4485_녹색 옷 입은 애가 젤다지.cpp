/*
입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 동굴의 크기를 나타내는 정수 N이 주어진다. (2 ≤ N ≤ 125) N = 0인 입력이 주어지면 전체 입력이 종료된다.
이어서 N개의 줄에 걸쳐 동굴의 각 칸에 있는 도둑루피의 크기가 공백으로 구분되어 차례대로 주어진다.
피의 크기가 k면 이 칸을 지나면 k루피를 잃는다는 뜻이다. 여기서 주어지는 모든 정수는 0 이상 9 이하인 한 자리 수다.

출력
각 테스트 케이스마다 한 줄에 걸쳐 정답을 형식에 맞춰서 출력한다. 형식은 예제 출력을 참고하시오
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

int n, p[130][130], d[130*130];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int path[130 * 130];
bool check[130*130];
struct Edge {
	int to, cost;
	Edge(int t, int c) :to(t), cost(c) {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int test = 1; 1;test++){
		cin >> n;
		if (n == 0) break;
		vector<vector<Edge> > g(n*n);
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> p[i][j];
				d[i*n + j] = INF;
			}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int now = i * n + j;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < n) {
						int next = nx * n + ny;
						g[now].push_back(Edge(next, p[nx][ny]));
					}
				}
			}
		}

		priority_queue<pair<int, int> > q;
		q.push({ 0, 0 });
		d[0] = 0;
		while (!q.empty()) {
			int now = q.top().second;
			q.pop();
			if (check[now]) continue;
			check[now] = true;
			for (auto it : g[now]) {
				int next = it.to;
				int ncost = it.cost;

				if (d[next] > d[now] + ncost) {
					d[next] = d[now] + ncost;
					path[next] = now;
					q.push({ -d[next], next });
				}
			}
		}
		cout << "Problem " << test << ": ";
		cout << d[n*n - 1] + p[0][0] << '\n';
	}
}