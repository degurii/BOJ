/*
다음과 같은 규칙으로 소수 게임을 진행할 때 승자를 출력하시오.

입력
입력의 첫째 줄에 두 사람이 대결을 하는 라운드 수 N이 주어진다. (5≤N≤100,000)
이 후 N개의 줄에 대웅이와 규성이가 말하는 자연수(<5,000,000)가 공백으로 구분되어 주어진다.

출력
대웅이가 이길 경우 “소수의 신 갓대웅” 규성이가 이길 경우 “소수 마스터 갓규성”을 출력한다.
만약 비길 경우 “우열을 가릴 수 없음” 을 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n, a[3], b[3];
bool isPrime[5000001], check[5000001];

void init_prime() {
	for (int i = 2; i < 5000001; i++)
		isPrime[i] = true;
	for (int i = 2; i < 5000001; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < 5000001; j += i)
				isPrime[j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init_prime();
	cin >> n;
	ll ascore = 0, bscore = 0; // a: 대웅, b: 규성
	int acnt = 0, bcnt = 0;
	while (n--) {
		int x, y;
		cin >> x;
		if (!isPrime[x])
			bscore += (bcnt < 3) ? 1000 : b[0];
		else if (check[x])
			ascore -= 1000;
		else {
			check[x] = true;
			if (acnt < 3) {
				a[0] = x;
				sort(a, a + 3);
			}
			else if (a[0] < x && x < a[1]) {
				a[0] = x;
			}
			else if (a[1] < x && x < a[2]) {
				a[0] = a[1];
				a[1] = x;
			}
			else if (a[2] < x) {
				a[0] = a[1];
				a[1] = a[2];
				a[2] = x;
			}
			acnt++;
		}

		cin >> y;
		if (!isPrime[y])
			ascore += (acnt < 3) ? 1000 : a[0];
		else if (check[y])
			bscore -= 1000;
		else {
			check[y] = true;
			if (bcnt < 3) {
				b[0] = y;
				sort(b, b + 3);
			}
			else if (b[0] < y && y < b[1])
				b[0] = y;
			else if (b[1] < y && y < b[2]) {
				b[0] = b[1];
				b[1] = y;
			}
			else if (b[2] < y) {
				b[0] = b[1];
				b[1] = b[2];
				b[2] = y;
			}
			bcnt++;
		}
	}
	if (ascore > bscore) {
		cout << "소수의 신 갓대웅";
	}
	else if (ascore < bscore)
		cout << "소수 마스터 갓규성";
	else
		cout << "우열을 가릴 수 없음";
	
}