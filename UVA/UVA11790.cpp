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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    int ctr = 1;
    while (t--) {
        int n;
        SCD(n);
        int w[n];
        int h[n];
        int lis[n];
        int lds[n];
        int lis_id[n];
        int lds_id[n];
        FOR (i, 0, n, 1) SCD(h[i]);
        FOR (i, 0, n, 1) SCD(w[i]);
        for (int i = 0; i < n; i++) {
            int maxLIS = 0;
            int maxLDS = 0;
            for (int j = 0; j < i; j++) {
                if (h[j] < h[i]) {
                    if (lis[j] > maxLIS) {
                        maxLIS = lis[j];
                    }
                }
                if (h[j] > h[i]) {
                    if (lds[j] > maxLDS) {
                        maxLDS = lds[j];
                    }
                }
            }
            lis[i] = maxLIS + w[i];
            lds[i] = maxLDS + w[i];
        }
        int maxLIS = 0;
        int maxLDS = 0;
        FOR (i, 0, n, 1) {
            if (lis[i] > maxLIS) {
                maxLIS = lis[i];
            }
            if (lds[i] > maxLDS) {
                maxLDS = lds[i];
            }
        }
        // printf("LIS of length %d: ", maxLIS);
        // printf("%d ", h[lis_end]);
        // while (lis_id[lis_end] >= 0) {
        //     printf("%d ", h[lis_id[lis_end]]);
        //     lisAns += w[lis_id[lis_end]];
        //     lis_end = lis_id[lis_end];
        // }
        // printf("%d\n", w[lis_end]);
        // lisAns += w[lis_end];
        // printf("\nLDS of length %d: ", maxLDS);
        // printf("%d ", h[lds_end]);
        // while (lds_id[lds_end] >= 0) {
        //     printf("%d ", h[lds_id[lds_end]]);
        //     ldsAns += w[lds_id[lds_end]];
        //     lds_end = lds_id[lds_end];
        // }
        // printf("%d\n", w[lds_end]);
        // ldsAns += w[lds_end];
        if (maxLIS >= maxLDS) {
            fprintf(stdout, "Case %d. Increasing (%d). Decreasing (%d).\n", ctr, maxLIS, maxLDS);
            // fprintf(pFile, "Case %d. Increasing (%d). Decreasing (%d).\n", ctr, maxLIS, maxLDS);
        } else {
            fprintf(stdout, "Case %d. Decreasing (%d). Increasing (%d).\n", ctr, maxLDS, maxLIS);
            // fprintf(pFile, "Case %d. Decreasing (%d). Increasing (%d).\n", ctr, maxLDS, maxLIS);
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}