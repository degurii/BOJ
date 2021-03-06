/*
문제
달팽이는 원점에서 시작하여 1초에 한 칸 씩, 시계방향으로 아래 그림과 같이 움직인다. (단, 1초일 때 달팽이의 위치는 (0, 1)이다.)
몇 초가 지났는지가 입력으로 주어질 때, 현재 달팽이의 위치를 좌표로 출력하시오.

입력
달팽이가 움직인 시간이 n초로 주어진다. (0 ≤ n ≤ 1000, n은 0이상의 정수)

출력
현재 달팽이의 위치를 x, y좌표 순서로 출력한다. Ex) 5 7
*/
#include <iostream>
using namespace std;

int n, x, y, dir, d[4] = { +1, +1, -1, -1 };
int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 1; 1; i++) {
		for (int j = 0; j < i; j++) {
			cnt++;
			x += d[dir];
			if (cnt == n) {
				cout << y << ' ' << x;
				return 0;
			}
		}
		dir++;
		dir %= 4;
		for (int j = 0; j < i; j++) {
			cnt++;
			y += d[dir];
			if (cnt == n) {
				cout << y << ' ' << x;
				return 0;
			}
		}
		dir++;
		dir %= 4;
	}
}