/*
문제
각 블럭의 높이가 주어질 때, 홍준이가 만들 수 있는 탑의 높이의 최대값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 조각의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
둘째 줄에 각 조각의 높이가 주어진다. 높이는 500,000보다 작거나 같은 자연수이고, 모든 조각의 높이의 합은 500,000을 넘지 않는다.

출력
첫째 줄에 문제의 정답을 출력한다. 불가능할 때는 -1을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int p[51], d[2][300000];
int n, idx, ridx;

int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	memset(d, -1, sizeof(d) / 2);
	d[0][0] = 0;

	for (int i = 1; i < n + 1; i++) {
		int h = p[i];
		if (h > 250000) continue;
		ridx = idx;
		idx ^= 1;
		for (int j = 0; j <= 250000; j++) {
			int &val = d[idx][j];
			val = d[ridx][j];
			if (h + j <= 250000 && d[ridx][h + j] != -1)
				val = max(val, d[ridx][h + j]);		// 더 낮은탑에 올림, 큰 게 여전히 더 큼

			if (j - h >= 0 && d[ridx][j - h] != -1) {
				val = max(val, d[ridx][j - h] + h);	// 더 높은탑에 올림
			}
			if (h - j >= 0 && d[ridx][h - j] != -1) {
				val = max(val, d[ridx][h - j] + j);	// 더 낮은탑에 올림, 높이가 바뀜
			}
		}
	}
	int &ans = d[idx][0];
	if (ans == 0) ans = -1;
	cout << ans;
}