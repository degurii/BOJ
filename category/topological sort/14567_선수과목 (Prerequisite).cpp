/*
문제
모든 과목에 대해 각 과목을 이수하려면 최소 몇 학기가 걸리는지 계산하는 프로그램을 작성하여라.

입력
첫 번째 줄에 과목의 수 N(1≤N≤1000)과 선수 조건의 수 M(0≤M≤500000)이 주어진다.
선수과목 조건은 M개의 줄에 걸쳐 한 줄에 정수 A B 형태로 주어진다.
A번 과목이 B번 과목의 선수과목이다. A<B인 입력만 주어진다. (1≤A<B≤N)

출력
1번 과목부터 N번 과목까지 차례대로 최소 몇 학기에 이수할 수 있는지를 한 줄에 공백으로 구분하여 출력한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> p;
int ind[1001], dist[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		ind[b]++;
	}
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (ind[i] == 0) {
			q.push(i);
			dist[i] = 1;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : p[now]) {
			dist[next] = max(dist[next], dist[now] + 1);
			if (--ind[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i < n + 1; i++) cout << dist[i] << ' ';
}