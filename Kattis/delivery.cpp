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
	int n, k;
    SCD(n);
    SCD(k);
    vii nega;
    vii posi;
    for (int i = 0; i < n; i++) {
        int x, t;
        SCD(x);
        SCD(t);
        if (x < 0) {
            nega.PB(ii(x, t));
        } else {
            posi.PB(ii(x, t));
        }
    }
    sort(nega.begin(), nega.end(), greater<ii>());
    sort(posi.begin(), posi.end());
    ll ans = 0;
    int currentStation = 0;
    while (!nega.empty() && nega[nega.size() - 1].second > 0) {
        int loc = abs(nega[currentStation].first);
        int letters = nega[currentStation].second;
        printf("Have to deliver %d letters at location %d. Traveled %lld.\n", letters, loc, ans);
        int roundTrips = (letters / k);
        int remainingLetters = letters % k;
        ans += 2 * loc * roundTrips;
        if (currentStation + 1 == nega.size()) {
            if (remainingLetters > 0) ans += 2 * loc;
        } else {
            nega[currentStation + 1].second += remainingLetters;
        }
        nega[currentStation].second = 0;
        currentStation++;
    }
    currentStation = 0;
    while (!posi.empty() && posi[posi.size() - 1].second > 0) {
        int loc = posi[currentStation].first;
        int letters = posi[currentStation].second;
        int roundTrips = (letters / k);
        ans += 2 * loc * roundTrips;
        if (currentStation + 1 == posi.size()) {
            ans += 2 * loc;
        } else {
            posi[currentStation + 1].second += letters % k;
        }
        posi[currentStation].second = 0;
        currentStation++;
    }
    printf("%lld\n", ans);
	return 0;
}