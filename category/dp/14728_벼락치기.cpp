/*
문제
여러 단원을 융합한 문제는 출제하지 않는다.
한 단원에 한 문제를 출제한다. 단, 그 단원에 모든 내용을 알고 있어야 풀 수 있는 문제를 낼 것이다.
이런 두가지 힌트와 함께 각 단원 별 배점을 적어 놓으셨다.
어떤 단원의 문제를 맞추기 위해서는 그 단원의 예상 공부 시간만큼, 혹은 그보다 더 많이 공부하면 맞출 수 있다고 가정하자.
이 때, ChAOS 회장 일로 인해 힘든 준석이를 위하여 남은 시간 동안 공부해서 얻을 수 있는 최대 점수를 구하는 프로그램을 만들어 주도록 하자.

입력
첫째 줄에는 이번 시험의 단원 개수 N(1 ≤ N ≤ 100)과 시험까지 공부 할 수 있는 총 시간 T(1 ≤ T ≤ 10000)가 공백을 사이에 두고 주어진다.
둘째 줄부터 N 줄에 걸쳐서 각 단원 별 예상 공부 시간 K(1 ≤ K ≤ 1000)와 그 단원 문제의 배점 S(1 ≤ S ≤ 1000)가 공백을 사이에 두고 주어진다.

출력
첫째 줄에 준석이가 얻을 수 있는 최대 점수를 출력한다.
*/




/*
solution:
d[t] = 시간 t만큼 써서 얻을 수 있는 점수의 최댓값
d[i+now.t] = max(d[i+now.t], d[i]+now.score) (i+now.t <= 제한시간)

dp를 제대로 공부해 본 적이 없어서 정확한 코드인지는 모르겠다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, t, d[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int k, s;
		cin >> k >> s;
		for (int j = t - k; j > 0; j--) {
			if (d[j]) {
				d[j + k] = max(d[j + k], d[j] + s);
			}
		}
		d[k] = max(d[k], s);
	}
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		ans = max(d[i], ans);
	}
	cout << ans;
}