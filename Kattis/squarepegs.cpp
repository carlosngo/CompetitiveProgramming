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
    int n, m, k;
    cin >> n >> m >> k;
    int plotSizes[n];
    int circles[m];
    int squares[k];
    FOR (i, 0, n, 1) cin >> plotSizes[i];
    FOR (i, 0, m, 1) cin >> circles[i];
    FOR (i, 0, k, 1) cin >> squares[i];
    sort(plotSizes, plotSizes + n);
    sort(circles, circles + m);
    sort(squares, squares + k);
    int ans = 0;
    int circleInd = 0;
    int squareInd = 0;
    for (int i = 0; i < n; i++) {
        int circleReq = plotSizes[i] - 1;
        int squareReq = sqrt((2 * plotSizes[i]) * (2 * plotSizes[i]) / 2.0);
        int circleDiff = -1;
        if (circleInd < m && circles[circleInd] <= circleReq) circleDiff = circleReq - circles[circleInd];
        int squareDiff = -1;
        if (squareInd < k && squares[squareInd] <= squareReq) squareDiff = squareReq - squares[squareInd] ;
             
        // printf("Square Req = %d, Circle Req = %d, Square Diff = %d, Circle Diff = %d\n", squareReq, circleReq, squareDiff, circleDiff);
        if (squareDiff == -1 && circleDiff == -1) continue;
        else if (squareDiff == -1) {
            circleInd++;
            ans++;
        } else if (circleDiff == -1) {
            squareInd++;
            ans++;
        } else {
            ans++;
            if (circleDiff > squareDiff) squareInd++;
            else circleInd++;
        }
    }
	cout << ans;
	return 0;
}