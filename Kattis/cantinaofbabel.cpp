#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

const int UNVISITED = -1;

int components;
bitset<101> visited;
vvi adjList;
vi dfs_low, dfs_num, S;
int dfs_ctr, ans;


void tarjan(int u) {
    dfs_low[u] = dfs_num[u] = dfs_ctr++;
    S.PB(u);
    visited.set(u);
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            tarjan(v);
        }
        if (visited.test(v)) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } 
    }
    if (dfs_low[u] == dfs_num[u]) {
        components = 0;
        while (1) {
            int v = S.back(); S.pop_back();
            visited.reset(v);
            components++;
            if (u == v) break;
        }
        ans = max(ans, components);
    }
}

int main() {
	int n;
    cin >> n;
    string line;
    getline(cin, line);
    dfs_low.assign(n, UNVISITED);
    dfs_num.assign(n, UNVISITED);
    dfs_ctr = 0;
    unordered_set<string> s;
    unordered_map<string, int> langToIndex;
    vi langSpoken(n);
    vvi listeners;
    adjList = vvi(n, vi());
    visited = bitset<101>();
    vector<string> languages;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string ch;
        ss >> ch;
        string spoken;
        ss >> spoken;
        if (!s.count(spoken)) {
            langToIndex[spoken] = languages.size();
            listeners.PB(vi());
            listeners[languages.size()].PB(i);
            langSpoken[i] = languages.size();
            s.insert(spoken);
            languages.PB(spoken);
        } else {
            int index = langToIndex[spoken];
            langSpoken[i] = index;
            listeners[index].PB(i);
        }
        string lang;
        while (ss >> lang) {
            if (!s.count(lang)) {
                langToIndex[lang] = languages.size();
                listeners.PB(vi());
                listeners[languages.size()].PB(i);
                s.insert(lang);
                languages.PB(lang);
            } else {
                int index = langToIndex[lang];
                listeners[index].PB(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int index = langSpoken[i];
        for (int j = 0; j < listeners[index].size(); j++) {
            int v = listeners[index][j];
            if (i == v) continue;
            adjList[i].PB(v);
        }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        components = 0;
        if (!visited.test(i)) {
            tarjan(i); 
        }
    }
    cout << (n - ans);
	return 0;
}