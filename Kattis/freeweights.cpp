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
    int n;
    SCD(n);
    int r1[n];
    int r2[n];
    set<int> weights;
    bool perfect = n % 2 == 0;
    for (int i = 0; i < n; i++) {
        SCD(r1[i]);
        weights.insert(r1[i]);
        if (i % 2) {
            if (r1[i] != r1[i - 1]) perfect = false;
        }
    }
    for (int i = 0; i < n; i++) {
        SCD(r2[i]);
        weights.insert(r2[i]);
        if (i % 2) {
            if (r2[i] != r2[i - 1]) perfect = false;
        }
    }
    if (perfect) {
        fprintf(stdout, "0");
        return 0;
    } 
    vi arr(weights.begin(), weights.end());
    int lo = 0;
    int hi = arr.size() - 1;
    int ans = INT_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int maxW = arr[mid];
        // printf("%d\n", maxW);
        vi newR1;
        vi newR2;
        for (int i = 0; i < n; i++) {
            if (r1[i] > maxW) newR1.PB(r1[i]);
            if (r2[i] > maxW) newR2.PB(r2[i]);
        }
        bool valid = true;
        for (int i = 0; i < newR1.size(); i += 2 ) {
            if (i + 1 >= newR1.size() || newR1[i] != newR1[i + 1]) valid = false;
        }
        for (int i = 0; i < newR2.size(); i += 2) {
            if (i + 1 >= newR2.size() || newR2[i] != newR2[i + 1]) valid = false;
        }
        if (valid) {
            ans = maxW;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    fprintf(stdout, "%d\n", ans);
	return 0;
}