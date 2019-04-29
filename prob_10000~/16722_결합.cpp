/*
입력
첫 번째 줄부터 아홉 줄에 걸쳐 i(1 ≤ i ≤ 9)번 그림의 도형의 모양, 도형의 색, 배경색을 나타나는 Si, Ci, Bi가 주어진다.

Si는 {“CIRCLE”, “TRIANGLE”, ”SQUARE”}, Ci는 {“YELLOW”, “RED”, “BLUE”}, Bi는 {“GRAY”, “WHITE”, “BLACK”} 중 하나이다. 각 속성 사이에는 공백이 하나 주어진다.
열 번째 줄에 플레이어의 게임 기록의 수 n(1 ≤ n ≤ 100)이 주어지고 다음 줄부터 n줄에 걸쳐 다음 두 가지 입력 중 하나가 주어진다.

H a b c : 플레이어가 ‘합’이라고 생각되는 서로 다른 그림의 번호 a, b, c를 외친 입력이다. (1 ≤ a, b, c ≤ 9)
G : 플레이어가 ‘결’을 외친 입력이다.
출력
첫 번째 줄에 플레이어의 최종 점수를 출력한다.
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
