/*
문제
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고,
조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때,
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.
한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.

출력
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다.
만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.
*/


/*
solution:
두 원의 상태에 대한 케이스를 나눈다
1) 두개가 같은 원
2) 아예 접하지 않을 때
3) 외접할 때
4) 두 점에서 만날 때
5) 내접할 때
6) 작은 원의 중심이 큰 원 내부에 있고, 두 원이 만나지 않을 때
*/
#include <iostream>
using namespace std;


int x, y, r1, x2, y2, r2;
int dist() {
	return (x - x2)*(x - x2) + (y - y2)*(y - y2);
}
int sq(int x) {
	return x * x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y >> r1 >> x2 >> y2 >> r2;

		if (r1 == r2 && x == x2 && y == y2)
			cout << -1;
		else if (dist() > sq(r1 + r2))
			cout << 0;
		else if (dist() == sq(r1 + r2))
			cout << 1;
		else if (dist() < sq(r1 + r2)) {
			if (dist() > sq(r2 - r1))
				cout << 2;
			else if (dist() == sq(r2 - r1))
				cout << 1;
			else if (dist() < sq(r2 - r1))
				cout << 0;
		}
		cout << '\n';
	}
}