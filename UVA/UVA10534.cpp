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
    int n;
    while (SCD(n) == 1) {
        int arr[n];
        int lis[n];
        int lis_cnt = 0;
        int lis_ans[n];
        int lds[n];
        int lds_cnt = 0;
        int lds_ans[n];
        FOR (i, 0, n, 1) SCD(arr[i]);
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(lis, lis + lis_cnt, arr[i]) - lis;
            lis[pos] = arr[i];
            lis_cnt = max(lis_cnt, pos + 1);
            lis_ans[i] = lis_cnt;
        }
        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(lds, lds + lds_cnt, arr[i]) - lds;
            lds[pos] = arr[i];
            lds_cnt = max(lds_cnt, pos + 1);
            lds_ans[i] = lds_cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // printf ("Lis = %d, LDS = %d\n", lis[i], lds[i]);'
            int mini = min(lis_ans[i], lds_ans[i]);
            // if (lis[i] == lds[i])
                ans = max(ans, 2 * mini - 1);
        }

        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}