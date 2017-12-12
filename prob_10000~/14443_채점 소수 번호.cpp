#include <iostream>
#include <vector>
using namespace std;

vector<int> pr;
vector<bool> p(10000000);
int main() {
	for (int i = 2; i <= 10000000; i++) {
		if (p[i]) continue;
		for (int j = i * 2; j <= 10000000; j += i) {
			p[i] = true;
		}
	}
	for (int i = 7332508; i <= 8000000; i++) {
		if (p[i] == false)
			pr.push_back(i);
	}
	for (int i : pr)
		cout << i << '\n';
}