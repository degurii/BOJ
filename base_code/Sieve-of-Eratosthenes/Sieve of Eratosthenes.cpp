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
	cin >> n;

	// isPrime[x] : True when x is a prime number
	vector<bool> isPrime = initPrime(n);

}