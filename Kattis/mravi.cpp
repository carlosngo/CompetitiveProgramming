#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int
main() {
	int n;
	cin >> n;
	vector<vii> adjList(n, vii());
	vector<vector<bool>> hasPower(n, vector<bool>(n, false));
	double INF = 100000000000000000;
	vector<double> dist(n, INF);
	vi topo;
	queue<int> q;
	vi in(n, 0);
	
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adjList[v].push_back(ii(u, w));
		in[u]++;
		int power;
		cin >> power;
		if (power) hasPower[v][u] = true;
	}	
	
	for (int i = 0; i < n; i++) {
		int start;
		cin >> start;
		if (start != -1) dist[i] = -start;
	}
	
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo.push_back(u);
		for (int i = 0; i < adjList[u].size(); i++) {
			int v = adjList[u][i].first;
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
			}
		}
	}
	// for (int i = 0; i < topo.size(); i++) {
	// 	cout << topo[i] << ' '; 
	// }
	for (int i = 0; i < topo.size(); i++) {
		int u = topo[i];
		if (dist[u] == INF) continue;
		if (adjList[u].size() == 0) fprintf(stdout, "%.3lf", -dist[u]);
		for (int j = 0; j < adjList[u].size(); j++) {
			int v = adjList[u][j].first;
			int w = adjList[u][j].second;
            if (hasPower[u][v]) {
                dist[v] = min(dist[v], -sqrt(-dist[u]) / (w / 100.0));
            } else {
                dist[v] = min(dist[v], dist[u] / (w / 100.0));
            }
			
		}
	}

	return 0;
}