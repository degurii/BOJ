/*
문제
문자열 S의 접두사란 S의 가장 앞에서부터 부분 문자열을 의미한다. 예를 들어, S = "codeplus"의 접두사는 "code", "co", "codepl", "codeplus"가 있고, "plus", "s", "cude", "crud"는 접두사가 아니다.
총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 문자열 중 적어도 하나의 접두사인 것의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.
둘째 줄에는 집합 S에 포함되어 있는 문자열이 주어지며, 공백으로 구분되어져 있다.
셋째 줄에는 검사해야 하는 문자열 M개가 주어지며, 공백으로 구분되어져 있다.

입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러번 주어지는 경우는 없다.

출력
첫째 줄에 M개의 문자열 중에 총 몇 개가 포함되어 있는 문자열 중 적어도 하나의 접두사인지 출력한다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
	struct Node {
		int abc[26];
		bool valid;
		Node() : valid(false) {
			for (int i = 0; i < 26; i++) abc[i] = -1;
		}
	};
	vector<Node> trie;
	int root;
	int init() {
		trie.emplace_back();
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}
	void add(int node, string &s, int idx) {
		if (idx == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[idx] - 'a';
		if (trie[node].abc[c] == -1) {
			trie[node].abc[c] = init();
		}
		int child = trie[node].abc[c];
		add(child, s, idx + 1);
	}
	void add(string &s) {
		add(root, s, 0);
	}
	bool search(int node, string &s, int idx) {
		if (node == -1) return false;
		if (idx == s.size())return true;
		int c = s[idx] - 'a';
		int child = trie[node].abc[c];
		return search(child, s, idx + 1);
	}
	bool search(string &s) {
		return search(root, s, 0);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	Trie trie;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		trie.add(s);
	}
	int ans = 0;
	for(int i=0; i< m; i++){
		cin >> s;
		if (trie.search(s))
			ans++;
	}
	cout << ans;
}