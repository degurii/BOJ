/*
입력
입력의 첫째 줄에 맵에 존재하는 헬멧의 개수 N(N은 1000이하의 자연수)과 조끼의 개수 M(M은 1000이하의 자연수)이 주어진다.
둘째 줄에 각 헬멧의 방어력 h[i] (h[i]는 10억 이하의 자연수)가 N개 만큼 주어지며,
셋째 줄에 각 조끼의 방어력 a[i] (a[i]는 10억 이하의 자연수)가 M개 만큼 주어진다.

출력
경수가 얻을 수 있는 방어력의 최댓값을 출력한다.
*/
#include <iostream>
using namespace std;

int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int a = -10, b = -10;
	while (n--) {
		int x;
		cin >> x;
		if (x > a) a = x;
	}
	while (m--) {
		int x;
		cin >> x;
		if (x > b) b = x;
	}
	cout << a + b;
}