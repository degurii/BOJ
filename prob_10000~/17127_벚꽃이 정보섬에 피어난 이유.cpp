#include <iostream>
using namespace std;

int p[20];
int n;
int go(int p1, int p2, int p3) {
	int val = 0;
	int x = 1;
	for (int i = 1; i < p1 + 1; i++) {
		x *= p[i];
	}
	val += x;
	x = 1;
	for (int i = p1 + 1; i < p2 + 1; i++) {
		x *= p[i];
	}
	val += x;
	x = 1;
	for (int i = p2 + 1; i < p3 + 1; i++) {
		x *= p[i];
	}
	val += x;
	x = 1;
	for (int i = p3 + 1; i < n + 1; i++) {
		x *= p[i];
	}
	val += x;
	return val;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	int ans = 0, val = 0;
	int cnt[10]; 
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				val = go(i, j, k);
				/*
				if (ans < val) {
					ans = val;
					cnt[0] = i, cnt[1] = j, cnt[2] = k;
				}
				*/
				ans = (ans > val) ? ans : val;
			}
		}
	}
	cout << ans;
	//for (int i = 0; i < 3; i++) cout << cnt[i] << ' ';
}