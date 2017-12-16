/*
문제
이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다.
보드의 크기와 보드판의 블럭 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블럭의 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다.
둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 블럭을 나타낸다.
블럭에 써있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블럭은 적어도 하나 주어진다.

출력
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블럭을 출력한다.
*/




/*
solution:
l을 기준으로 함수를 만든 뒤에
r, u, d에 복붙하고 범위와 i,j순서를 조정해주었다.
함수포인터를 이용해 0, 1, 2, 3에 각 함수를 맵핑했음.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vvi = vector<vector<int> >;

int n;

void l(vvi &p) {
	for (int i = 0; i < n; i++) {
	int prev = p[i][0], py = 0;
		for (int j = 1; j < n; j++) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				py = j;
			}
			else {
				p[i][py] *= 2;
				prev = p[i][py];
				p[i][j] = 0;
				prev = 0;
			}
		}
		py = 0;
		if (p[i][0] != 0)
			py = 1;
		for (int j = 1; j < n; j++) {
			if (p[i][j] == 0) continue;
			if (py != j) {
				p[i][py] = p[i][j];
				p[i][j] = 0;
			}
			py++;
		}
	}
}
void r(vvi &p) {
	for (int i = n-1; i >= 0; i--) {
		int prev = p[i][n - 1], py = n - 1;
		for (int j = n - 2; j >= 0; j--) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				py = j;
			}
			else {
				p[i][py] *= 2;
				prev = p[i][py];
				p[i][j] = 0;
				prev = 0;
			}
		}
		py = n-1;
		if (p[i][n-1] != 0)
			py = n-2;
		for (int j = n-2; j >= 0; j--) {
			if (p[i][j] == 0) continue;
			if (py != j) {
				p[i][py] = p[i][j];
				p[i][j] = 0;
			}
			py--;
		}
	}
}
void u(vvi &p) {
	for (int j = 0; j < n; j++) {
		int prev = p[0][j], px = 0;
		for (int i = 1; i < n; i++) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				px = i;
			}
			else {
				p[px][j] *= 2;
				prev = p[px][j];
				p[i][j] = 0;
				prev = 0;
			}
		}
		px = 0;
		if (p[0][j] != 0)
			px = 1;
		for (int i = 1; i < n; i++) {
			if (p[i][j] == 0) continue;
			if (px != i) {
				p[px][j] = p[i][j];
				p[i][j] = 0;
			}
			px++;
		}
	}
}
void d(vvi &p) {
	for (int j = n - 1; j >= 0; j--) {
		int prev = p[n-1][j], px = n-1;
		for (int i = n-2; i >= 0; i--) {
			if (p[i][j] == 0) continue;
			if (prev != p[i][j]) {
				prev = p[i][j];
				px = i;
			}
			else {
				p[px][j] *= 2;
				prev = p[px][j];
				p[i][j] = 0;
				prev = 0;
			}
		}
		px = n - 1;
		if (p[n-1][j] != 0)
			px = n - 2;
		for (int i = n - 2; i >= 0; i--) {
			if (p[i][j] == 0) continue;
			if (px != i) {
				p[px][j] = p[i][j];
				p[i][j] = 0;
			}
			px--;
		}
	}
}

void(*fp[4])(vvi&);


int foo(vvi &p, int cnt) {
	int m = 0;
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m = max(m, p[i][j]);
			}
		}
		return m;
	}
	
	for (int i = 0; i < 4; i++) {
		vvi p2(p);
		fp[i](p2);
		m = max(m, foo(p2, cnt + 1));
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vvi p(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	fp[0] = r;
	fp[1] = l;
	fp[2] = u;
	fp[3] = d;
	
	int ans = foo(p, 0);
	cout << ans;
}