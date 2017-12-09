/*
����
� �뷮�� ���ϴ� ����� �ٿ��� �� ������,
���� �뷮�� ���ϴ� ������� ���ӵǾ� �ִ� ������ ������ ���� �� ���� �ִ밡 �Ǵ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����.
��° �ٺ��� N�� �ٿ��� ���� �� �ִ� ������� �� ����� ���ϴ� �뷮 B(i)�� �־�����.
B(i)�� 0���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
����̰� ���� �� �ִ� ���� ���̰� �� ���� �뷮�� ���ϴ� ����� ���� ������ ���̸� ����Ѵ�.
*/









/*
�̷����� ������ Ǯ �� �׻� �迭 �� ���ʿ��� ans�Ǵ��� �����༭ �ѵι��� Ʋ���� �ȴ�.
����س��� �ҵ�.

solution:
n<=1000�̹Ƿ� O(N^2)�� Ǭ��
��� ���� ���� ������ ��Ǯ����
ó���� �ƹ� ���� ���� �ʾ��� ���� ���� ���� �����ش�.
*/
#include <iostream>
using namespace std;

int n, p[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int ans = 1, cur = 1;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] == p[i + 1]) {
			cur++;
		}
		else {
			ans = (ans > cur) ? ans : cur;
			cur = 1;
		}
	}
	ans = (ans > cur) ? ans : cur;
	for (int i = 0; i < n; i++) {
		cur = 0;
		int last = -1;
		for (int j = 0; j < n; j++) {
			if (p[i] == p[j]) continue;
			if (last == -1) {
				cur++;
				last = p[j];
				continue;
			}
			else if (last != p[j]) {
				if (ans < cur) ans = cur;
				cur = 0;
			}
			cur++;
			last = p[j];
		}
		if (ans < cur) ans = cur;
	}
	cout << ans;
}