/*
����
N�� �־��� �� hello + world = N�� �����ϴ� ���� �ٸ� �� �ڸ� �ڿ���(0 ����)
d, e, h, l, o, r, w�� ���ؼ� �Ʒ� �׸��� ���� ���·� ����ϴ� ���α׷��� �ۼ��Ͽ���. ��, h�� w�� 0�� �� �� ����.

�Է�
ù ��° �ٿ� ���� ���� N�� �־�����. N�� 32��Ʈ ���� ������ ǥ���� �� �ִ� ���� ���´�.

���
���� ���� ������ 'No Answer'�� ����Ѵ�. �׷��� ���� ��� ������ ��� �߿��� �ƹ��ų� ����Ѵ�.
*/



/*
solution:
�ϵ��ڵ� ����Ƥ���������
*/
#include <iostream>
using namespace std;

int h, e, l, o, w, r, d;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int h = 1; h < 10; h++) {
		for (int e = 0; e < 10; e++) {
			if (h == e) continue;
			for (int l = 0; l < 10; l++) {
				if (h == l || e == l)continue;
				for (int o = 0; o < 10; o++) {
					if (o == h || o == e || o == l)continue;
					for (int w = 1; w < 10; w++) {
						if (w == h || w == e || w == l || w == o)continue;
						for (int r = 0; r < 10; r++) {
							if (r == h || r == e || r == l || r == o || r == w)continue;
							for (int d = 0; d < 10; d++) {
								if (d == h || d == e || d == l || d == o || d == w || d == r) continue;
								int x = h * 10000 + e * 1000 + l * 100 + l * 10 + o;
								int y = w * 10000 + o * 1000 + r * 100 + l * 10 + d;
								if (x + y == n) {
									cout << "  " << h << e << l << l << o << '\n';
									cout << "+ " << w << o << r << l << d << '\n';
									cout << "-------\n";
									if (n < 99999)
										cout << "  " << n;
									else
										cout << " " << n;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No Answer";
}