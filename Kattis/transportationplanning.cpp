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


typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;
const double INF = 1000000000.0;

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int n;
    while (cin >> n, n != 0) {
        vii pts(n);
        double adjMatrix[n][n];
        double dist[n][n];
        for (int i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
            // cout << pts[i].first << ' ' << pts[i].second << '\n';
            adjMatrix[i][i] = 0;
        }

        

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = pts[i].first, y1 = pts[i].second;
                int x2 = pts[j].first, y2 = pts[j].second;
                dist[i][j] = dist[j][i] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                
                adjMatrix[i][j] = INF;
                adjMatrix[j][i] = INF;
            }
        }

        bool used[n][n];
        memset(used, false, sizeof used);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            used[u][v] = true;
            used[v][u] = true;
            adjMatrix[u][v] = dist[u][v];
            adjMatrix[v][u] = dist[v][u];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
        double init = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                init += adjMatrix[i][j];
            }
        }
        double ans = init;
        int u, v;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!used[i][j]) {
                    double temp[n][n];
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < n; l++) {
                            temp[k][l] = adjMatrix[k][l];
                        }
                    }
                    temp[i][j] = dist[i][j];
                    temp[j][i] = dist[j][i];
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < n; l++) {
                            temp[k][l] = min(temp[k][l], temp[k][i] + temp[i][l]);
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < n; l++) {
                            temp[k][l] = min(temp[k][l], temp[k][j] + temp[j][l]);
                        }
                    }
                    double sum = 0;
                    for (int k = 0; k < n; k++) {
                        for (int l = k + 1; l < n; l++) {
                            sum += temp[k][l];
                        }
                    }
                    if (sum < ans) {
                        ans = sum;
                        u = i;
                        v = j;
                    }
                }

            }
        }
        if (ans == init) fprintf(stdout, "no addition reduces %.5lf\n", ans);
        else fprintf(stdout, "adding %d %d reduces %.5lf to %.5lf\n", u, v, init, ans);
    }
	return 0;
}