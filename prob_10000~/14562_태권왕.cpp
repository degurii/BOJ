/*
문제
태균이는 지금 태권도 겨루기 중이다. 지금은 상대에게 지고 있지만 지금부터 진심으로 경기하여 빠르게 역전을 노리려 한다.
태균이가 현재 할 수 있는 연속 발차기는 두가지가 있다.

A는 현재 점수만큼 점수를 얻을 수 있는 엄청난 연속 발차기이다. 하지만 상대 역시 3점을 득점하는 위험이 있다.
B는 1점을 얻는 연속 발차기이다.
현재 태균이의 점수 S와 상대의 점수 T가 주어질 때, S와 T가 같아지는 최소 연속 발차기 횟수를 구하는 프로그램을 만드시오.

입력
첫째 줄에 테스트 케이스의 수 C(1 ≤ C ≤ 100)이 주어진다.
둘째 줄부터 C줄에 걸쳐 테스트 케이스별로 현재 점수 S와 T가 공백을 사이에 두고 주어진다. (1 ≤ S < T ≤ 100)

출력
각 줄마다 S와 T가 같아지는 최소 n을 출력한다.
*/

/*
solution:
풀고나니 그냥 재귀적으로 풀어도 됐었다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s, t, c;

int dist[201][201];
bool check[201][201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> c;
	while (c--) {
		memset(dist, 0, sizeof(dist));
		memset(check, 0, sizeof(check));
		queue<pair<int, int>> q;
		cin >> s >> t;
		check[s][t] = true;
		q.push({ s, t });
		while (!q.empty()) {
			int u = q.front().first;
			int v = q.front().second;
			q.pop();
			if (u == v) {
				cout << dist[u][v] << '\n';
				break;
			}
			if (u + 1 <= v) {
				check[u + 1][v] = true;
				dist[u + 1][v] = dist[u][v] + 1;
				q.push({ u + 1, v });
			}
			if (u * 2 <= v + 3 ) {
				check[u * 2][v + 3] = true;
				dist[u * 2][v + 3] = dist[u][v] + 1;
				q.push({ u * 2, v + 3 });
			}
		}
	}
}