/*
����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����.
����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �� �� �ִ� ��η� �̵��Ϸ� �Ѵ�.
�ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �� �� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.
���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.
���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��1,000), M(1��M��1,000)�� �־�����.
���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.
*/
/*
���� �μ�����, �Ⱥμ����·� ������
�Ⱥμ����� -> �Ⱥμ��� 0����, �μ��� 1�� ����
�μ����� -> �Ⱥμ��� 0���θ� ����
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, p[1001][1001], dist[1001][1001][2];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
struct Node {
	int x, y, b;
	Node(int x, int y, int b) :x(x), y(y), b(b) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			char c;
			cin >> c;
			p[i][j] = c - '0';
		}
	}
	queue<Node> q;
	q.push(Node(1, 1, 0));
	dist[1][1][0] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i], b = now.b;
			if (0 < nx && nx <= n && 0 < ny && ny <= m) {
				if (p[nx][ny] == 0 && dist[nx][ny][b] == 0) {
					q.push(Node(nx, ny, b));
					dist[nx][ny][b] = dist[now.x][now.y][b] + 1;
				}
				if (b == 0 && p[nx][ny] == 1 && dist[nx][ny][1] == 0) {
					dist[nx][ny][1] = dist[now.x][now.y][0] + 1;
					q.push(Node(nx, ny, 1));
				}
			}
		}
	}
	int ans = 0;
	int &d1 = dist[n][m][0], &d2 = dist[n][m][1];
	
	if (d1 == 0 && d2 == 0) {
		ans = -1;
	}
	else if (d1 != 0 && d2 != 0) {
		ans = (d1 < d2) ? d1 : d2;
	}
	else if (!d2) {
		ans = d1;
	}
	else if (!d1) {
		ans = d2;
	}
	cout << ans;
}