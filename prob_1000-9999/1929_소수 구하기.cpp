#include <iostream>
#include <vector>
using namespace std;

vector<bool> initPrime(int n) {
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n + 1; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < n + 1; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return isPrime;
}
int main() {
	int n;
	int m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	vector<bool> isPrime = initPrime(n);
	for (int i = m; i < n + 1; i++) {
		if (isPrime[i]) cout << i << '\n';
	}
}