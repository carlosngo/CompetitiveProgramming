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
    int q;
    cin >> q;
    while (q--) {
        ll n, m;
        cin >> n >> m;
        ll divisors = n / m;
        ll ans = 0;
        int last_digit = m % 10;
        if (divisors == 0 || last_digit == 0) {
            cout << 0 << '\n';
            continue;
        }
        int pattern[10][10] = {0};
        for (int i = 0; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                pattern[i][j] = (i + 1) * j % 10;
                // cout << pattern[i][j] << ' ';
            }
            // cout << '\n';
        }
        if (last_digit % 2) {
            for (int i = 1; i < 10; i++) {
                ans += pattern[last_digit - 1][i] * (divisors / 10);
                if (i <= divisors % 10) ans += pattern[last_digit - 1][i];
            }
        } else {
            for (int i = 1; i < 5; i ++) {
                ans += pattern[last_digit - 1][i] * (divisors / 5);
                if (i <= divisors % 5) ans += pattern[last_digit - 1][i];
            }
        }
        // switch (m % 10) {
        //     case 1:
        //         for (int i = 1; i < 10; i++) {
        //             ans += i * (divisors / 10);
        //             if (i <= divisors % 10) ans += i;
        //         }
        //         break;
        //     case 2:
        //         for (int i = 2; i < 9; i += 2) {
        //             ans += i * (divisors / 5);
        //             if (i / 2 <= divisors % 5) ans += i;
        //         }
        //         break;
        //     case 3:
        //         int pattern[] = {0, 3, 6, 9, 2, 5, 8, 1, 4, 7}; 
        //         for (int i = 1; i < 10; i++) {
        //             ans += pattern[i] * (divisors / 10);
        //             if (i <= divisors % 10) ans += pattern[i];
        //         }
        //         break;
        //     case 4:
        //         break;
        //     case 5:
        //         break;
        //     case 6:
        //         break;
        //     case 7:
        //         break;
        //     case 8:
        //         break;
        //     case 9:
        //         break;
                
        // }
        cout << ans << '\n';
    }
	return 0;
}