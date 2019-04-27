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
 
vii segments;
 
double check(double c) {
    double time = 0;
    FOR (i, 0, segments.size(), 1) {
        time += segments[i].first / (segments[i].second + c);
        // printf("%lf = %d / (%d + %lf)\n",segments[i].first / (segments[i].second + c),segments[i].first,segments[i].second,c);
    }
    return time;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *pFile = fopen("NeedForSpeed.txt","w");
    int n, t;
    while (SCD(n) == 1) {
        SCD(t);
        segments.clear();
        FOR(i, 0, n, 1) {
            int l, r;
            SCD(l); SCD(r);
            segments.PB(ii(l, r));  
        }  
        ll lo = -100000000000000000, hi = 100000000000000000;
        double ans = 0.0;
        while (lo < hi) {
            ll mid = (lo + hi);
            if(mid >= 0) {
                mid /= 2;
            } else if(mid % 2 == 0){
                mid = mid / 2;
            } else {
                mid = (mid - 1) / 2;
            }
            double test = check(mid / 10000000000.0);
            // printf("lo,hi,mid,test = %lld,%lld,%lld,%lf\n",lo,hi,mid,test);
 
            bool hasNeg = false;
            FOR(i,0,segments.size(),1) {
                if(segments[i].second + mid / 10000000000.0 < 0 ||
                    segments[i].second + mid / 10000000000.0 < 1e-9 &&
                    segments[i].first != 0) {
                    hasNeg = true;
                    break;
                }
            }
            // printf("hasNeg = %d\n",hasNeg);
            if (test > t || hasNeg) {
                lo = mid + 1;
            } else {
                hi = mid;
                ans = mid / 10000000000.0;
            }
        }
        printf("%.9lf\n", ans);
        fprintf(pFile, "%.9lf\n", ans);
    }
    fclose(pFile);
    return 0;
}