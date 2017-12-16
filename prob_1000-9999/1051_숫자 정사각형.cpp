/*
문제
N*M크기의 직사각형이 있다. 각 칸은 한 자리 숫자가 적혀 있다.
이 직사각형에서 꼭지점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오.
이 때, 정사각형은 행 또는 열에 평행해야 한다.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 수가 주어진다.

출력
첫째 줄에 정답 정사각형의 크기를 출력한다.
*/
#include <iostream>
using namespace std;

int n, m, p[51][51];
int main() {
	int ans = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			p[i][j] = x - '0';
		}
	}
	int l = (n < m) ? n : m;
	for(int k = 1; k<l; k++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (p[i][j] == p[i + k][j] && p[i + k][j] == p[i + k][j + k] && p[i + k][j + k] == p[i][j + k]) {
					ans = k + 1;
				}
			}
		}
	}
	cout << ans*ans;
}