/*
�Է�
ù ��° �ٿ� ����� ���� n(3 �� n �� 5000)�� �־�����.
��° �ٺ��� n�� ���� �� �ٸ��� n���� ����� ���谡 �־�����.  i+1��° ���� j��° ���ڰ� �� + �� �� ��� ģ��, ' - ' �� ��� ��, ' 0 '�� �ڱ� �ڽ��� ���Ѵ�.
�� ���� �ٿ��� ������ ���� m(1 �� m �� 100)�� �־�����.
���� m�� ���� ��� B�� ��ȣ b(0 �� b < n), ��� C�� ��ȣ c(0 �� c < n)�� �־�����.
�� ���� 0���� n-1������ ���� ǥ���ǰ� B, C�� ���� �ٸ� ��� ��ȣ�� �־�����.

���
m�ٵ��� B�� C�� ���踦 ����Ѵ�.
*/
#include <iostream>
using namespace std;

int n, m, val;
char x, p[5001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (i != 0) continue;
			p[j] = x;
		}
	}
	cin >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		if (u == 0 || v == 0) cout << p[u + v] << '\n';
		else if (p[u] == p[v]) cout << "+\n";
		else cout << "-\n";
	}
}