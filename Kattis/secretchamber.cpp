#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int
main() {
	vvi adjList(26, vi());
	int adjMatrix[26][26];
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;
		adjList[a - 'a'].push_back(b - 'a');
	}
	bool reachable[26][26];
	memset(reachable, false, sizeof reachable);
	for (int a = 0; a < 26; a++) {
		bitset<26> visited;
		visited.set(a);
		queue<int> q;
		q.push(a);
		reachable[a][a] = true;
		while (!q.empty()) {
			int u = q.front();
			reachable[a][u] = true;
			q.pop();
			for (int i = 0; i < adjList[u].size(); i++) {
				int v = adjList[u][i];
				if (!visited.test(v)) {
					visited.set(v);
					q.push(v);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (a.length() != b.length()) {
			cout << "no\n";
			continue;
		}
		bool match = true;
		for (int j = 0; j < a.length(); j++) {
			char u = a[j];
			char v = b[j];
			if (!reachable[u - 'a'][v - 'a']) {
				match = false;
				break;
			}
		}
		if (match) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
