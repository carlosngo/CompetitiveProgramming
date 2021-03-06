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
#define INF 1000000000

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
    int m, n;
    while (scanf("%d %d", &m, &n), m || n) {
        int ans;
        int a = max(m, n);
        if (m == 0 || n == 0) {
            ans = 0;
        } else if (m == 1 || n == 1) {
            ans = a;
        } else if (m == 2 || n == 2) {
            int mod = a % 4;
            if (mod == 1) {
                ans = 4 * (a / 4) + 2;
            } else if (mod == 0) 
                ans = a;
            else 
                ans = 4 * (a / 4 + 1);
        } else 
            ans = (ceil(m * n / 2.0));
        printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
        fprintf(pFile, "%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }
	fclose(pFile);
	return 0;
}
