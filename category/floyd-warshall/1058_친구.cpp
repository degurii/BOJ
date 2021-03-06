/* 문제
지민이는 세계에서 가장 유명한 사람이 누구인지 궁금해졌다.
가장 유명한 사람을 구하는 방법은 각 사람의 2-친구를 구하면 된다.
어떤 사람 A가 또다른 사람 B의 2-친구가 되기 위해선, 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재해야 된다.
여기서 가장 유명한 사람은 2-친구의 수가 가장 많은 사람이다. 가장 유명한 사람의 2-친구의 수를 출력하는 프로그램을 작성하시오.

A와 B가 친구면, B와 A도 친구이고, A와 A는 친구가 아니다.

입력
첫째 줄에 사람의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에 각 사람이 친구이면 Y, 아니면 N이 주어진다. (예제를 참고)

출력
첫째 줄에 가장 유명한 사람의 2-친구의 수를 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int p[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	fill(&p[0][0], &p[0][0] + 51 * 51, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (i == j)
				p[i][j] = 0;
			else if (c == 'Y')
				p[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if(p[i][j] <= 2)
				cnt++;
		}
		ans = ans > cnt ? ans : cnt;
	}
	cout << ans;
}