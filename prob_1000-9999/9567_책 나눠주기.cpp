/*
문제
백준이는 방 청소를 하면서 필요 없는 전공 서적을 사람들에게 나눠주려고 한다. 나눠줄 책을 모아보니 총 N권이었다.
책이 너무 많기 때문에 백준이는 책을 구분하기 위해 각각 1부터 N까지의 정수 번호를 중복되지 않게 매겨 두었다.

조사를 해 보니 책을 원하는 서강대학교 학부생이 총 M명이었다.
백준이는 이 M명에게 신청서에 두 정수 a, b (1 ≤ a ≤ b ≤ N)를 적어 내라고 했다.
그러면 백준이는 책 번호가 a 이상 b 이하인 책 중 남아있는 책 한 권을 골라 그 학생에게 준다.
만약 a번부터 b번까지의 모든 책을 이미 다른 학생에게 주고 없다면 그 학생에게는 책을 주지 않는다.

백준이가 책을 줄 수 있는 최대 학생 수를 구하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다.
각 케이스의 첫 줄에 정수 N(1 ≤ N ≤ 1,000)과 M(1 ≤ M ≤ 1,000)이 주어진다.
다음 줄부터 M개의 줄에는 각각 정수 ai, bi가 주어진다. (1 ≤ ai ≤ bi ≤ N)

출력
백준이가 책을 줄 수 있는 최대 학생 수를 출력한다.
*/


/*
solution:
이분매칭인데
책에 연결된 간선이 범위로 주어지므로
간선을 따로 연결하지 않고 바로 범위를 참조한다.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
bool check[1001];
int match[1001];
pair<int, int> range[1001];
int dfs(int now) {
	if (now == -1) return 1;
	for (int i = range[now].first; i < range[now].second + 1; i++) {
		if (check[i]) continue;
		check[i] = true;
		if (dfs(match[i])) {
			match[i] = now;
			return 1;
		}
	}
	return 0;
}

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) {
			cin >> range[i].first >> range[i].second;
		}

		int ans = 0;
		memset(match, -1, sizeof(match));
		for (int i = 0; i < m; i++) {
			memset(check, 0, sizeof(check));
			ans += dfs(i);
		}
		cout << ans << '\n';
	}
}