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
    int t; SCD(t);
    while (t--) {
        int city[25];
        FOR (i, 0, 25, 1) city[i] = 0;
        int n; SCD(n);
        int ans[5];
        bitset<25> bs;
        while (n--) {
            int r, c, p;
            SCD(r); SCD(c); SCD(p);
            city[r * 5 + c] = p;
        }
        FOR (i, 0, 5, 1) {
            ii opt = ii(-1, INT_MIN);
            FOR (j, 0, 25, 1) {
                if (!bs.test(j)) {
                    if (city[j] > opt.second) {
                        opt.first = j;
                        opt.second = city[j];
                    } 
                }
            }
            ans[i] = opt.first;
            bs.set(opt.first);
        }
        sort(ans, ans + 5);
        fprintf(stdout, "%d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
        fprintf(pFile, "%d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);

    }
	fclose(pFile);
	return 0;
}