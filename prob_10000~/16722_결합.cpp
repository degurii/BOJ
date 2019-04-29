/*
�Է�
ù ��° �ٺ��� ��ȩ �ٿ� ���� i(1 �� i �� 9)�� �׸��� ������ ���, ������ ��, ������ ��Ÿ���� Si, Ci, Bi�� �־�����.

Si�� {��CIRCLE��, ��TRIANGLE��, ��SQUARE��}, Ci�� {��YELLOW��, ��RED��, ��BLUE��}, Bi�� {��GRAY��, ��WHITE��, ��BLACK��} �� �ϳ��̴�. �� �Ӽ� ���̿��� ������ �ϳ� �־�����.
�� ��° �ٿ� �÷��̾��� ���� ����� �� n(1 �� n �� 100)�� �־����� ���� �ٺ��� n�ٿ� ���� ���� �� ���� �Է� �� �ϳ��� �־�����.

H a b c : �÷��̾ ���ա��̶�� �����Ǵ� ���� �ٸ� �׸��� ��ȣ a, b, c�� ��ģ �Է��̴�. (1 �� a, b, c �� 9)
G : �÷��̾ ���ᡯ�� ��ģ �Է��̴�.
���
ù ��° �ٿ� �÷��̾��� ���� ������ ����Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

bool comb[10][10][10], chk[10][10][10];
bool foo(const string &x, const string &xx, const string &xxx) {
	return (x == xx && xx == xxx) || (x != xx && xx != xxx && xxx != x);
}
void bar(int &a, int &b, int &c) {
	int l = min({ a, b, c });
	int r = max({ a, b, c });
	b = a + b + c - l - r;
	a = l;
	c = r;
}
tuple<string, string, string> p[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < 10; i++) {
		string x, y, z;
		cin >> x >> y >> z;
		p[i] = { x, y, z };
	}
	int kk = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			for (int k = j + 1; k < 10; k++) {
				auto[x, y, z] = p[i];
				auto[xx, yy, zz] = p[j];
				auto[xxx, yyy, zzz] = p[k];
				if(comb[i][j][k] = foo(x, xx, xxx) && foo(y, yy, yyy) && foo(z, zz, zzz)) kk++;
			}
		}
	}
	int n;
	cin >> n;
	char c;
	bool g = false;
	int ans = 0;
	while (n--) {
		cin >> c;
		if (c == 'H') {
			int a, b, c;
			cin >> a >> b >> c;
			bar(a, b, c);
			if (!chk[a][b][c] && comb[a][b][c]) {
				chk[a][b][c] = true;
				ans++;
				kk--;
			}
			else {
				ans--;
			}
		}
		else {
			if (!g && kk == 0) {
				g = true;
				ans += 3;
			}
			else {
				ans--;
			}
		}
	}
	cout << ans;
}
