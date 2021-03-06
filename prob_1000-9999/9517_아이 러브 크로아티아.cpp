/*
입력
첫째 줄에 게임이 시작했을 때 폭탄을 들고 있는 사람의 번호 K (1 ≤ K ≤ 8)가 주어진다.
둘째 줄에는 질문의 개수 N (1 ≤ N ≤ 100)이 주어진다.
다음 N개 줄에는 i번째 질문을 대답하기까지 걸린 시간(단위: 초) T (1 ≤ T ≤ 100), 그 플레이어의 대답 Z (T, N, P중 하나) 가 주어진다.

출력
폭탄을 터뜨린 사람의 번호를 출력한다.
*/
#include <iostream>
using namespace std;

int n, k;
int main() {
	cin >> k >> n;
	k--;
	int time = 0;
	while (n--) {
		int t;
		char c;
		cin >> t >> c;
		if (time + t >= 210) {
			cout << k + 1;
			return 0;
		}
		if (c == 'T')
			k = (k + 1) % 8;
		time += t;
	}
}