/*
문제
인코딩 된 문자열과 인코딩하는데 사용한 m과 p1, ..., pn이 주어졌을 때, 인코딩 하기 전 문자열을 구하는 프로그램을 작성하시오. (디코딩)

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 n과 m이 주어진다. (1 ≤ n ≤ 80, 1 ≤ m ≤ 109)
다음 줄에는 인코딩하는데 사용한 n개의 서로 다른 숫자 p1, ..., pn이 주어진다. (1 ≤ pi ≤ n)
셋째 줄에는 인코딩된 문자열이 주어진다. 입력의 마지막 줄에는 0이 두 개 있다.

출력
각 테스트 케이스에 대해서 디코딩한 문자열을 출력한다.
*/



/*
solution:
첫번째 접근
m이 굉장히 큰 관계로 주어진 문자열을 순열 p의 순서로 돌리면서
원래 문자열로 돌아올때까지의 횟수(이하 lotation)를 카운팅 하여 m과 그 횟수를 mod연산해서 m을 줄임
위가 a)번 과정

남은 m만큼 문자열의 순서를 반복적으로 바꿈
이게 b)번 과정
-> 시간초과

두번째 접근
lotation을 구하는데에서 많은 시간이 소비된다고 생각함
순열 p가 각 연결요소마다 싸이클을 가지는 그래프라는 것을 발견
각 연결요소의 사이즈들의 최소공배수가 이전 접근에서 구하려한 lotation의 값이기 때문에
더 빠른시간내에 lotation 을 구할 수 있음
 
-> 그러나 시간초과
의의 - a)번 과정의 시간을 줄임, 그러나 b)번 과정의 시간은 고려하지 못함

두번째에서 틀린 이유
m을 lotation으로 나눈 나머지 또한 lotation에 근접한 수일 수도 있다는 것을 간과함
이미 첫번째 접근에서 lotation을 반복적으로 구할때 시간초과가 났고,
b)번 과정 또한 lotation만큼 반복하는 과정이기 때문에 시간초과가 날 수 밖에 없음
다른 방식으로 접근해야 함

세번째 접근
lotatoin을 문자열 전체가 초기상태로 돌아올때까지의 반복횟수가 아니라
싸이클들을 따로 보고 각 연결요소에서 싸이클이 한번 반복될때까지의 횟수로 정의함
각 싸이클은 indegree와 outdegree가 1인 그래프이므로, 싸이클이 한번 반복되는데는 싸이클의 사이즈만큼 소요됨

따라서 각 연결요소에 대해 m을 연결요소의 사이즈와 mod연산하여 줄이고, 해당되는 멤버들끼리 남은 m만큼 순서를 바꿈
(m % size) < size 이고, n<=80이기 때문에 size<=80 인 관계로 직접 위치를 바꾸는 반복의 횟수는 높은 시간복잡도를 가지지 않음
-> 맞았습니다

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;

int _hash[90], p2[90], p1[90];
char s[90];

bool check[90];
vector<vector<pair<int, int> > > group;
int g = -1;
void dfs(int now, int num) {
	check[now] = true;
	int next = _hash[now];
	group[num].push_back({ now, next });
	if (!check[next])
		dfs(next, num);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		group.clear();
		g = -1;
		memset(check, 0, sizeof(check));
		int n;
		ll m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			_hash[x - 1] = i;
		}

		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				group.push_back(vector<pair<int, int> >());
				dfs(i, ++g);
			}
		}
		
		cin.ignore();
		cin.getline(s, n + 1);
		
		copy(s, s + sizeof(s), p1);
		copy(s, s + sizeof(s), p2);
		for (auto it : group) {
			int m2 = m % it.size();
			while (m2--) {
				for (auto jt : it) {
					int u = jt.first, v = jt.second;
					p2[u] = p1[v];
				}
				copy(p2, p2 + n, p1);
			}
		}
		
		for (int i = 0; i < n; i++)
			cout.put(p1[i]);
		cout << '\n';
	}
}