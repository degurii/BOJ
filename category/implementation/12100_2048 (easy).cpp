/*
����
�� �������� �ٷ�� 2048 ������ ������ ũ�Ⱑ N��N �̴�.
������ ũ��� �������� �� ���°� �־����� ��, �ִ� 5�� �̵��ؼ� ���� �� �ִ� ���� ū ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N (1 �� N �� 20)�� �־�����.
��° �ٺ��� N���� �ٿ��� �������� �ʱ� ���°� �־�����. 0�� �� ĭ�� ��Ÿ����, �̿��� ���� ��� ���� ��Ÿ����.
���� ���ִ� ���� 2���� ũ�ų� ����, 1024���� �۰ų� ���� 2�� �������̴�. ���� ��� �ϳ� �־�����.

���
�ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ���� ����Ѵ�.
*/




/*
solution:
l�� �������� �Լ��� ���� �ڿ�
r, u, d�� �����ϰ� ������ i,j������ �������־���.
�Լ������͸� �̿��� 0, 1, 2, 3�� �� �Լ��� ��������.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vvi = vector<vector<int> >;

int n;

void l(vvi &p) {
	for (int i = 0; i < n; i++) {
	int prev = p[i][0], py = 0;
		for (int j = 1; j < n; j++) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				py = j;
			}
			else {
				p[i][py] *= 2;
				prev = p[i][py];
				p[i][j] = 0;
				prev = 0;
			}
		}
		py = 0;
		if (p[i][0] != 0)
			py = 1;
		for (int j = 1; j < n; j++) {
			if (p[i][j] == 0) continue;
			if (py != j) {
				p[i][py] = p[i][j];
				p[i][j] = 0;
			}
			py++;
		}
	}
}
void r(vvi &p) {
	for (int i = n-1; i >= 0; i--) {
		int prev = p[i][n - 1], py = n - 1;
		for (int j = n - 2; j >= 0; j--) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				py = j;
			}
			else {
				p[i][py] *= 2;
				prev = p[i][py];
				p[i][j] = 0;
				prev = 0;
			}
		}
		py = n-1;
		if (p[i][n-1] != 0)
			py = n-2;
		for (int j = n-2; j >= 0; j--) {
			if (p[i][j] == 0) continue;
			if (py != j) {
				p[i][py] = p[i][j];
				p[i][j] = 0;
			}
			py--;
		}
	}
}
void u(vvi &p) {
	for (int j = 0; j < n; j++) {
		int prev = p[0][j], px = 0;
		for (int i = 1; i < n; i++) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				px = i;
			}
			else {
				p[px][j] *= 2;
				prev = p[px][j];
				p[i][j] = 0;
				prev = 0;
			}
		}
		px = 0;
		if (p[0][j] != 0)
			px = 1;
		for (int i = 1; i < n; i++) {
			if (p[i][j] == 0) continue;
			if (px != i) {
				p[px][j] = p[i][j];
				p[i][j] = 0;
			}
			px++;
		}
	}
}
void d(vvi &p) {
	for (int j = n - 1; j >= 0; j--) {
		int prev = p[n-1][j], px = n-1;
		for (int i = n-2; i >= 0; i--) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				px = i;
			}
			else {
				p[px][j] *= 2;
				prev = p[px][j];
				p[i][j] = 0;
				prev = 0;
			}
		}
		px = n - 1;
		if (p[n-1][j] != 0)
			px = n - 2;
		for (int i = n - 2; i >= 0; i--) {
			if (p[i][j] == 0) continue;
			if (px != i) {
				p[px][j] = p[i][j];
				p[i][j] = 0;
			}
			px--;
		}
	}
}

void(*fp[4])(vvi&);


int foo(vvi &p, int cnt) {
	int m = 0;
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m = max(m, p[i][j]);
			}
		}
		return m;
	}
	
	for (int i = 0; i < 4; i++) {
		vvi p2(p);
		fp[i](p2);
		m = max(m, foo(p2, cnt + 1));
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vvi p(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	fp[0] = r;
	fp[1] = l;
	fp[2] = u;
	fp[3] = d;
	
	int ans = foo(p, 0);
	cout << ans;
}