/*
문제
랭퍼드 수열은 다음 조건을 만족하는 길이 2n의 수열이다.

1 이상 n 이하의 자연수가 각각 두 개씩 들어 있다.
두 개의 1 사이에는 정확히 1개의 수가 있다.
두 개의 2 사이에는 정확히 2개의 수가 있다.
...
두 개의 n 사이에는 정확히 n개의 수가 있다.
예를 들어 3, 1, 2, 1, 3, 2은 n=3인 랭퍼드 수열이다.

n이 주어졌을 때, 길이 2n의 랭퍼드 수열의 개수를 구하면 된다.
하지만 이렇게만 하면 재미가 없으니 조건 하나를 추가하고자 한다.
x번째 수와 y번째 수는 같다는 조건이다. (이 번호는 1부터 시작한다.)

입력
세 자연수 n, x, y가 주어진다. (2 ≤ n ≤ 12, 1 ≤ x < y ≤ 2n, 1 ≤ y-x-1 ≤ n)

출력
x번째 수와 y번째 수가 같은 길이 2n의 랭퍼드 수열의 개수를 출력한다.
*/
#include <iostream>
using namespace std;

int n, x, y, t;
int p[25];
int foo(int num) {
	if (num == t) return foo(num + 1);
	if (num == n + 1) {
		return 1;
	}
	int cnt = 0;
	for (int i = 1; (i + num + 1) < 2 * n + 1; i++) {
		if (p[i] == 0 && p[i + num + 1] == 0) {
			p[i] = p[i + num + 1] = num;
			cnt += foo(num + 1);
			p[i] = p[i + num + 1] = 0;
		}
	}
	return cnt;
}
int main() {
	cin >> n >> x >> y;
	t = y - x - 1;
	p[x] = p[y] = t;
	cout << foo(1);
}