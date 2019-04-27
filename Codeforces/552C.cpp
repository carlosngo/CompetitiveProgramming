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
    ll a, b, c;
    cin >> a >> b >> c;
    ll aWeeks = a / 3;
    ll bWeeks = b / 2;
    ll cWeeks = c / 2;
    ll minWeeks = min(aWeeks, min(bWeeks, cWeeks));
    a -= 3 * minWeeks;
    b -= 2 * minWeeks;
    c -= 2 * minWeeks;
    ll days = minWeeks * 7;
    ll ans = days;
	if (a >= 0 && b >= 0 && c >= 0) ans = minWeeks * 7;
    if (a >= 0 && b >= 0 && c >= 1) ans = max(ans, days + 1);
    if (a >= 0 && b >= 0 && c >= 2) ans = max(ans, days + 1);
    if (a >= 0 && b >= 1 && c >= 0) ans = max(ans, days + 1);
    if (a >= 0 && b >= 1 && c >= 1) ans = max(ans, days + 2);
    if (a >= 0 && b >= 1 && c >= 2) ans = max(ans, days + 2);
    if (a >= 0 && b >= 2 && c >= 0) ans = max(ans, days + 1);
    if (a >= 0 && b >= 2 && c >= 1) ans = max(ans, days + 2);
    if (a >= 0 && b >= 2 && c >= 2) ans = max(ans, days + 2);
    if (a >= 1 && b >= 0 && c >= 0) ans = max(ans, days + 1);
    if (a >= 1 && b >= 0 && c >= 1) ans = max(ans, days + 2);
    if (a >= 1 && b >= 0 && c >= 2) ans = max(ans, days + 3);
    if (a >= 1 && b >= 1 && c >= 0) ans = max(ans, days + 2);
    if (a >= 1 && b >= 1 && c >= 1) ans = max(ans, days + 3);
    if (a >= 1 && b >= 1 && c >= 2) ans = max(ans, days + 4);
    if (a >= 1 && b >= 2 && c >= 0) ans = max(ans, days + 2);
    if (a >= 1 && b >= 2 && c >= 1) ans = max(ans, days + 3);
    if (a >= 1 && b >= 2 && c >= 2) ans = max(ans, days + 5);
    if (a >= 2 && b >= 0 && c >= 0) ans = max(ans, days + 2);
    if (a >= 2 && b >= 0 && c >= 1) ans = max(ans, days + 2);
    if (a >= 2 && b >= 0 && c >= 2) ans = max(ans, days + 3);
    if (a >= 2 && b >= 1 && c >= 0) ans = max(ans, days + 3);
    if (a >= 2 && b >= 1 && c >= 1) ans = max(ans, days + 4);
    if (a >= 2 && b >= 1 && c >= 2) ans = max(ans, days + 5);
    if (a >= 2 && b >= 2 && c >= 0) ans = max(ans, days + 4);
    if (a >= 2 && b >= 2 && c >= 1) ans = max(ans, days + 5);
    if (a >= 2 && b >= 2 && c >= 2) ans = max(ans, days + 6);
    
    if (a >= 3 && b >= 0 && c >= 0) ans = max(ans, days + 2);
    if (a >= 3 && b >= 0 && c >= 1) ans = max(ans, days + 2);
    if (a >= 3 && b >= 0 && c >= 2) ans = max(ans, days + 3);
    if (a >= 3 && b >= 1 && c >= 0) ans = max(ans, days + 3);
    if (a >= 3 && b >= 1 && c >= 1) ans = max(ans, days + 5);
    if (a >= 3 && b >= 1 && c >= 2) ans = max(ans, days + 6);
    if (a >= 3 && b >= 2 && c >= 0) ans = max(ans, days + 4);
    if (a >= 3 && b >= 2 && c >= 1) ans = max(ans, days + 6);
    if (a >= 3 && b >= 2 && c >= 2) ans = max(ans, days + 7);
    cout << ans;
	return 0;
}