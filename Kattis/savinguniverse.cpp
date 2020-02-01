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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

int s, q;
vector<string> engines;
vi queries;
vvi memo;

int dp(int si, int qi) {
    if (si == s || qi == q) return 0;
    if (memo[si][qi] != UNVISITED) return memo[si][qi];
    int ans = INT_MAX;
    for (int i = 0; i < s; i++) {
        if (i != si) {
            ans = min(ans, 1 + dp(i, qi + 1));
        }
    }
    if (si != queries[qi]) ans = min(ans, dp(si, qi + 1));
    return memo[si][qi] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        cin >> s;
        unordered_map<string, int> m;
        engines = vector<string>(s);
        string str;
        getline(cin, str);
        for (int i = 0; i < s; i++) {
            getline(cin, str);
            engines[i] = str;
            m[str] = i;
        }
        cin >> q;
        getline(cin, str);
        queries = vi(q);
        for (int i = 0; i < q; i++) {
            getline(cin, str);
            queries[i] = m[str];
        }
        memo.assign(s, vi(q, UNVISITED));
        int ans = INT_MAX;
        for (int i = 0; i < s; i++) {
            ans = min(ans, dp(i, 0));
            // cout << "if start with " << i << ", ans = " << ans << '\n';
        }
        // for (int i = 0; i < s; i++) {
        //     for (int j = 0; j < q; j++) {
        //         cout << memo[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << "Case #" << T << ": " << ans << '\n';
    }
	return 0;
}