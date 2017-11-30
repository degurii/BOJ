/*
문제
N개의 정수로 이루어진 집합이 있을 때, 이 집합의 공집합이 아닌 부분집합 중에서
그 집합의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1≤N≤20, |S|≤1,000,000)
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절대값은 100,000을 넘지 않는다. 같은 수가 여러번 주어질 수도 있다.

출력
첫째 줄에 합이 S가 되는 부분집합의 개수를 출력한다.
*/


/*
solve:
n<=20 이므로 O(2^N)으로 다 해보면 된다
*/
#include <iostream>
using namespace std;

int n, s, p[20];
int ans;

void go(int sum, int idx, bool last) {
	if (sum == s && last) {
		ans++;
	}
	if (idx == n) {
		return;
	}
	go(sum + p[idx], idx + 1, true);
	go(sum, idx + 1, false);
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	go(0, 0, false);
	cout << ans;
}