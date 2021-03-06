/*
문제
상덕이가 종이에 적어놓은 내용과 바퀴의 칸의 수가 주어졌을 때, 바퀴에 적어놓은 알파벳을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 바퀴의 칸의 수 N과 상덕이가 바퀴를 돌리는 횟수 K가 주어진다. (2 ≤ N ≤ 25, 1 ≤ K ≤ 100)
다음 줄부터 K줄에는 바퀴를 회전시켰을 때
화살표가 가리키는 글자가 몇 번 바뀌었는지를 나타내는 S와 회전을 멈추었을 때 가리키던 글자가 주어진다. (1 ≤ S ≤ 100)

출력
첫째 줄에 마지막 회전에서 화살표가 가리키기는 문자부터 시계방향으로 바퀴에 적어놓은 알파벳을 출력한다.
이 때, 어떤 글자인지 결정하지 못하는 칸은 '?'를 출력한다.
만약, 상덕이가 적어놓은 종이에 해당하는 행운의 바퀴가 없다면 "!"를 출력한다.
*/
#include <iostream>
using namespace std;

int n, k;
char p[26];
bool check[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	int idx = 0;
	while (k--) {
		int x;
		char a;
		cin >> x >> a;

		idx = (idx + x) % n;
		if (p[idx] && p[idx] != a) {
			cout << "!";
			return 0;
		}
		p[idx] = a;
	}
	for (char i = 0; i < n; i++) {
		if (p[i] == 0)
			p[i] = '?';
		else if (check[p[i] - 'A']) {
			cout << "!";
			return 0;
		}
		else
			check[p[i] - 'A'] = true;
	}
	for (int i = n; i--; idx--) {
		if (idx < 0) idx += n;
		cout << p[idx];
	}
}