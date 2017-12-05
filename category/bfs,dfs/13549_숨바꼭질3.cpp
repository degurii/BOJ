/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/





/*
solution1:
queue두개를 이용해 하나는 0초만에 갈 수 있는것, 다른 하나는 1초만에 갈 수 있는 것으로 하고
0초만에 가는 queue의 내용물들로 queue들에 push한다
한바퀴 돌 떄마다 q[0], q[1]을 교체 -> t ^= 1;


solution2:
deque를 이용한다
0초만에 가는곳은 deque의 앞에
1초만에 가는곳은 deque의 뒤에 넣는다
(코드가 훨씬 간결하다)
*/
#include <iostream>
#include <queue>
using namespace std;

int n, k;
int dist[100001];
bool check[100001];
int main() {
	cin >> n >> k;
	deque<int> dq;
	check[n] = true;
	dq.push_back(n);
	while (!dq.empty()) {
		int now = dq.front();
		dq.pop_front();
		
		if(now == k) break;
		if (now * 2 <= 100000 && check[now * 2] == false) {
			dq.push_front(now * 2);
			check[now * 2] = true;
			dist[now * 2] = dist[now];
		}
		if (now - 1 >= 0 && check[now - 1] == false) {
			dq.push_back(now - 1);
			check[now - 1] = true;
			dist[now - 1] = dist[now] + 1;
		}
		if (now + 1 <= 100000 && check[now + 1] == false) {
			dq.push_back(now + 1);
			check[now + 1] = true;
			dist[now + 1] = dist[now] + 1;
		}
	}
	cout << dist[k];
}













/*
**solve1**

#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool check[100001];
int dist[100001];
int main() {
	cin >> n >> k;
	int t = 0;
	queue<int> q[2];
	q[t].push(n);
	check[n] = true;
	bool flag = false;
	while (!q[t].empty() || !q[t^1].empty()) {
		while (!q[t].empty()) {
			int now = q[t].front();
			q[t].pop();
			if (flag = (now == k)) break;
			
			if (now * 2 <= 100000 && check[now * 2] == false) {
				q[t].push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now];
			}
			if (now - 1 >= 0 && check[now - 1] == false) {
				q[t^1].push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
			if (now + 1 <= 100000 && check[now + 1] == false) {
				q[t^1].push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (flag) break;
		t ^= 1;
	}
	cout << dist[k];
}
*/