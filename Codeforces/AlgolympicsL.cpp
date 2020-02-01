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
const ll INF = 1000000000LL;

int main() {
    ll pows[100001];
    pows[0] = 1;
    for (int i = 1; i < 100001; i++) {
        pows[i] = (2 * (pows[i - 1] % INF)) % INF;
    }
    int n, k;
    cin >> n >> k;
    ll total = 0;
    priority_queue<int, vi, less<int> > mooks;
    priority_queue<int, vi, greater<int> > meeks;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "MEEK") {
            meeks.push(i);
        } else {
            mooks.push(i);
            total = (total + (pows[i])) % INF;
        }
    }
    if (n > 2) {
        if (!meeks.empty() && !mooks.empty()) {
            while (k > 0) {
                k--;
                int mook = mooks.top(); 
                int meek = meeks.top();
                if (meek < mook) {
                    mooks.pop();
                    meeks.pop();
                    total = (total - (pows[mook])) % INF;
                    total = (total + (pows[meek])) % INF;
                    meeks.push(mook);
                    mooks.push(meek);
                } else break;
            }
        }
        cout << total;
    } else {
        if (mooks.empty()) cout << 0;
        else if (meeks.empty()) cout << 3;
        else {
            if ((k & 1) == 1) cout << (pows[meeks.top()]);
            else cout << (pows[mooks.top()]);
        }
    }
	return 0;
}