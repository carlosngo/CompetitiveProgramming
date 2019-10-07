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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR(a, 0, t, 1) {
        int n, x, y;
        cin >> n >> x >> y;
        ii pts[n];
        FOR(i, 0, n, 1) cin >> pts[i].first >> pts[i].second;
        bool found = false;
        cout << "Case #" << (a + 1) << ": ";
        FOR(i, 0, n, 1) { 
            if (found) break;
            FOR(j, i + 1, n, 1) {
                int mDistance = abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
                double eDistance = sqrt((pts[i].first - pts[j].first) * (pts[i].first - pts[j].first) + (pts[i].second - pts[j].second) * (pts[i].second - pts[j].second)); 
                if (eDistance == floor(eDistance)) {
                    if (mDistance == x && int(eDistance) == y) {
                        if (pts[i].first < pts[j].first) {
                            cout << "(" << pts[i].first << "," << pts[i].second << ") (" << pts[j].first << "," << pts[j].second << ")\n";
                        } else if (pts[i].first > pts[j].first) {
                            cout << "(" << pts[j].first << "," << pts[j].second << ") (" << pts[i].first << "," << pts[i].second << ")\n";    
                        } else {
                            if (pts[i].second < pts[j].second) {
                                cout << "(" << pts[i].first << "," << pts[i].second << ") (" << pts[j].first << "," << pts[j].second << ")\n";
                            } else {
                                cout << "(" << pts[j].first << "," << pts[j].second << ") (" << pts[i].first << "," << pts[i].second << ")\n";
                            }   
                        }
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    
	
	return 0;
}