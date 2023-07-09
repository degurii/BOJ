#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;	// n: num of vertex, m: num of edge
	cin >> n >> m;

	vector<vector<int> > d(n + 1, vector<int>(n + 1, inf));

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = w;
	}

	for (int i = 1; i < n + 1; i++) d[i][i] = 0;

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}