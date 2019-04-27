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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	int n, s, r;
    SCD(n);
    SCD(s);
    SCD(r);
    bitset<10> dmg;
    bitset<10> res;
    int arr[10];
    for (int i = 0; i < s; i++) {
        int num;
        SCD(num);
        dmg.set(num - 1);
        arr[i] = num - 1;
    }
    for (int i = 0; i < r; i++) {
        int num;
        SCD(num);
        res.set(num - 1);
    }
    int ans = 0;
    for (int i = 0; i < s; i++) {
        int num = arr[i];
        if (res.test(num)) res.reset(num);
        else if (num - 1 >= 0) {
            if (res.test(num - 1)) res.reset(num - 1);
            else if (num + 1 < n) {
                if (res.test(num + 1)) res.reset(num + 1);
                else ans++;
            } else ans++;
        } else if (num + 1 < n) {
            if (res.test(num + 1)) res.reset(num + 1);
            else ans++;
        } else ans++;
    }
    fprintf(stdout, "%d\n", ans);
	return 0;
}