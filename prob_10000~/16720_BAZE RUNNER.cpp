/*
�Է�
ù ��° �ٿ� �̷��� ũ�� N(3 �� N �� 1000)�� �־�����.
���� �ٺ��� N-2���� �ٿ��� �̷��� ���� �� �ٰ� ���� �Ʒ� ���� ������ �� ���� ������ �־�����.
���� �� 0(��), 1(��)�� �̷���� 4���� ��Ʈ�� �����Ǿ� ������, �� �ٸ��� ���� �� ���� ���� �����Ѵ�.

���
ù ��° �ٿ� �����̰� ����ϱ� ���� �ൿ�� �ּڰ��� ����Ѵ�.
*/
#include <cstdio>
#include <cmath>

int n, cnt[4];
int main() {
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%1d", &x);
			if (x == 0) cnt[j]++;
		}
	}
	int res = 0, ans = 0x3f3f3f3f;
	for (int i = 0; i < 4; i++) {
		res = 0;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			x = abs(i - j);
			if (x & 1) x = 1;
			res += x * cnt[j];
		}
		ans = ans < res ? ans : res;
	}
	ans += n + 2;
	printf("%d", ans);
}