/*
문제
가장 많은 케이크 조각을 받을 것으로 기대한 방청객의 번호와 실제로 가장 많은 케이크 조각을 받는 방청객의 번호를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 롤 케이크의 길이 L (1 ≤ L ≤ 1000)이 주어진다.
둘째 줄에는 방청객의 수 N (1 ≤ N ≤ 1000)이 주어진다.
다음 N개 줄에는 각 방청객 i가 종이에 적어낸 숫자 Pi와 Ki가 주어진다. (1 ≤ Pi ≤ Ki ≤ L, i = 1..N)

출력
첫째 줄에 가장 많은 조각을 받을 것으로 기대하고 있던 방청객의 번호를 출력한다.
둘째 줄에 실제로 가장 많은 조각을 받은 방청객의 번호를 출력한다.
가장 많은 조각을 받거나 예상되는 방청객이 여러 명인 경우에는 번호가 작은 사람을 출력한다.
*/
#include <iostream>
using namespace std;

int d[1001];
bool c[1001];
int l, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> n;
	int a1 = 0, a2 = 0, t1 = 0, t2 = 0;
	int u, v;
	for (int i = 1; i < n + 1; i++) {
		cin >> u >> v;
		if (t1 < v - u + 1) {
			t1 = v - u + 1;
			a1 = i;
		}
		int cnt = 0;
		for (int j = u; j < v + 1; j++) {
			if (!c[j]) {
				cnt++;
				c[j] = true;
			}
		}
		if (t2 < cnt) {
			t2 = cnt;
			a2 = i;
		}
	}
	cout << a1 << '\n' << a2;
}