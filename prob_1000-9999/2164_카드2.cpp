/*
문제
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다.
우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(1≤N≤500,000)이 주어진다.

출력
첫째 줄에 남게 되는 카드의 번호를 출력한다.
*/


/*
solution:
분명 뭔가 식이 있겠지만 queue로 시뮬레이션 돌리는것도 견적 나와보여서 그냥 전부돌려봄
*/
#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;
int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}
	bool c = true;
	while (q.size() > 1) {
		if (!c)
			q.push(q.front());
		q.pop();
		c ^= 1;
	}
	cout << q.front();
}