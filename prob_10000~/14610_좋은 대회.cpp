/*
문제
깨어진 모니터에 보이는 스코어보드 정보가 주어졌을 때, 이 대회가 좋은 대회가 될 수 있는지를 알아보자.

입력
첫 줄에 이번 대회의 참가자의 N(1 ≤ N ≤ 100)과 문제의 수 M(1 ≤ M ≤ 10)이 주어진다.
다음 N 개의 줄에는 1등부터 N 등까지, i 등 참가자의 맞춘 문제 수 Ki (0 ≤ Ki ≤ M)와 해당 참가자의 1 ~ M번 문제에 대한 결과가 M 개가 주어진다.
결과는 맞았다면 1, 틀렸다면 0, 찢어져 결과를 알 수 없다면 -1로 주어진다.

출력
좋은대회가 될 수 있다면 “YES”, 아니라면  “NO”를 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int p[101][11], ac[101];
bool a[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		cin >> ac[i];
		if (ac[i] == 0 || ac[i] == m) {
			cout << "NO";
			return 0;
		}
		for (int j = 1; j < m + 1; j++) {
			cin >> p[i][j];
			if (p[i][j] == 1)
				a[j] = true;
		}
	}
	for (int i = n; i > 0; i--) {
		int cnt = 0;
		for (int j = 1; j < m + 1; j++) {
			if (p[i][j] != -1 && p[i][j]) cnt++;
		}
		cnt = ac[i] - cnt;
		for (int j = m; j > 0 && cnt > 0; j--) {
			if (p[i][j] != -1) break;
			if (!a[j]) {
				a[j] = true;
				cnt--;
			}
		}
	}
	for(int i=1; i<m+1; i++)
		if (!a[i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
}
