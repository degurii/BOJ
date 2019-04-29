/*
입력
첫 번째 줄에 미로의 크기 N(3 ≤ N ≤ 1000)이 주어진다.
다음 줄부터 N-2개의 줄에는 미로의 제일 위 줄과 제일 아래 줄을 제외한 각 줄의 정보가 주어진다.
줄은 총 0(길), 1(벽)로 이루어진 4개의 비트로 구성되어 있으며, 각 줄마다 오직 한 개의 길이 존재한다.

출력
첫 번째 줄에 세영이가 우승하기 위한 행동의 최솟값을 출력한다.
*/
#include <cstdio>
#include <cmath>

int n, cnt[4];
int main() {
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%1d", &x);
			if (x == 0) cnt[j]++;
		}
	}
	int res = 0, ans = 0x3f3f3f3f;
	for (int i = 0; i < 4; i++) {
		res = 0;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			x = abs(i - j);
			if (x & 1) x = 1;
			res += x * cnt[j];
		}
		ans = ans < res ? ans : res;
	}
	ans += n + 2;
	printf("%d", ans);
}