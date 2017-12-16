/*
모든 쌍의 도시 사이의 최소 이동 시간이 주어졌을 때, 이 나라에 존재할 수 있는 도로의 개수의 최소값과
그 때, 모든 도로의 시간의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 20)이 주어진다.
둘째 줄부터 N개의 줄에 각각의 도시 사이에 이동하는데 필요한 시간 (≤ 10,000)이 주어진다.
A에서 B로 가는 시간과 B에서 A로 가는 시간은 같다. 또, A와 B가 같은 경우에는 필요한 시간은 0이다.

출력
첫째 줄에 도로 개수가 최소일 때, 모든 도로의 시간의 합을 출력한다. 불가능한 경우에는 -1을 출력한다.
*/







/*
아이디어가 잘 안떠올라서
다른사람이 올린 질문의 답을 좀 참고했다.
다음에 다시 풀어봐야 할듯.

solution:
주어진 표에서
d[i][j] == d[i][k] + d[k][j] 라면
i-j 사이의 도로가 없어도 된다는 말이므로 제거한다.
워셜 -플로이드로 모든 경로에 대해 위의 과정을 반복한다

만약 최종적으로 남은 도로들로 워셜-플로이드를 돌렸을 때
원래의 표와 다르다면 모순된 입력이므로 불가능한 경우이다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

int n, d[21][21], p[21][21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> p[i][j];
			d[i][j] = p[i][j];
		}
	}
	
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i == k || k == j) continue;
				if (p[i][j] == p[i][k] + p[k][j]) {
					d[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			ans += d[i][j];
			if (i != j && d[i][j] == 0) d[i][j] = inf;
		}
	}
	ans /= 2;
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (p[i][j] != d[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
}