/*
����
���ڵ� �� ���ڿ��� ���ڵ��ϴµ� ����� m�� p1, ..., pn�� �־����� ��, ���ڵ� �ϱ� �� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (���ڵ�)

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� n�� m�� �־�����. (1 �� n �� 80, 1 �� m �� 109)
���� �ٿ��� ���ڵ��ϴµ� ����� n���� ���� �ٸ� ���� p1, ..., pn�� �־�����. (1 �� pi �� n)
��° �ٿ��� ���ڵ��� ���ڿ��� �־�����. �Է��� ������ �ٿ��� 0�� �� �� �ִ�.

���
�� �׽�Ʈ ���̽��� ���ؼ� ���ڵ��� ���ڿ��� ����Ѵ�.
*/



/*
solution:
ù��° ����
m�� ������ ū ����� �־��� ���ڿ��� ���� p�� ������ �����鼭
���� ���ڿ��� ���ƿö������� Ƚ��(���� lotation)�� ī���� �Ͽ� m�� �� Ƚ���� mod�����ؼ� m�� ����
���� a)�� ����

���� m��ŭ ���ڿ��� ������ �ݺ������� �ٲ�
�̰� b)�� ����
-> �ð��ʰ�

�ι�° ����
lotation�� ���ϴµ����� ���� �ð��� �Һ�ȴٰ� ������
���� p�� �� �����Ҹ��� ����Ŭ�� ������ �׷������ ���� �߰�
�� �������� ��������� �ּҰ������ ���� ���ٿ��� ���Ϸ��� lotation�� ���̱� ������
�� �����ð����� lotation �� ���� �� ����
 
-> �׷��� �ð��ʰ�
���� - a)�� ������ �ð��� ����, �׷��� b)�� ������ �ð��� ������� ����

�ι�°���� Ʋ�� ����
m�� lotation���� ���� ������ ���� lotation�� ������ ���� ���� �ִٴ� ���� ������
�̹� ù��° ���ٿ��� lotation�� �ݺ������� ���Ҷ� �ð��ʰ��� ����,
b)�� ���� ���� lotation��ŭ �ݺ��ϴ� �����̱� ������ �ð��ʰ��� �� �� �ۿ� ����
�ٸ� ������� �����ؾ� ��

����° ����
lotatoin�� ���ڿ� ��ü�� �ʱ���·� ���ƿö������� �ݺ�Ƚ���� �ƴ϶�
����Ŭ���� ���� ���� �� �����ҿ��� ����Ŭ�� �ѹ� �ݺ��ɶ������� Ƚ���� ������
�� ����Ŭ�� indegree�� outdegree�� 1�� �׷����̹Ƿ�, ����Ŭ�� �ѹ� �ݺ��Ǵµ��� ����Ŭ�� �����ŭ �ҿ��

���� �� �����ҿ� ���� m�� �������� ������� mod�����Ͽ� ���̰�, �ش�Ǵ� ����鳢�� ���� m��ŭ ������ �ٲ�
(m % size) < size �̰�, n<=80�̱� ������ size<=80 �� ����� ���� ��ġ�� �ٲٴ� �ݺ��� Ƚ���� ���� �ð����⵵�� ������ ����
-> �¾ҽ��ϴ�

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;

int _hash[90], p2[90], p1[90];
char s[90];

bool check[90];
vector<vector<pair<int, int> > > group;
int g = -1;
void dfs(int now, int num) {
	check[now] = true;
	int next = _hash[now];
	group[num].push_back({ now, next });
	if (!check[next])
		dfs(next, num);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		group.clear();
		g = -1;
		memset(check, 0, sizeof(check));
		int n;
		ll m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			_hash[x - 1] = i;
		}

		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				group.push_back(vector<pair<int, int> >());
				dfs(i, ++g);
			}
		}
		
		cin.ignore();
		cin.getline(s, n + 1);
		
		copy(s, s + sizeof(s), p1);
		copy(s, s + sizeof(s), p2);
		for (auto it : group) {
			int m2 = m % it.size();
			while (m2--) {
				for (auto jt : it) {
					int u = jt.first, v = jt.second;
					p2[u] = p1[v];
				}
				copy(p2, p2 + n, p1);
			}
		}
		
		for (int i = 0; i < n; i++)
			cout.put(p1[i]);
		cout << '\n';
	}
}