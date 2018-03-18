/*
문제
김우현을 위해 x지점부터 정확히 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최소값을 구하는 프로그램을 작성하라.

입력
입력의 첫 줄에는 테스트케이스의 개수 T가 주어진다.
각각의 테스트 케이스에 대해 현재 위치 x 와 목표 위치 y 가 정수로 주어지며, x는 항상 y보다 작은 값을 갖는다. ( 0 ≤ x < y < 2^31)

출력
각 테스트 케이스에 대해 x지점으로부터 y지점까지 정확히 도달하는데 필요한 최소한의 공간이동 장치 작동 회수를 출력한다.
*/



/*
solution:
손으로 직접 그려보며
즉당히 식을 세워보자
*/
#include <iostream>
using namespace std;
using ll = long long;

int t;
ll x, y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> x >> y;
		x = y - x;
		
		for (ll i = 0; i*(i + 1) < x; i++) {
			if (x <= (i + 1)*(i + 2)) {
				if (x <= (i + 1)*(i + 1)) {
					cout << 2 * i + 1 << '\n';
				}
				else {
					cout << 2 * i + 2 << '\n';
				}
				break;
			}
		}
	}
}