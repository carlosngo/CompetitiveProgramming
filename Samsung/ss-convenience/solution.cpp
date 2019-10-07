#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, int> li;

ll minDist[100002];
vector<vii> adjList;
int s, m, l;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> s >> m >> l;
    adjList = vector<vii>(s, vii());
    vi stores(m);
    for (int i = 0; i < m; i++) {
        int node;
        cin >> node;
        node--;
        stores[i] = node;
    }
    for (int i = 0; i < l; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adjList[v].push_back(ii(u, w));
    }
    for (int i = 0; i < s; i++) {
        minDist[i] = LLONG_MAX;
    }
    
    priority_queue<li, vector<li>, greater<li> > pq;
    for (int i = 0; i < m; i++) {
        minDist[stores[i]] = 0;
        pq.push(li(0, stores[i]));
    }
    while (!pq.empty()) {
        int curV = pq.top().second;
        ll curW = pq.top().first;
        pq.pop();
        for (int j = 0; j < adjList[curV].size(); j++) {
            int nextV = adjList[curV][j].first;
            int nextW = adjList[curV][j].second;
            if (minDist[nextV] == LLONG_MAX || minDist[curV] + nextW < minDist[nextV]) {
                minDist[nextV] = minDist[curV] + nextW;
                pq.push(li(minDist[nextV], nextV));
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < s; i++) {
        ans = max(ans, minDist[i]);
    }
    cout << ans;
	return 0;
}