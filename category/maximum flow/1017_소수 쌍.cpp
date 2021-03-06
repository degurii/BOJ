/*
문제
지민이는 수의 리스트가 있을 때, 이를 짝지어 각 쌍의 합이 소수가 되게 하려고 한다.
예를 들어, {1, 4, 7, 10, 11, 12}가 있다고 하자. 지민이는 다음과 같이 그룹지을 수 있다.

1 + 4 = 5, 7 + 10 = 17, 11 + 12 = 23
또는
1 + 10 = 11, 4 + 7 = 11, 11 + 12 = 23

수의 리스트가 주어졌을 때, 지민이가 모든 수를 다 짝지었을 때, 첫번째 수와 어떤 수를 짝지었는지 오름차순으로 출력하는 프로그램을 작성하시오.
위의 예제에서 1 + 12 = 13으로 소수이다. 그러나, 남은 4개의 수를 합이 소수가 되게 짝지을 수 있는 방법이 없다. 따라서 예제의 답은 4, 10이다.

입력
첫째 줄에 리스트의 크기 N이 주어진다. N은 50보다 작거나 같은 자연수이며, 짝수이다.
둘째 줄에 리스트에 들어있는 수가 주어진다. 리스트에 들어있는 수는 1,000보다 작거나 같은 자연수이며, 중복되지 않는다.

출력
첫째 줄에 정답을 출력한다. 없으면 -1을 출력한다.
*/


/*
solution:
먼저 첫번째 수와 짝지을 수를 결정한다.
나머지 수들 중 짝수집합/홀수집합으로 나눠서
두 집합 사이의 이분매칭이 완벽하게 이루어지면 정답에 첫 번째 수와 짝지은 수를 추가한다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPrime[3000];
vector<vector<int>> p;
vector<int> lst;
bool check[100];
int match[100];
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : p[now]) {
		if (check[next])continue;
		check[next] = true;
		if (dfs(match[next])) {
			match[next] = now;
			return 1;
		}
	}
	return 0;
}
void initPrime() {
	fill(isPrime, isPrime + 3000, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 3000; i++) {
		if (!isPrime[i])continue;
		for (int j = i * 2; j < 3000; j += i) {
			isPrime[j] = false;
		}
	}
}
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	initPrime();
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		lst.push_back(x);
	}
	vector<int> ans;
	for (int i = 1; i < n; i++) {
		if (!isPrime[lst[0] + lst[i]]) continue;
		vector<int> odd, even;
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			if (lst[j] & 1) odd.push_back(lst[j]);
			else even.push_back(lst[j]);
		}
		if (odd.size() != even.size()) continue;
		int m = odd.size();
		p = vector<vector<int>>(m);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				if (isPrime[odd[j] + even[k]]) {
					p[j].push_back(k);
				}
			}
		}
		int cnt = 0;
		memset(match, -1, sizeof(match));
		for (int j = 0; j < m; j++) {
			memset(check, 0, sizeof(check));
			cnt += dfs(j);
		}
		if (cnt == m) {
			ans.push_back(lst[i]);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty())cout << -1;
	else
	for (int a : ans) cout << a << ' ';
}