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

int poss[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 51, 54, 57, 60};

vi taken;
bool found = false; 

void solve(int pos, int n) {
    if (pos == 41 || found || n < 0 || taken.size() > 3) return;
    else if (n == 0) {
        for (int i = 0; i < taken.size(); i++) {
            int score = taken[i];
            if (score <= 20) {
                cout << "single " << score << "\n";
            } else if (score % 2 == 0 && score / 2 <= 20) {
                cout << "double " << (score / 2) << "\n";
            } else {
                cout << "triple " << (score / 3) << "\n";
            }
        }
        found = true;
          
    } else {
        taken.push_back(poss[pos]);
        // cout << "N = " << n << "\n";
        // cout << "Taking " << poss[pos] << "\n";
        solve(pos, n - poss[pos]);
        taken.pop_back();
        solve(pos + 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    solve(0, n);
    if (!found) cout << "impossible";
	return 0;
}