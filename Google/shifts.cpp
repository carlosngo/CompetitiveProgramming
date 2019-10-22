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
const int UNVISITED = -1;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, h;
        cin >> n >> h;
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vi happyA;
        vi happyB;
        for (int mask = 0; mask < (1 << n); mask++) {
            ll aTotal = 0;
            ll bTotal = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    aTotal += a[i];
                    bTotal += b[i];
                }
            }
            if (aTotal >= h) happyA.PB(mask);
            if (bTotal >= h) happyB.PB(mask);
        }
        int ans = 0;
        for (int i = 0; i < happyA.size(); i++) {
            for (int j = 0; j < happyB.size(); j++) {
                int x = happyA[i];
                int y = happyB[j];
                if ((x | y) == (1 << n) - 1) ans++;
            }
        }
        
        cout << "Case #" << tc << ": " << ans << '\n';
    }
	return 0;
}