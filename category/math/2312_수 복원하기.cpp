/*
����
���� ���� N�� �־����� ��, �� ���� ���μ����� �� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����. �� �׽�Ʈ ���̽����� ���� ���� N (2 �� N �� 100,000)�� �־�����.

���
�� �׽�Ʈ ���̽����� �� �μ��� �� �μ��� ������ Ƚ���� �� �پ� ����Ѵ�. ��� ������ �μ��� �����ϴ� ������ �Ѵ�.
*/


/*
� �� n�� ���� n = a*b(a<=b, a,b�� �Ҽ�)�̸� a<=root(n)�̴�. (n = root(n)^2�̱� ����)
1) Ȯ���ؼ� n = a*b*...*c*d*e (a<b<...<c<d<e)�� �ϸ� �׻� a<=root(n)�̰�,
2) n/a = b*...*c*d*e -> b<=root(n/a)
3) 2)�� ���� ������ �ݺ��ϸ� {n/(a*b*...)}�� ���� �׻� root(n/(a*b*...))������ ���μ��� �� �� �̻� ���� �� �ִ�.
4) n/(a*b*...*c*d) = e
������ ���� e���� n�� ���μ��̴�.
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> m;
		for (int i = 2; i*i <= n;) {
			if (n%i == 0) {
				m[i]++;
				n /= i;
			}
			else i++;
		}
		m[n]++;
		for (auto it = m.begin(); it != m.end(); it++) {
			cout << it->first << ' ' << it->second << '\n';
		}
	}
}