/*
문제
N이 주어질 때 hello + world = N을 만족하는 서로 다른 한 자리 자연수(0 포함)
d, e, h, l, o, r, w를 구해서 아래 그림과 같은 형태로 출력하는 프로그램을 작성하여라. 단, h와 w는 0이 될 수 없다.

입력
첫 번째 줄에 양의 정수 N이 주어진다. N은 32비트 정수 범위로 표현할 수 있는 수만 들어온다.

출력
만약 답이 없으면 'No Answer'을 출력한다. 그렇지 않은 경우 가능한 답들 중에서 아무거나 출력한다.
*/



/*
solution:
하드코딩 가즈아ㅏㅏㅏㅏㅏ
*/
#include <iostream>
using namespace std;

int h, e, l, o, w, r, d;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int h = 1; h < 10; h++) {
		for (int e = 0; e < 10; e++) {
			if (h == e) continue;
			for (int l = 0; l < 10; l++) {
				if (h == l || e == l)continue;
				for (int o = 0; o < 10; o++) {
					if (o == h || o == e || o == l)continue;
					for (int w = 1; w < 10; w++) {
						if (w == h || w == e || w == l || w == o)continue;
						for (int r = 0; r < 10; r++) {
							if (r == h || r == e || r == l || r == o || r == w)continue;
							for (int d = 0; d < 10; d++) {
								if (d == h || d == e || d == l || d == o || d == w || d == r) continue;
								int x = h * 10000 + e * 1000 + l * 100 + l * 10 + o;
								int y = w * 10000 + o * 1000 + r * 100 + l * 10 + d;
								if (x + y == n) {
									cout << "  " << h << e << l << l << o << '\n';
									cout << "+ " << w << o << r << l << d << '\n';
									cout << "-------\n";
									if (n < 99999)
										cout << "  " << n;
									else
										cout << " " << n;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No Answer";
}