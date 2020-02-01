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


int main() {
    vector<ll> primes;
    bitset<1000001> bs;
    ll MAX_N = 1000000;
    for (ll i = 2; i < MAX_N; i++) {
        if (!bs.test(i)) {
            primes.PB(i);
            for (ll j = i * i; j < MAX_N; j += i) {
                bs.set(j);
            }
        }
    }
    int n, m;
    cin >> n >> m;
    unordered_map<ll, ll> occ;
    for (int i = 0; i < n; i++) {
        ll N;
        cin >> N;
        vector<ll> pFactors;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= N; j++) {
            if (N % primes[j] == 0) pFactors.PB(primes[j]);
            while (N % primes[j] == 0) N /= primes[j];
        } 
        if (N != 1) pFactors.PB(N);
        vector<ll> x;
        x.PB(1);
        // cout << "factors of " << N << '\n';
        for (int j = 0; j < pFactors.size(); j++) {
            ll factor = pFactors[j];
            // cout << factor << ' ';
            int s = x.size();
            for (int k = 0; k < s; k++) {
                ll prod = x[k] * factor;
                // cout << prod << '\n';
                ++occ[prod];
                x.PB(prod);
            }
        }
        // cout << '\n';
    }
    ll ans = n * m;
    for (int i = 0; i < m; i++) {
        ll N;
        cin >> N;
        N--;
        vector<ll> pFactors;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= N; j++) {
            if (N % primes[j] == 0) pFactors.PB(primes[j]);
            while (N % primes[j] == 0) N /= primes[j];
        }
        if (N != 1) pFactors.PB(N);
        vector<pair<ll, ll> > x;
        x.PB(pair<ll, ll>(0, 1));
        
        // cout << "factors of " << N << '\n';
        for (int j = 0; j < pFactors.size(); j++) {
            ll factor = pFactors[j];
            // cout << factor << ' ';
            int s = x.size();
            for (int k = 0; k < s; k++) {
                ll numFactors = x[k].first + 1;
                ll prod = x[k].second * factor;
                x.PB(pair<ll, ll>(numFactors, prod));
                if (numFactors % 2 == 1) {
                    ans -= occ[prod];
                } else {
                    ans += occ[prod];
                }
            }
        }
        // cout << '\n';
    }
    cout << ans;
	return 0;
}