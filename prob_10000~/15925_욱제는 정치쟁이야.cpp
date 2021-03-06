/*
문제
현재 컴퓨터실의 컴퓨터 전원 상태와, 다음 시간에 컴퓨터실을 사용하는 반이 있는지 여부가 주어진다!
욱제는 컴퓨터들을 다음 시간표에 맞게 모두 켜거나 끌 수 있을까?

입력
첫째 줄에 각 줄의 컴퓨터 개수 N과 이후의 컴퓨터실 사용 여부가 하나의 공백을 사이에 두고 주어진다.
사용 여부는 사용시 1, 미사용시 0으로 주어진다. (1 ≤ N ≤ 31, N % 2 == 1)
이후 둘째 줄부터 N*N의 컴퓨터실의 전원 상태가 주어진다. (i, j)의 컴퓨터가 켜져있으면 1, 꺼져있으면 0으로 표현되며 한 줄의 숫자들은 하나의 공백으로 구분된다.

출력
조건에 맞게 전원을 조작할 수 있다면 1을, 그렇지 않다면 0을 출력한다.
*/


/*
solution:
이러면 되지 않을까 했는데 진짜 됐다
*/
#include <iostream>
using namespace std;

int n, p[40][40], m;
void foo() {
	for (int i = 0; i < n; i++) {
		int mcnt = 0;
		for (int j = 0; j < n; j++) {
			if (p[i][j] == m) mcnt++;
		}
		if (mcnt > n / 2) {
			for (int j = 0; j < n; j++) {
				p[i][j] = m;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int mcnt = 0;
		for (int i = 0; i < n; i++) {
			if (p[i][j] == m) mcnt++;
		}
		if (mcnt > n / 2) {
			for (int i = 0; i < n; i++) {
				p[i][j] = m;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	foo();
	foo();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] != m) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}