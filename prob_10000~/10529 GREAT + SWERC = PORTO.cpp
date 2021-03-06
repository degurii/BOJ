#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

pair<bool, bool> let[100];
string s[10];
int val[100];
bool digit[10];
vector<char> p;
int ans, n;

bool cal() {
	long long res = 0;
	long long num = 0;
	for (int i = 0; i < n - 1; i++) {
		num = 0;
		for (char c : s[i]) {
			num *= 10;
			num += val[c];
		}
		res += num;
	}

	num = 0;
	for (char c : s[n - 1]) {
		num *= 10;
		num += val[c];
	}

	return (res == num);
}
void foo(int idx) {
	if (idx == p.size()) {
		if (cal()) ans++;
		return;
	}
	char c = p[idx];
	for (int i = let[c].second ? 1 : 0; i < 10; i++) {
		if (digit[i]) continue;
		digit[i] = true;
		val[c] = i;
		foo(idx + 1);
		val[c] = -1;
		digit[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(val, -1, sizeof(val));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		auto x = s[i];
		let[x[0]].first = let[x[0]].second = true;
		for (int j = 1; x[j]; j++) {
			let[x[j]].first = true;
		}
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (let[i].first) p.push_back(i);
	}
	foo(0);
	cout << ans;
}