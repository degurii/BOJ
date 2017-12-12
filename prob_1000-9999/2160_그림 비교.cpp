/*
문제
N(2≤N≤50)개의 그림이 있다. 각각의 그림은 5×7의 크기이고, 두 가지 색으로 되어 있다.
이 때 두 가지의 색을 각각 ‘X’와 ‘.’으로 표현하기로 하자.
이러한 그림들이 주어졌을 때, 가장 비슷한 두 개의 그림을 찾아내는 프로그램을 작성하시오.
두 개의 그림에서 다른 칸의 개수가 가장 적을 때, 두 개의 그림이 가장 비슷하다고 하자.

입력
첫째 줄에 N이 주어진다. 다음 5×N개의 줄에 7개의 문자로 각각의 그림이 주어진다.

출력
첫째 줄에 가장 비슷한 두 그림의 번호를 출력한다.
그림의 번호는 입력되는 순서대로 1, 2, …, N이다.
번호를 출력할 때에는 작은 것을 먼저 출력한다. 입력은 항상 답이 한 가지인 경우만 주어진다.
*/
#include <iostream>
#include <string>
using namespace std;

string p[51][5];
int n;
int diff(string a[5], string  b[5]) {
	int d = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (a[i][j] != b[i][j])
				d++;
		}
	}
	return d;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> p[i][j];
		}
	}
	int a1 = -1, a2 = -1, ans = 100000000;
	for (int i = 1; i < n + 1; i++) {
		for (int j = i + 1; j < n + 1; j++) {
			int d = diff(p[i], p[j]);
			if (ans > d) {
				ans = d;
				a1 = i, a2 = j;
			}
		}
	}
	cout << a1 << ' ' << a2;
}