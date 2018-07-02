/*
문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다.
여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
집합을 표현하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다.
m은 입력으로 주어지는 연산의 개수이다.
다음 m개의 줄에는 각각의 연산이 주어진다.
합집합은 0 a b의 형태로 입력이 주어진다.
이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다.
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다.
이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.
a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.

출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)
*/





/*
solution:
기초 Disjoint set 문제이다
Union,Find 를 구현한다
*/
#include <iostream>
using namespace std;
#include <algorithm>

int n, m;
int p[1000001];
int Find(int x) {
	if (x == p[x]) return x;
	else return p[x] = Find(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)p[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			p[Find(b)] = Find(c);
		}
		else if (a == 1) {
			if (Find(b) == Find(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}