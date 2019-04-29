/*
입력
첫 번째 줄에 노드의 개수 n(3 ≤ n ≤ 5000)가 주어진다.
둘째 줄부터 n줄 동안 각 줄마다 n개의 노드의 관계가 주어진다.  i+1번째 줄의 j번째 문자가 ‘ + ’ 일 경우 친구, ' - ' 일 경우 적, ' 0 '은 자기 자신을 뜻한다.
그 다음 줄에는 질의의 개수 m(1 ≤ m ≤ 100)이 주어진다.
다음 m줄 동안 노드 B의 번호 b(0 ≤ b < n), 노드 C의 번호 c(0 ≤ c < n)가 주어진다.
각 노드는 0부터 n-1까지의 수로 표현되고 B, C는 서로 다른 노드 번호로 주어진다.

출력
m줄동안 B와 C의 관계를 출력한다.
*/
#include <iostream>
using namespace std;

int n, m, val;
char x, p[5001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (i != 0) continue;
			p[j] = x;
		}
	}
	cin >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		if (u == 0 || v == 0) cout << p[u + v] << '\n';
		else if (p[u] == p[v]) cout << "+\n";
		else cout << "-\n";
	}
}