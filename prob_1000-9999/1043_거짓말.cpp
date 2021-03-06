/*
사람의 수 N이 주어진다. 그리고 그 이야기의 진실을 아는 사람이 주어진다. 그리고 각 파티에 오는 사람들의 번호가 주어진다.
지민이는 모든 파티에 참가해야 한다. 이 때, 지민이가 거짓말쟁이로 알려지지 않으면서, 과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N과 파티의 수 M이 주어진다.
둘째 줄에는 이야기의 진실을 아는 사람의 수와 번호가 주어진다.
진실을 아는 사람의 수가 먼저 주어지고 그 개수만큼 사람들의 번호가 주어진다. 사람들의 번호는 1부터 N까지의 수로 주어진다.
셋째 줄부터 M개의 줄에는 각 파티마다 오는 사람의 수와 번호가 같은 방식으로 주어진다.

N, M은 50 이하의 자연수이고, 진실을 아는 사람의 수와 각 파티마다 오는 사람의 수는 모두 0 이상 50 이하의 정수이다.

출력
첫째 줄에 문제의 정답을 출력한다.
*/


/*
진실을 아는 사람 x가 참가한 파티에 참가한 어떤 사람 A는 진실을 알게 된다.
A가 진실을 알게 됐으므로 A가 참가한 파티에 참가한 다른 사람들도 진실을 알게된다.
이런 식으로 진실을 알게 될 사람들이 모두 알 때까지 반복한다.
파티가 최대 50개이므로 최대 50번 반복하면 된다.
*/
#include <iostream>
using namespace std;

int n, m;
bool truth[51];
int p[51][51], num[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int x;
	cin >> x;
	while (x--) {
		int u;
		cin >> u;
		truth[u] = true;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> num[i];
		bool c = false;
		for (int j = 0; j < num[i]; j++) {
			cin >> p[i][j];
		}
	}

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			bool c = false;
			for (int j = 0; j < num[i]; j++) {
				if (truth[p[i][j]]) {
					c = true;
					break;
				}
			}
			if (c) {
				for (int j = 0; j < num[i]; j++) {
					truth[p[i][j]] = true;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool c = false;
		for (int j = 0; j < num[i]; j++) {
			if (truth[p[i][j]]) c = true;
		}
		if (!c) ans++;
	}
	cout << ans;
}