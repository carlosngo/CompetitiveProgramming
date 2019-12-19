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
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin >> line;
        int l = 0, r = 0, u = 0, d = 0;
        int moves = line.length();
        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];
            if (ch == 'U') u++;
            else if (ch == 'D') d++;
            else if (ch == 'L') l++;
            else r++;
        }
        int lr = min(l, r) * 2;
        int ud = min(u, d) * 2;
        if (lr == 0 && ud != 0) cout << "2\nUD";
        else if (lr != 0 && ud == 0) cout << "2\nLR";
        else  {
            int ans = lr + ud;
            cout << ans << '\n';
            for (int i = 0; i < lr / 2; i++) cout << "L";
            for (int i = 0; i < ud / 2; i++) cout << "U";
            for (int i = 0; i < lr / 2; i++) cout << "R";
            for (int i = 0; i < ud / 2; i++) cout << "D";
        }
        
        cout << '\n';
    }
	return 0;
}