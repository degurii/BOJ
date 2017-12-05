/*
문제
이 관찰 기록을 가지고 소가 최소 몇 번 길을 건넜는지 알아보자. 즉 같은 번호의 소가 위치를 바꾼 것이 몇 번인지 세면 된다.

입력
첫 줄에 관찰 횟수 N이 주어진다. N은 100 이하의 양의 정수이다.
다음 N줄에는 한 줄에 하나씩 관찰 결과가 주어진다. 관찰 결과는 소의 번호와 위치(0 또는 1)로 이루어져 있다.

출력
첫 줄에 소가 길을 건너간 최소 횟수를 출력한다.
*/




/*
solution:
그냥 구현하면 됨
*/
#include <iostream>
using namespace std;
#include <cstring>

int n, p[11];
int main() {
	memset(p, -1, sizeof(p));
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if (p[u] == -1)
			p[u] = v;
		else if(p[u] != v){
			p[u] = v;
			ans++;
		}
	}
	cout << ans;
}