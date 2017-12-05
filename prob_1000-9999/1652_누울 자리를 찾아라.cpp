/*
문제
일 년 동안 세계일주를 하던 영식이는 여행을 하다 너무 피곤해서 근처에 있는 코레스코 콘도에서 하룻밤 잠을 자기로 하고 방을 잡았다.
코레스코 콘도에 있는 방은 NxN의 정사각형모양으로 생겼다.
방 안에는 옮길 수 없는 짐들이 이것저것 많이 있어서 영식이의 누울 자리를 차지하고 있었다.
영식이는 이 열악한 환경에서 누울 수 있는 자리를 찾아야 한다.
영식이가 누울 수 있는 자리에는 조건이 있다.
똑바로 연속해서 2칸 이상의 빈 칸이 존재하면 그 곳에 몸을 양 옆으로 쭉 뻗으면서 누울 수 있다.
가로로 누울 수도 있고 세로로 누울 수도 있다.
누울 때는 무조건 몸을 쭉 뻗기 때문에 반드시 벽이나 짐에 닿게 된다. (중간에 어정쩡하게 눕는 경우가 없다.)

방의 크기 N과 방의 구조가 주어졌을 때, 가로로 누울 수 있는 자리와 세로로 누울 수 있는 자리의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 방의 크기 N이 주어진다. N은 1이상 100이하의 정수이다.
그 다음 N줄에 걸쳐 N개의 문자가 들어오는데 '.'은 아무것도 없는 곳을 의미하고, 'X'는 짐이 있는 곳을 의미한다.

출력
첫째 줄에 가로로 누울 수 있는 자리와 세로로 누울 수 있는 자리의 개수를 출력한다.
*/





/*
solution:

간단한 구현문제지만
생각지도 못한 반례가 있었따
..X..일때, 왼쪽하나 오른쪽하나로
자리는 두개이다

내가 난독인걸로
*/
#include <iostream>
using namespace std;

int p[101][101];
int n;
int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			char u;
			cin >> u;
			if (u == '.')p[i][j] = 1;
			else p[i][j] = 0;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < n + 1; i++) {
		bool c = true;
		for (int j = 1; j < n; j++) {
			if (p[i][j] == 0) c = true;
			else if (c && p[i][j] == 1 && p[i][j + 1] == 1) {
				ans1++;
				c = false;
			}
		}
	}
	for (int j = 1; j < n + 1; j++) {
		bool c = true;
		for (int i = 1; i < n; i++) {
			if (p[i][j] == 0) c = true;
			else if (c && p[i][j] == 1 && p[i + 1][j] == 1) {
				ans2++;
				c = false;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}