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
typedef pair<int, iii> iiii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> ppll;
typedef pair<ll, ppll> pppll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
	pppll ans[801];
    ans[1] = pppll(2, ppll(2, pll(1, 0)));
    ans[2] = pppll(11, ppll(16, pll(8, 4)));
    for (int i = 3; i < 801; i++) {
        pppll val;
        val.first = (ans[i - 1].first * 2 + ans[i - 2].first * 7) ;
        val.second.first = ((ans[i - 1].second.first * 2) + (ans[i - 1].first * 2) + 
            (ans[i - 2].second.first * 7) + (ans[i - 2].first * 8));
        val.second.second.first = ((ans[i - 1].second.second.first * 2) + (ans[i - 1].first) + 
            (ans[i - 2].second.second.first * 7) + (ans[i - 2].first * 4));
        val.second.second.second = ((ans[i - 1].second.second.second * 2) + 
            (ans[i - 2].second.second.second * 7) + (ans[i - 2].first * 4));
        ans[i] = val;
        
    }
    WHILEZ {
        int ctr, n;
        SCD(ctr); SCD(n);
        fprintf(stdout, "%d %lld %lld %lld %lld\n", ctr, ans[n].first % (1000000000 + 7), ans[n].second.first % (1000000000 + 7), ans[n].second.second.first  % (1000000000 + 7), ans[n].second.second.second  % (1000000000 + 7));
    }

	return 0;
}