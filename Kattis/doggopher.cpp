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
#define EPS 1e-9

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int UNVISITED = -1;

int main() {
    double dx, dy, gx, gy;
    SCLF(gx);
    SCLF(gy);
    SCLF(dx);
    SCLF(dy);
    double x, y;
    vector<dd> pts;
    vector<double> dDist;
    vector<double> gDist;
    while (fscanf(stdin, "%lf %lf", &x, &y) == 2) {
        pts.PB(dd(x, y));
        dDist.PB(sqrt((dx - x) * (dx - x) + (dy - y) * (dy - y)));
        gDist.PB(sqrt((gx - x) * (gx - x) + (gy - y) * (gy - y)) * 2);
    }
    bool found = false;
    for (int i = 0; i < pts.size(); i++) {
        if (fabs(gDist[i] - dDist[i]) < EPS) {
            found = true;
            fprintf(stdout, "The gopher can escape through the hole at (%.3lf,%.3lf).", pts[i].first,pts[i].second);
            break;
        } else if (gDist[i] < dDist[i]) {
            found = true;
            fprintf(stdout, "The gopher can escape through the hole at (%.3lf,%.3lf).", pts[i].first,pts[i].second);
            break;
        } 
    }
    if (!found) fprintf(stdout, "The gopher cannot escape.");
	
	return 0;
}