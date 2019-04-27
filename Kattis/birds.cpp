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
	int l, d, n;
    SCD(l);
    SCD(d);
    SCD(n);
    vi birds;
    ll ans = 0;
    if (n == 0) {
        int distanceBetweenPoles = l - 12;
        if (distanceBetweenPoles >= 0) ans = distanceBetweenPoles / d + 1;
        fprintf(stdout, "%lld", ans);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int pos;
        SCD(pos);
        birds.PB(pos);
    }
    sort(birds.begin(), birds.end());
    int distFromLeftPole = birds[0] - d - 6;
    if (distFromLeftPole >= 0) {
        ans += distFromLeftPole / d + 1;
    }
    int distFromRightPole = l - birds[n - 1] - d - 6;
    if (distFromRightPole >= 0) {
        ans += distFromRightPole / d + 1;
    }
    for (int i = 0; i < birds.size() - 1; i++) {
        int dist = birds[i + 1] - birds[i] - 2 * d;
        if (dist >= 0) {
            ans += dist / d + 1;
        }
    }
    fprintf(stdout, "%lld", ans);
	return 0;
}