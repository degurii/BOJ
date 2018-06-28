/*
N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �����Ǿ��ִ�.
ù° �ٿ� N�� �־�����. N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
�� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.
*/


/*
solution:
n<=40�̹Ƿ� O(2^N)���� ���غ��°� �Ұ����ϴ�.
dp�� �̿��ϴµ� �Ǻ���ġ���� �ƴ϶� 0�� 1�� ������ �����Ѵ�
*/
#include <iostream>
using namespace std;
using pii = pair<int, int>;

int n, t;
pii d[50];
pii operator + (const pii &a, const pii &b) {
	return { a.first + b.first, a.second + b.second };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	d[0] = { 1, 0 };
	d[1] = { 0, 1 };
	for (int i = 2; i <= 40; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << d[n].first << ' ' << d[n].second << '\n';
	}
}
