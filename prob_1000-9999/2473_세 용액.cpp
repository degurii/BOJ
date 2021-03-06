/*
산성 용액과 알칼리성 용액이 주어졌을 때, 이 중 같은 양의 세 개의 서로 다른 용액을 혼합하여
특성값이 0에 가장 가까운 용액을 만들어내는 세 용액을 찾는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 3 이상 5,000 이하의 정수이다.
둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다.
N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

출력
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값을 출력한다.
출력해야하는 세 용액은 특성값의 오름차순으로 출력한다.
특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int n, ans[3];
ll p[5001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	ll val = (ll)3e9 + 1;
	for (int k = 0; k < n; k++) {
		for (int i = k+1, j = n - 1; i < j;) {
			if (abs(val) > abs(p[i] + p[j] + p[k])) {
				ans[0] = p[i];
				ans[1] = p[j];
				ans[2] = p[k];
				val = p[i] + p[j] + p[k];
			}
			
			if (p[i] + p[j] < -p[k])
				i++;
			else if (p[i] + p[j] > -p[k])
				j--;
			else
				break;
		}
		if (val == 0)break;
	}
	sort(ans, ans + 3);
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}