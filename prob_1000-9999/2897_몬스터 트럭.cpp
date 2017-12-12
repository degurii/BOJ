/*
문제
해빈이를 도와 가능한 주차 공간을 해빈이가 부숴야 하는 차의 수대로 모아서 보여주자.
이 때 주차하기 위해 부숴야 하는 차만 고려한다. (주차 하러 가는 길에 부수는 차는 신경쓰지 않는다.)
단, 아무리 몬스터 트럭이라도 빌딩을 부술 수는 없기 때문에 빌딩이 있는 자리에는 주차를 할 수 없다.

입력
입력의 첫 줄에 두 정수 R과 C(2 ≤ R, C ≤ 50)가 주어진다. R은 행의 갯수, C는 열의 갯수이다.
두 번째 줄에는 R개의 줄에 각각 C개의 문자가 주어진다. 이 문자는 '#', 'X', '.'로만 이뤄져 있다. 'X'는 항상 영대문자이다.

출력
출력은 다섯 줄이다.
첫째 줄에는 해빈이가 아무 차도 부수지 않으면서 주차할 수 있는 공간의 갯수,
둘째 줄은 차 한 대를 부수고 주차할 수 있는 공간의 갯수,
셋째 줄은 차 두 대,
넷째 줄은 차 세 대,
다섯째 줄은 차 네 대를 부수고 주차할 수 있는 공간의 갯수이다.
*/
#include <iostream>
using namespace std;

int ans[6];
int p[51][51];
void check(int x, int y) {
	int k = 0;
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			if (p[i][j] == 1) k++;
			else if (p[i][j] == -1) return;
		}
	}
	ans[k]++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			cin >> c;
			if (c == '#') p[i][j] = -1;
			else if (c == 'X') p[i][j] = 1;
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (i + 1 <= r && j + 1 <= c) {
				check(i, j);
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << ans[i] << '\n';
	}
}