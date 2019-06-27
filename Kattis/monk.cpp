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

const double EPS = 1e-6;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int a, d;
    SCD(a); SCD(d);
    vii aSegments(a), dSegments(d);
    double hi = 0, lo = 0;
    double height = 0;
    for (int i = 0; i < a; i++) {
        SCD(aSegments[i].first); 
        SCD(aSegments[i].second);
    }
    for (int i = 0; i < d; i++) {
        SCD(dSegments[i].first); SCD(dSegments[i].second);
        hi += dSegments[i].second;
        height += dSegments[i].first;
    }
    bool found = false;
    while (!found) {
        double mid = (lo + hi) / 2;
        double aPos = 0;
        double aTime = 0;
        for (int i = 0; i < a; i++) {
            if (aTime + aSegments[i].second < mid) {
                aTime += aSegments[i].second;
                aPos += aSegments[i].first;
            } else {
                double rate = aSegments[i].first * 1.0 / aSegments[i].second;
                aPos += rate * (mid - aTime);
                break;
            }
        }
        double dPos = height;
        double dTime = 0;
        for (int i = 0; i < d; i++) {
            if (dTime + dSegments[i].second < mid) {
                dTime += dSegments[i].second;
                dPos -= dSegments[i].first;
            } else {
                double rate = dSegments[i].first * 1.0 / dSegments[i].second;
                dPos -= rate * (mid - dTime);
                break;
            }
        }
        // cout << "At t = " << mid << " aPos = " << aPos << " and dPos = " << dPos << '\n';
        
        if (fabs(hi - lo) < EPS) {
            fprintf(stdout, "%.6lf", mid);
            found = true;
        } else if (dPos > aPos) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return 0;
}