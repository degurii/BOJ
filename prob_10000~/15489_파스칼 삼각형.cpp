/*
이 때 R번째 줄, C번째 수를 위 꼭지점으로 하는 한 변이 포함하는 수의 개수가 W인 정삼각형과 그 내부를 생각하자.
정삼각형의 변과 그 내부에 있는 수들의 합을 구하고 싶다.
주어진 R, C, W에 대해서 그에 해당하는 합을 구하는 프로그램을 작성하여라.

입력
첫째 줄에 양의 정수 R, C, W가 공백을 한 칸씩 두고 차례로 주어진다. (단, 2 ≤ R+W ≤ 30, 2 ≤ C+W ≤ 30, 1 ≤ W ≤ 29, C ≤ R)

출력
첫째 줄에 R번째 줄, C번째 수를 위 꼭지점으로 하는 한 변이 포함하는 수의 개수가 W인 정삼각형과 그 내부에 있는 수들의 합을 출력한다.
*/


/*
solution
파스칼의 삼각형을 구한 뒤
r, c, w에 맞춰서 그냥 더한다
*/
#include <iostream>
using namespace std;

int d[31][31], r, c, w;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < 31; i++) {
		d[i][1] = d[i][i] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = 2; j < i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}
	int ans = 0;
	cin >> r >> c >> w;
	for (int i = r; i < r + w; i++) {
		for (int j = c; j - c < i - r + 1; j++) {
			ans+=d[i][j];
		}
	}
	cout << ans;
}