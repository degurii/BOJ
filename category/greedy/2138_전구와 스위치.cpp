/*
문제

N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때,
그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(2≤N≤100,000)이 주어진다.
다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다.
그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다.

출력
첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.
*/







/*
solve:
맨 처음 스위치를 누를지 말지 결정하면
두번째 스위치부터는 바로 앞의 칸을 바꿀 수 있는 방법이 하나가 된다
따라서 처음 스위치를 눌렀을때, 안눌렀을때로 나눠 돌린다

n-1번째 전구까지는 만들고자 하는 전구의 상태와 똑같이 만들 수 있으므로
마지막 n번째 전구가 만들고자 하는 전구와 같은지 비교해서 불가능을 판단한다
*/

#include<iostream>
using namespace std;

int n, p[100001], p2[100001], des[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		char c;
		cin >> c;
		p2[i] = p[i] = c - '0';
	}
	for (int i = 1; i < n + 1; i++) {
		char c;
		cin >> c;
		des[i] = c - '0';
	}
	int cnt1 = 0, cnt2 = 0;
	cnt1++;
	p[1] ^= 1;
	p[2] ^= 1;
	for (int i = 2; i < n + 1; i++) {
		if (p[i - 1] != des[i - 1]) {
			cnt1++;
			p[i - 1] ^= 1;
			p[i] ^= 1;
			if (i + 1 < n + 1)
				p[i + 1] ^= 1;
		}
	}
	for (int i = 2; i < n + 1; i++) {
		if (p2[i - 1] != des[i - 1]) {
			cnt2++;
			p2[i - 1] ^= 1;
			p2[i] ^= 1;
			if (i + 1 < n + 1)
				p2[i + 1] ^= 1;
		}
	}
	if (p[n] != des[n] && p2[n] != des[n]) cout << -1;
	else if (p[n] != des[n]) cout << cnt2;
	else if (p2[n] != des[n]) cout << cnt1;
	else if (cnt1 < cnt2) cout << cnt1;
	else cout << cnt2;
}