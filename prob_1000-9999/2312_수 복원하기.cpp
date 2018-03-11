/*
문제
양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 주어진다.

출력
각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 한다.
*/


/*
어떤 수 n에 대해 n = a*b(a<=b, a,b는 소수)이면 a<=root(n)이다. (n = root(n)^2이기 때문)
1) 확장해서 n = a*b*...*c*d*e (a<b<...<c<d<e)라 하면 항상 a<=root(n)이고,
2) n/a = b*...*c*d*e -> b<=root(n/a)
3) 2)와 같은 과정을 반복하면 {n/(a*b*...)}에 대해 항상 root(n/(a*b*...))이하의 소인수를 한 개 이상 구할 수 있다.
4) n/(a*b*...*c*d) = e
마지막 남은 e또한 n의 소인수이다.
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> m;
		for (int i = 2; i*i <= n;) {
			if (n%i == 0) {
				m[i]++;
				n /= i;
			}
			else i++;
		}
		m[n]++;
		for (auto it = m.begin(); it != m.end(); it++) {
			cout << it->first << ' ' << it->second << '\n';
		}
	}
}