/*
����
N*Mũ���� ���簢���� �ִ�. �� ĭ�� �� �ڸ� ���ڰ� ���� �ִ�.
�� ���簢������ �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã�� ���α׷��� �ۼ��Ͻÿ�.
�� ��, ���簢���� �� �Ǵ� ���� �����ؾ� �Ѵ�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� M�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ���� �־�����.

���
ù° �ٿ� ���� ���簢���� ũ�⸦ ����Ѵ�.
*/
#include <iostream>
using namespace std;

int n, m, p[51][51];
int main() {
	int ans = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			p[i][j] = x - '0';
		}
	}
	int l = (n < m) ? n : m;
	for(int k = 1; k<l; k++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (p[i][j] == p[i + k][j] && p[i + k][j] == p[i + k][j + k] && p[i + k][j + k] == p[i][j + k]) {
					ans = k + 1;
				}
			}
		}
	}
	cout << ans*ans;
}