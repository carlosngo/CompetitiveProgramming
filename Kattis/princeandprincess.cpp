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
    int t;
    SCD(t);
    int ctr = 1;
    while (t--) {
        int n, p, q;
        SCD(n); SCD(p); SCD(q);
        int m[n * n];
        memset(m, INF, sizeof m);
        for (int i = 0; i < p + 1; i++) {
            int mov;
            SCD(mov);
            mov--;
            m[mov] = i; 
        }
        int ans;
        int lis[q + 1];
        int lis_cnt = 0;
        for (int i = 0; i < q + 1; i++) {
            int jmp;
            SCD(jmp);
            jmp--;
            int pos = lower_bound(lis, lis + lis_cnt, m[jmp]) - lis;
            lis[pos] = m[jmp];
            if (pos + 1 > lis_cnt) {
                lis_cnt = pos + 1;
            }
        }
        fprintf(stdout, "Case %d: %d\n", ctr, lis_cnt);
        ctr++;
    }
	return 0;
}