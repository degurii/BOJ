/*
문제
1부터 N - 1까지의 정수가 하나씩 정렬되지 않은 채로 저장되어 있는 어떤 수열 A가 있다.
수열 A에 임의의 정수 M(1 ≤ M ≤ N – 1)을 넣어 크기가 N인 수열로 만들었을 때, 임의의 정수 M을 찾는 프로그램을 작성하라.

입력
첫째줄에 수열의 크기 N(1 ≤ N ≤ 10,000,000)이 주어진다.
둘째줄에 수열 A의 원소인 N개의 정수가 주어진다.
입력으로 주어지는 정수는 모두 1부터 N – 1 사이의 정수이며 문제의 답인 M을 제외하고는 모두 서로 다른 정수이다.

출력
M을 출력하라.
*/

/*
solution:
어떤 수 x에 대해
x^x = 0
0^x = x
이고 xor은 결합법칙이 성립한다.
따라서 1 ~ n-1과 입력들을 모두 xor하면 m이 나온다.
*/
#include <iostream>
using namespace std;

int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		if(i < n) ans ^= i;
		int x;
		cin >> x;
		ans ^= x;
	}
	
	cout << ans;
}