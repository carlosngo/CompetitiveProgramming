#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int v, e;
    int ctr = 1;
    while (cin >> v >> e, v && e) {
        vvi adjMat(v, vi(v, INT_MAX));
        map<string, int> names;
        int curIndex = 0;
        while (e--) {
            string src, dest;
            cin >> src >> dest;
            if (names.find(src) == names.end()) {
                names[src] = curIndex;
                curIndex++;
            }
            if (names.find(dest) == names.end()) {
                names[dest] = curIndex;
                curIndex++;
            }
            adjMat[names[src]][names[dest]] = 1;
            adjMat[names[dest]][names[src]] = 1;
        }
        FOR (i, 0, v, 1) {
            adjMat[i][i] = 0;
        }
        vvi ans = adjMat;
        FOR (k, 0, v, 1) {
            FOR (i, 0, v, 1) {
                FOR (j, 0, v, 1) {
                    if (ans[i][k] != INT_MAX && ans[k][j] != INT_MAX)
                        ans[i][j] = min (ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
        int res = 0;
        FOR (i, 0, v, 1) {
            FOR (j, 0, v, 1) {
                res = max(res, ans[i][j]);
            }
        }
        printf("Network %d: ", ctr);
        fprintf(pFile, "Network %d: ", ctr);
        if (res == INT_MAX) {
            printf("DISCONNECTED\n");
            fprintf(pFile, "DISCONNECTED\n");
        } else {
            printf("%d\n", res);
            fprintf(pFile, "%d\n", res);
        }
        printf("\n");
        fprintf(pFile, "\n");
        ctr++;
    }
	fclose(pFile);
	return 0;
}