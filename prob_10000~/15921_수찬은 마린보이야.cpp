/*
문제
꾸준한 기량을 뽐낼 수 있는 확률은 (연습 기록들의 평균값) / (연습 기록들의 기댓값) 이라고 한다.
수찬이는 이 기사를 읽고 무릎을 탁(!) 치며 자신의 연습 기록을 가지고 이 확률을 계산해보기로 했다. 수찬이가 꾸준한 기량을 뽐낼 수 있는 확률은 얼마일까?

입력
첫째 줄에 수찬이의 연습 기록의 개수 N이 주어진다. (0 ≤ N ≤ 100)
둘째 줄에 수찬이의 연습 기록 N개가 주어진다. N이 0이면 아무것도 주어지지 않으며 연습 기록은 100 이하의 양의 정수이다.

출력
문제에서 제시한 확률을 소수 셋째 자리에서 반올림하여 소수 둘째 자리까지 출력한다.
N이 0이거나 분모가 0인 경우에는 “divide by zero”를 출력한다.
*/
#include <iostream>
using namespace std;

int n;
int sum;
int main() {
	cin >> n;
	if (n == 0) {
		cout << "divide by zero";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	if (sum == 0) {
		cout << "divide by zero";
		return 0;
	}
	cout << "1.00";
}