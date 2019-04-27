#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCLD(t) fscanf(stdin, "%ld",&t)
#define SCLLD(t) fscanf(stdin, "%lld",&t)
#define SCC(t) fscanf(stdin, "%c",&t)
#define SCS(t) fscanf(stdin, "%s",t)
#define SCF(t) fscanf(stdin, "%f",&t)
#define SCLF(t) fscanf(stdin, "%lf",&t)
// CHECKING BOUNDS
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// LOOPS
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define WHILEZ int T; SCD(T); while(T--) 
// MISC
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define PB push_back
#define INF 1000000000

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

// class Node {
//     public:
//         int color;
//         int ind;
//         Node(int _ind) {
//             color = -1;
//             ind = _ind;
//         }
// };

vvi adjList;
vi graph;
vi most;
int m, n, k;
int ans;
int cnt;

void solve(int pos, int black) {
    if (pos == n) {
        // printf("Reached the end.");
        if (black > ans) {
            ans = black;
            most = graph;
        }
    } else {
        // if (graph[pos] == -1) {
            printf("Checking node #%d\n", pos);
            vi temp = graph;
            // BFS BLACK
            graph[pos] = 1;
            // cnt += dfs(pos);
            cnt = 1;
            queue<int> q;
            q.push(pos);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int adj = adjList[cur][i];
                    if (graph[adj] == -1) {
                        bool flag = false;
                        for (int j = 0; j < adjList[adj].size() && !flag; j++) {
                            if (graph[adjList[adj][j]] == 1) flag = true;
                        }
                        if (graph[cur] == 0 && !flag) {
                            graph[adj] = 1;
                            cnt++;
                        } else 
                            graph[adj] = 0;
                        q.push(adj);
                    }
                }
            }
            printf("Done DFS black. Found %d black nodes\n", cnt);
            solve(pos + 1, black + cnt);
            // REVERT AND BFS WHITE
            graph = temp;
            q = queue<int>();
            graph[pos] = 0;
            cnt = 0;
            q.push(pos);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int adj = adjList[cur][i];
                    if (graph[adj] == -1) {
                        bool flag = false;
                        for (int j = 0; j < adjList[adj].size() && !flag; j++) {
                            if (graph[adjList[adj][j]] == 1) flag = true;
                        }
                        if (graph[cur] == 0 && !flag) {
                            graph[adj] = 1;
                            cnt++;
                        } else 
                            graph[adj] = 0;
                        q.push(adj);
                    }
                }
            }
            printf("Done DFS white. Found %d black nodes\n", cnt);
            solve(pos + 1, black + cnt);
        // } else {
        //     solve(pos + 1, black);
        // }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    SCD(m);
    FOR(a, 0, m, 1) {
        // if (a > 0) {
        //     fprintf(stdout, "\n");
        //     fprintf(pFile, "\n");
        // }
        SCD(n); SCD(k);
        adjList = vvi(n, vi());
        graph = vi(n, -1);
        // FOR(i, 0, graph.size(), 1) printf("%d ", graph[i]);
        ans = 0;
        FOR (i, 0, k, 1) {
            int fro, to;
            SCD(fro); SCD(to);
            fro--; to--;
            adjList[fro].PB(to);
            adjList[to].PB(fro);
        }
        // for (int i = 0; i < adjList.size(); i++) {
        //     printf("%d -> ", i);
        //     for (int j = 0; j < adjList[i].size(); j++) {
        //         printf("%d ", adjList[i][j]);
        //     }
        //     printf("\n");
        // }
        solve(0, 0);
        fprintf(stdout, "%d\n", ans);
        fprintf(pFile, "%d\n", ans);
        int ctr = 0;
        for (int i = 0; i < most.size(); i++) {
            
            if (most[i] == 1) {
                if (ctr > 0) {
                    fprintf(stdout, " ");
                    fprintf(pFile, " ");
                }
                fprintf(stdout, "%d", i + 1);
                fprintf(pFile, "%d", i + 1);
                ctr++;
            }
        }
        fprintf(stdout, "\n");
        fprintf(pFile, "\n");
    }
	fclose(pFile);
	return 0;
}