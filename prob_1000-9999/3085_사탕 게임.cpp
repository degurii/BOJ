/*
����
����̴� ����� ���� "������ (Bomboni)" ������ ����ߴ�.
���� ó���� N��Nũ�⿡ ������ ä�� ���´�. ������ ���� ��� ���� ���� ���� �ִ�.
����̴� ������ �� ĭ�� ����. �� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�.
����, ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� �� ������ ��� �Դ´�.
������ ä���� ���°� �־����� ��, ����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (3 �� N �� 50)
���� N�� �ٿ��� ���忡 ä���� �ִ� ������ ������ �־�����. �������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y�� �־�����.

���
ù° �ٿ� ����̰� ���� �� �ִ� ������ �ִ� ������ ����Ѵ�.
*/
#include <iostream>
using namespace std;

int n, p[51][51];
int ans = 0;

void foo() {
	for (int i = 1; i <= n; i++) {
		int len = 0, last = 0;
		for (int j = 1; j <= n + 1; j++) {
			if (last != p[i][j]) {
				ans = (ans > len) ? ans : len;
				last = p[i][j];
				len = 0;
			}
			if (j == n + 1) break;
			len++;
			last = p[i][j];
		}
	}
	for (int j = 1; j <= n; j++) {
		int len = 0, last = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (last != p[i][j]) {
				ans = (ans > len) ? ans : len;
				last = p[i][j];
				len = 0;
			}
			if (i == n + 1) break;
			len++;
			last = p[i][j];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			char c;
			cin >> c;
			if (c == 'C')
				p[i][j] = 1;
			else if (c == 'P')
				p[i][j] = 2;
			else if (c == 'Z')
				p[i][j] = 3;
			else if (c == 'Y')
				p[i][j] = 4;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n + 1; j++) {
			int &x = p[i][j];
			int &y = p[i + 1][j];
			x ^= y ^= x ^= y;
			foo();
			x ^= y ^= x ^= y;
		}
	}
	for (int j = 1; j < n + 1; j++) {
		for (int i = 1; i < n; i++) {
			int &x = p[i][j];
			int &y= p[i][j + 1];
			x ^= y ^= x ^= y;
			foo();
			x ^= y ^= x ^= y;
		}
	}
	cout << ans;
}