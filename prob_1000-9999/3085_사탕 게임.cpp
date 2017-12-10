/*
문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.
가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다.
상근이는 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다.
이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.
사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)
다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
*/
#include <iostream>
using namespace std;

int n, p[51][51];
int ans = 0;

void foo() {
	for (int i = 1; i <= n; i++) {
		int len = 0, last = 0;
		for (int j = 1; j <= n + 1; j++) {
			if (last != p[i][j]) {
				ans = (ans > len) ? ans : len;
				last = p[i][j];
				len = 0;
			}
			if (j == n + 1) break;
			len++;
			last = p[i][j];
		}
	}
	for (int j = 1; j <= n; j++) {
		int len = 0, last = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (last != p[i][j]) {
				ans = (ans > len) ? ans : len;
				last = p[i][j];
				len = 0;
			}
			if (i == n + 1) break;
			len++;
			last = p[i][j];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			char c;
			cin >> c;
			if (c == 'C')
				p[i][j] = 1;
			else if (c == 'P')
				p[i][j] = 2;
			else if (c == 'Z')
				p[i][j] = 3;
			else if (c == 'Y')
				p[i][j] = 4;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n + 1; j++) {
			int &x = p[i][j];
			int &y = p[i + 1][j];
			x ^= y ^= x ^= y;
			foo();
			x ^= y ^= x ^= y;
		}
	}
	for (int j = 1; j < n + 1; j++) {
		for (int i = 1; i < n; i++) {
			int &x = p[i][j];
			int &y= p[i][j + 1];
			x ^= y ^= x ^= y;
			foo();
			x ^= y ^= x ^= y;
		}
	}
	cout << ans;
}