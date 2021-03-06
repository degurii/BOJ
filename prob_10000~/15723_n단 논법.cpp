/*
입력
첫째줄에 정수 n(2 ≤ n ≤ 26)이 주어진다.
둘째줄부터 n개의 줄에 걸쳐 각 줄에 전제가 하나씩 주어진다.
전제는 모두 a is b의 형식으로 주어지며 a와 b는 서로 다른 임의의 알파벳 소문자이다.
특별한 명시는 없지만 모든 전제는 “모든 a는 b이다”라는 의미이다. 하지만 “모든 b는 a이다”의 의미는 될 수 없다. 또한 a는 b이면서 c일 수 없으나, a와 b가 동시에 c일 수는 있다.
n + 2번째줄에 정수 m(1 ≤ m ≤ 10)이 주어진다. 그 다음 m개의 줄에 걸쳐 각 줄에 하나의 결론이 전제와 같은 형식으로 주어진다.

출력
m개의 줄에 걸쳐 각 줄에 결론이 참인지 거짓인지 출력하라.
참일 경우 T, 거짓일 경우 F를 출력하라. 알 수 없는 경우도 거짓이다. 답은 필히 대문자로 출력해야 한다.
*/
#include <cstdio>

bool d[27][27];
int main() {
	int n;
	scanf("%d", &n);
	while (getchar() != '\n');
	char x, y;
	for (int i = 0; i < n; i++) {
		scanf("%c is %c ", &x, &y);
		d[x - 'a'][y - 'a'] = true;
	}
	
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (d[i][k] && d[k][j])
					d[i][j] = true;
			}
		}
	}
	int m;
	scanf("%d", &m);
	while (getchar() != '\n');
	for (int i = 0; i < m; i++) {
		scanf(" %c is %c", &x, &y);
		printf("%c\n", d[x - 'a'][y - 'a'] ? 'T' : 'F');
	}
}