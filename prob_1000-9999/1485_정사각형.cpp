/*
����
�� ���� �־����� ��, �� ���� �̿��� ���簢���� ���� �� �ִ��� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����.
���� ��ǥ�� -100,000���� ũ�ų� ����, 100,000���� �۰ų� ���� �����̴�. ���� ���� �� �� �̻� �־����� �ʴ´�.

���
�� �׽�Ʈ ���̽����� �Է����� �־��� �� ���� �̿��ؼ� ���簢���� ���� �� ������ 1��, ������ 0�� ����Ѵ�.
*/







/*
solution:
�������´�� «
��� ���� ���̰� ����, �� �밢���� ���̰� ������ ���簢��
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
	double x, y;
	Node(double x = 0, double y = 0) :x(x), y(y) {}
} p[5];
int t;

double dist(Node x, Node y) {
	return sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		bool ok = false;
		for (int i = 1; i < 5; i++) cin >> p[i].x >> p[i].y;
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				if (i == j)continue;
				int a = 0, b = 0;
				for (int k = 1; i < 5; i++)
					if (k != i && k != j) {
						a = k;
						break;
					}
				for (int k = 1; k < 5; k++)
					if (k != i && k != j && k != a) {
						b = k;
						break;
					}

				if ((dist(p[i], p[a]) == dist(p[i], p[j]) || dist(p[i], p[b]) == dist(p[i], p[j])) && dist(p[i], p[j]) == dist(p[a], p[b]) && (dist(p[i], p[a]) == dist(p[j], p[b]) && dist(p[i], p[b]) == dist(p[j], p[a]))) {
					ok = true;
					break;
				}
			}
			if (ok)break;
		}
		cout << ok << '\n';
	}
}
