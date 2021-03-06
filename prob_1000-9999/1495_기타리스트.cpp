/*
곡의 개수 N과 시작 볼륨 S, 그리고 M이 주어졌을 때, 마지막 곡을 연주할 수 있는 볼륨 중 최대값을 구하는 프로그램을 작성하시오.
모든 곡은 리스트에 적힌 순서대로 연주해야 한다.  

입력
첫째 줄에 곡의 개수 N, 시작 볼륨 S, M이 주어진다. (1 ≤ N ≤ 100, 1 ≤ M ≤ 1000, 0 ≤ S ≤ M)
둘째 줄에는 각 곡이 시작하기 전에 줄 수 있는 볼륨의 차이가 주어진다.
이 값은 1보다 크거나 같고, M보다 작거나 같다.

출력
첫째 줄에 가능한 마지막 곡의 볼륨 중 최대값을 출력한다.
만약 마지막 곡을 연주할 수 없다면 (중간에 볼륨 조절을 할 수 없다면) -1을 출력한다.
*/
#include <iostream>
using namespace std;

int n, s, m;
bool d[101][1001];
int main() {
	cin >> n >> s >> m;
	d[0][s] = true;
	int x;
	for (int i = 1; i < n + 1; i++) {
		cin >> x;
		for (int j = 0; j < m + 1; j++) {
			if (!d[i - 1][j]) continue;
			if (j + x <= m) {
				d[i][j + x] = true;
			}
			if (j - x >= 0) {
				d[i][j - x] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < m + 1; i++) {
		if (d[n][i]) ans = i;
	}
	cout << ans;
}