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
    int n;
    cin >> n;
    int arr[2 * n + 1];
    for (int i = 1; i < 2 * n + 1; i += 2) cin >> arr[i];
    for (int a = 0; a <= 10000; a++) {
        for (int b = 0; b <= 10000; b++) {
            bool valid = true;
            for (int i = 2; i < 2 * n; i += 2) {
                arr[i] = (a * arr[i - 1] + b) % 10001;
                if (arr[i + 1] != (a * arr[i] + b) % 10001) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                arr[2 * n] = (a * arr[2 * n - 1] + b) % 10001;
                for (int i = 2; i < 2 * n + 1; i += 2) {
                    cout << arr[i] << '\n';
                }   
                return 0;
            }
        }
    }

	return 0;
}