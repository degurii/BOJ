/*
입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때 잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다.
색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다.
하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.
*/


/*
solution:
나눈다
센다
출력한다
*/
#include <iostream>
using namespace std;

int n, p[200][200];
int blue, white;
bool isValid(int m, int x, int y) {
	int k = p[x][y];
	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			if (k != p[i][j])
				return false;
		}
	}
	if (k == 1) blue++;
	else white++;
	return true;
}

void foo(int m, int x, int y) {
	if (isValid(m, x, y)) {
		return;
	}
	foo (m / 2, x, y);
	foo(m / 2, x + m / 2, y);
	foo(m / 2, x, y + m / 2);
	foo(m / 2, x + m / 2, y + m / 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	foo(n, 0, 0);
	cout << white << '\n' << blue;
}