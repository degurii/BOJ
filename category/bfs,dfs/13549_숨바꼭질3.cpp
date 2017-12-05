/*
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�.
�����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�.
�����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�.
�����̵��� �ϴ� ��쿡�� 0�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
*/





/*
solution1:
queue�ΰ��� �̿��� �ϳ��� 0�ʸ��� �� �� �ִ°�, �ٸ� �ϳ��� 1�ʸ��� �� �� �ִ� ������ �ϰ�
0�ʸ��� ���� queue�� ���빰��� queue�鿡 push�Ѵ�
�ѹ��� �� ������ q[0], q[1]�� ��ü -> t ^= 1;


solution2:
deque�� �̿��Ѵ�
0�ʸ��� ���°��� deque�� �տ�
1�ʸ��� ���°��� deque�� �ڿ� �ִ´�
(�ڵ尡 �ξ� �����ϴ�)
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