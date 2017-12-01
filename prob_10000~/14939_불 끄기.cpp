/*
����
���� 100���� 10��10 ���簢�� ������� �þ �ִ�.
������ �޸� ����ġ�� ������ �� ������ ��, �Ʒ�, ����, �����ʿ� �ִ� ������ ���µ� �ٲ��.
���� 100���� ���°� �־����� ��� ������ ���� ���� �ּ������� ������ �ϴ� ����ġ�� ������ ����϶�

�Է�
10�ٿ� 10���ھ� �Է��� �־�����. #�� ���� ������ O(�빮�� ���ĺ� o)�� ���� ������. #�� O�ܿ��� �Է����� �־����� �ʴ´�.

���
��� ������ ���� ���� �ּ������� ������ �ϴ� ����ġ�� ������ ����϶�. �Ұ����ϸ� -1�� ����϶�.
*/




/*
14927_�������� ������ ���� ����.
�ڵ� ������
https://github.com/degurii/BOJ/blob/master/prob_10000~/14927_%EC%A0%84%EA%B5%AC%20%EB%81%84%EA%B8%B0.cpp
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

int src[10], p[10];
void change(int x, int y) {
	p[x] ^= (1 << y);
	if (x - 1 >= 0) p[x - 1] ^= (1 << y);
	if (x + 1 < 10) p[x + 1] ^= (1 << y);
	if (y - 1 >= 0)p[x] ^= (1 << (y - 1));
	if (y + 1 < 10) p[x] ^= (1 << (y + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char x;
			cin >> x;
			if (x == 'O') src[i] |= (1 << j);
		}
	}

	int ans = INF;
	for (int k = 0; k < (1 << 10); k++) {
		memcpy(p, src, sizeof(src));
		int cnt = 0;
		for (int m = 0; m < 10; m++) {
			if (k &(1 << m)) {
				cnt++;
				change(0, m);
			}
		}

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p[i - 1] & (1 << j)) {
					cnt++;
					change(i, j);
				}
			}
		}
		if (p[9] != 0) cnt = INF;
		ans = (ans < cnt) ? ans : cnt;
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}
