/*
문제
다음 16진법 식이 성립하도록 각 영문자에 0 ∼ f 사이의 16진수를 배정하라.
단, 서로 다른 영문자에는 서로 다른 숫자가 배정되어야 하며, 각 수의 첫 글자는 0이 될 수 없다.

입력
없다.

출력
첫 번째 줄부터 모든 해답을 한 줄에 한 개씩 사전순으로 출력한다.
각 해답은 LIST + FILO = STACK 의 형태로 16진수로 표현해야 하며, a, b, c, d, e, f 는 대소문자를 구분하지 않는다.

 LIST
+FILO
-----
STACK

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f 의 순서를 사전순으로 간주한다.
*/


/*
solution;
l, i, s, t, f, o가 결정되면
결과값이 5자리인지, 앞 두자리가 각각 s, t와 같은지, 뒤 세자리 각각이 모두 다르고 l, i, s, t, f, o와 다른지 확인하면 된다.
브루트포스로 시간복잡도는 (5*16^6)
5는 계산한 결과값을 16진수로 바꾸는 시간
*/
#include <iostream>
using namespace std;

int l, i, s, t, f, o;
bool check(int x) {
	return (x != l && x != i && x != s && x != t && x != f && x != o);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	for (l = 0; l < 16; l++) {
		for (i = 0; i < 16; i++) {
			if (i == l) continue;
			for (s = 0; s < 16; s++) {
				if (s == l || s == i) continue;
				for (t = 0; t < 16; t++) {
					if (t == l || t == i || t == s) continue;
					for (f = 0; f < 16; f++) {
						if (f == l || f == i || f == s || f == t)continue;
						for (o = 0; o < 16; o++) {
							if (o == l || o == i || o == s || o == t || o == f) continue;
							int a = l * (1 << 12) + i * (1 << 8) + s * (1 << 4) + t;
							int b = f * (1 << 12) + i * (1 << 8) + l * (1 << 4) + o;
							int c = a + b;
							if (c < (1 << 16)) continue;
							int p[5] = { -1, -1, -1, -1, -1 };
							for (int idx = 4; c > 0; idx--) {
								p[idx] = c % 16;
								c /= 16;
							}
							if (p[0] != -1) {
								if (p[0] == s && p[1] == t && (p[2] != p[3] && p[3] != p[4] && p[4] != p[2]) && check(p[2]) && check(p[3]) && check(p[4])) {
									cout << hex << l << i << s << t << " + " << f << i << l << o << " = " << p[0] << p[1] << p[2] << p[3] << p[4] << '\n';
								}
							}
						}
					}
				}
			}
		}
	}
}