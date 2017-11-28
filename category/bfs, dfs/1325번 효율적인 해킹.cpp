/*
문제
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다.
김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다.
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.

출력
첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.
*/



/*
sovle:
시간제한이 5초인걸 못보고 이걸 어떻게 푸나 머리 싸매다가 겨우 푼 문제이다.
시간이 널널하니 모든 노드에서 bfs를 돌려 최댓값들을 찾아주면 된다.

scc(strongly connected component)문제라고 하는데, 나중에 공부해서 다시 풀어봐야할 듯.
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

vector<vector<int> > p;
vector<bool> check;
vector<int> dist;
int n, m;

void bfs(int now, int &cur) {
	queue<int> q;
	check[now] = true;
	q.push(now);
	
	while (!q.empty()) {
		now = q.front();
		q.pop();
		cur++;
		for (int &next : p[now]) {
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	p.resize(n + 1); check.resize(n + 1); dist.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[v].push_back(u);
	}
	
	int maxi = 0;
	vector<int> ans;
	for (int i = 1; i < n + 1; i++) {
		int cur = 0;
		bfs(i, cur);
		if (maxi < cur) {
			maxi = cur;
			ans = vector<int>(1, i);
		}
		else if(maxi == cur){
			ans.push_back(i);
		}
		check = vector<bool>(n + 1);
	}
	for (int it : ans)
		cout << it << ' ';
}