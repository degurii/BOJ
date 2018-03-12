/*
����
�������� �Ϸķ� ���� �ִ� ¡�˴ٸ� ���̸� ��¦��¦ �پ�ٴϰ� �ִ�.
¡�˴ٸ����� ���ڰ� ���� ���� �ִµ�,
�� �������� �ſ� Ư���� ���������� � ¡�˴ٸ����� ������ �� ���� �� ¡�˴ٸ��� ���� �ִ� ���� �����ŭ ������ �ִ� �����θ� �� �� �ִ�.

�� �������� a��° ¡�˴ٸ����� b��° ¡�˴ٸ����� ������ �Ѵ�.
�� �������� a��° ¡�˴ٸ����� �����Ͽ� �ּ� �� �� ������ �Ͽ� b��° ¡�˴ٸ����� �� �� �ִ����� �˾ƺ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ¡�˴ٸ��� ���� N(1��N��10,000)�� �־�����, �̾ �� ¡�˴ٸ��� ���� �ִ� N���� ������ �־�����.
�� ���� �ٿ��� N���� �۰ų� ���� �ڿ��� a, b�� �־����� ��, �̴� �������� a�� ¡�˴ٸ����� �����Ͽ� b�� ¡�˴ٸ��� ���� �ʹٴ� ���̴�.
¡�˴ٸ��� �����ִ� ������ 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� �������� a�� ¡�˴ٸ����� b�� ¡�˴ٸ��� �ּ� �� �� �����Ͽ� �� �� �ִ� ���� ����Ͻÿ�.
a���� b�� �� �� ���� ��쿡�� -1�� ����Ѵ�.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, p[10001], dist[10001];
bool check[10001];
int a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	memset(dist, -1, sizeof(dist));
	cin >> a >> b;
	dist[a] = 0;
	check[a] = true;
	queue<int> q;
	q.push(a);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == b)
			break;
		for (int next = now + p[now]; next <= n; next += p[now]) {
			if (!check[next]) {
				check[next] = true;
				q.push(next); 
				dist[next] = dist[now] + 1;
			}
		}

		for (int next = now - p[now]; next > 0; next -= p[now]) {
			if (!check[next]) {
				check[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
	cout << dist[b];
}