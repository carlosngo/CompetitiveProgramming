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

int l, w, n, r;
ii cranes[30];
pair<double, double> walls[4];
vii taken;
bitset<4> hitWalls; 
int ans = INT_MAX;

bool hasReachedAll() {
    bool hasReached = true;
    for (int i = 0; i < 4; i++) if (!hitWalls.test(i)) hasReached = false;
    return hasReached;
}

void solve(int pos) {
    if (hasReachedAll()) ans = min(ans, (int)taken.size()); 
    else if (pos == n) return;
    else if (taken.size() > ans) return;
    else {
        taken.push_back(cranes[pos]);
        bitset<4> temp = hitWalls;
        for (int i = 0; i < 4; i++) {
            double x1 = walls[i].first, y1 = walls[i].second;
            int x2 = cranes[pos].first, y2 = cranes[pos].second;
            if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) <= r) {
                hitWalls.set(i);
            }
        }
        solve(pos + 1);
        taken.pop_back();
        hitWalls = temp;
        solve(pos + 1);
    }
}

int main() {
    cin >> l >> w >> n >> r;
    for (int i = 0; i < n; i++) cin >> cranes[i].first >> cranes[i].second;
    walls[0].first = -l/2.0, walls[0].second = 0;
    walls[1].first = l/2.0, walls[1].second = 0;
    walls[2].first = 0, walls[2].second = -w/2.0;
    walls[3].first = 0, walls[3].second = w/2.0;
    solve(0);
	if (ans == INT_MAX) cout << "Impossible";
    else cout << ans;
	return 0;
}