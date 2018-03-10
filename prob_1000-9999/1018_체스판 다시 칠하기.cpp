/*
ü������ �� ���簢���� ���� �Ǵ� ����̸�, ���� �����ϴ� �� ���� �簢���� ���� ���� �ƴ� �� �̴�.
���� �� ���ǿ� ���ϸ� ü������ ���� �׻� �� ������ �����ѵ�, �ϳ��� ���� �� �ڳʰ� ����� ��, �������� �� �ΰ����̴�.

�Է�
ù° �ٿ� N�� M�� �־�����. M�� N�� 8���� ũ�ų� ����, 50���� �۰ų� ���� �ڿ����̴�
��° �ٺ��� N�� �ٿ��� ü������ �� ���°� �־�����. B�� �������̸�, W�� ����̴�.

���
ù° �ٿ� �����̰� 8*8ũ��� �ڸ� �ڿ� �ٽ� ĥ�ؾ��ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.
*/



/*
sliding window�� ���غ���
*/
#include <iostream>
using namespace std;

int ori1[8][8], ori2[8][8], p[51][51];
int cmp(int x, int y) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (ori1[i - x][j - y] != p[i][j]) {
				cnt1++;
			}
			if (ori2[i - x][j - y] != p[i][j]) {
				cnt2++;
			}
		}
	}
	return (cnt1 < cnt2) ? cnt1 : cnt2;
}
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == 'W')
				p[i][j] = 1;
			else
				p[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) & 1) {
				ori1[i][j] = 0;
				ori2[i][j] = 1;
			}
			else {
				ori1[i][j] = 1;
				ori2[i][j] = 0;
			}
		}
	}
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			ans = min(ans, cmp(i, j));
		}
	}
	cout << ans;
}