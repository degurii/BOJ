/*
문제
전구 100개가 10×10 정사각형 모양으로 늘어서 있다.
전구에 달린 스위치를 누르면 그 전구와 위, 아래, 왼쪽, 오른쪽에 있는 전구의 상태도 바뀐다.
전구 100개의 상태가 주어지면 모든 전구를 끄기 위해 최소한으로 눌러야 하는 스위치의 개수를 출력하라

입력
10줄에 10글자씩 입력이 주어진다. #은 꺼진 전구고 O(대문자 알파벳 o)는 켜진 전구다. #과 O외에는 입력으로 주어지지 않는다.

출력
모든 전구를 끄기 위해 최소한으로 눌러야 하는 스위치의 개수를 출력하라. 불가능하면 -1를 출력하라.
*/




/*
14927_전구끄기 문제랑 같은 문제.
코드 복붙함
https://github.com/degurii/BOJ/blob/master/prob_10000~/14927_%EC%A0%84%EA%B5%AC%20%EB%81%84%EA%B8%B0.cpp
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

int src[10], p[10];
void change(int x, int y) {
	p[x] ^= (1 << y);
	if (x - 1 >= 0) p[x - 1] ^= (1 << y);
	if (x + 1 < 10) p[x + 1] ^= (1 << y);
	if (y - 1 >= 0)p[x] ^= (1 << (y - 1));
	if (y + 1 < 10) p[x] ^= (1 << (y + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char x;
			cin >> x;
			if (x == 'O') src[i] |= (1 << j);
		}
	}

	int ans = INF;
	for (int k = 0; k < (1 << 10); k++) {
		memcpy(p, src, sizeof(src));
		int cnt = 0;
		for (int m = 0; m < 10; m++) {
			if (k &(1 << m)) {
				cnt++;
				change(0, m);
			}
		}

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p[i - 1] & (1 << j)) {
					cnt++;
					change(i, j);
				}
			}
		}
		if (p[9] != 0) cnt = INF;
		ans = (ans < cnt) ? ans : cnt;
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}
