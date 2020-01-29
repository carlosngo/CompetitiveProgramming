#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int
main() {
	int n, m, num, srcA, srcB;
	cin >> n >> m >> num >> srcA >> srcB;
	srcA--; srcB--;
	vvi adjList(n, vi());
	vi in(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adjList[u].push_back(v);
		in[v]++;
	}
	vi net(n);
	for (int i = 0; i < n; i++) {
		string s;
		int cost;
		cin >> s;
		cin >> cost;
		if (s == "TAX") net[i] = cost;
		else if (s == "SALARY") net[i] = -cost;
		else {
			net[i] = 0;
			cin >> cost;
		}
	}
	vi topo;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) q.push(i);
	}
	int startA, startB;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == srcA) startA = topo.size();
		if (u == srcB) startB = topo.size();
		topo.push_back(u);
		
		for (int i = 0; i < adjList[u].size(); i++) {
			int v = adjList[u][i];
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
			}
		}
	}
	ll INF = 1000000000000000LL;
	vector<ll> dist(n, INF);
	dist[srcA] = 0;
	ll ans = INF;
	for (int i = 0; i < topo.size(); i++) {
		int u = topo[i];
		if (dist[u] == INF) continue;
		if (adjList[u].size() == 0) ans = min(ans, dist[u]);
		for (int j = 0; j < adjList[u].size(); j++) {
			int v = adjList[u][j];
			dist[v] = min(dist[v], dist[u] + net[v]);
		}
	}
	cout << -ans << ' ';
	ans = INF;
	dist.assign(n, INF);
	dist[srcB] = 0;
	for (int i = 0; i < topo.size(); i++) {
		
		int u = topo[i];
		if (dist[u] == INF) continue;
		if (adjList[u].size() == 0) ans = min(ans, dist[u]);
		for (int j = 0; j < adjList[u].size(); j++) {
			int v = adjList[u][j];
			dist[v] = min(dist[v], dist[u] + net[v]);
		}
	}
	cout << -ans << '\n';
	return 0;
}
