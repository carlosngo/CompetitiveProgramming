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

int n, m;
vi conts;
vi vess;

bool tryCapacity(int cap) {
    int curCap = 0;
    int num = 0;
    FOR (i, 0, vess.size(), 1) {
        if (vess[i] > cap) return false;
        if (vess[i] + curCap > cap) curCap = 0;
        if (curCap == 0) num++;  
        if (num > m) return false;
        curCap += vess[i];
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    while (fscanf(stdin, "%d %d", &n, &m) == 2) {
        conts = vi();
        vess = vi(n);
        int lo = 1;
        int hi = 0;
        FOR (i, 0, n, 1) {
            SCD(vess[i]);
            hi += vess[i];
        }
        int ans = 1;
        // printf("Lo = %d\n Hi = %d\n", lo, hi);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (tryCapacity(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
    }    
	fclose(pFile);
	return 0;
}