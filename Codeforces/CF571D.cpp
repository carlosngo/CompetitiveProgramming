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
const double EPS = 1e-6;
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    double arr[n];
    int ans[n];
    vi positives, negatives;
    ll sum = 0; 
    double dummy;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            if (modf(arr[i], &dummy) == 0.0) {
                ans[i] = (int)arr[i];
            } else {
                ans[i] = (int)(ceil(arr[i]));
                negatives.PB(i);
            }
        } else if (arr[i] > 0) {
            if (modf(arr[i], &dummy) == 0.0) {
                ans[i] = (int)arr[i];
            } else {
                ans[i] = (int)(floor(arr[i]));
                positives.PB(i);
            }
        } else {
            ans[i] = (int)arr[i];
        }
        sum += ans[i];
    }
	while (sum != 0) {
        if (sum > 0) {
            int index = negatives.back();
            negatives.pop_back();
            ans[index]--;
            sum--;
        } else {
            int index = positives.back();
            positives.pop_back();
            ans[index]++;
            sum++;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}