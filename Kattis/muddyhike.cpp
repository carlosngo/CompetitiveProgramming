#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
// CHECKING BOUNDS
#define LIN(i,l,r) (l<=i&&i<r)
// LOOPS
#define PB push_back

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int UNVISITED = -1;

class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

int src, dest;
int r, c;
int ans;
int grid[1001][1001];
bitset<1100000> visited;
vector<vii> adjList;

int convertTo1D(int row, int col) {
    return c * row + col;
}

void dfs(int u, int maxW) {
    // cout << u;
    visited.set(u);
    if (u == dest) {
        ans = maxW;
    }
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (!visited.test(v)) {       
            dfs(v, max(maxW, adjList[u][i].second));
        }
    }    
}

int main() {
    SCD(r);
    SCD(c);
    UnionFind ufds(r * c + 2);
    src = r * c;
    dest = r * c + 1;
    adjList = vector<vii>(r * c + 2, vii());
    visited = bitset<1100000>();
    vector<iii> edges;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            SCD(grid[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c ; j++) {
            int u = convertTo1D(i, j);
            for (int k = 0; k < 4; k++) {
                int nextR = i + fx[k][0];
                int nextC = j + fx[k][1];
                if (LIN(nextR, 0, r) && LIN(nextC, 0, c)) {
                    int v = convertTo1D(nextR, nextC);
                    if (v > u) {
                        edges.PB(iii(max(grid[i][j], grid[nextR][nextC]), ii(u, v)));
                    }
                }
            }
        }
    }
    // cout << "hi";
    for (int i = 0; i < r; i++) {
        int u = convertTo1D(i, 0);
        int v = convertTo1D(i, c - 1);
        edges.PB(iii(grid[i][0], ii(u, src)));
        edges.PB(iii(0, ii(v, dest)));
    }
    // cout << "hi";
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (!ufds.isSameSet(u, v)) {
            ufds.unionSet(u, v);
            adjList[u].PB(ii(v, w));
            adjList[v].PB(ii(u, w));
        }
    }
    ans = INT_MIN;
    dfs(src, ans);
    fprintf(stdout, "%d", ans);
	return 0;
}