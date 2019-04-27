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
typedef unsigned long long ull;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

ull pow3(int expo) {
    ull prod = 1;
    for (int i = 0; i < expo; i++) {
        prod *= 3;
    }
    return prod;
}

ull pow2(int expo) {
    ull prod = 1;
    for (int i = 0; i < expo; i++) {
        prod *= 2;
    }
    return prod;
}
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	ull n;
    while (fscanf(stdin, "%llu", &n), n != 0) {
        n--;
        printf("%llu\n", n);
        fprintf(stdout, "{");
        int ctr = 0;
        for (int i = 0; i < 64; i++) {
            ull bitTest = pow2(i);
            ull power = pow3(i);
            printf("3 ^ %d = %llu\n", i, power);
            if ((n & bitTest) != 0) {
                if (ctr) fprintf(stdout, ",");
                fprintf(stdout, " %llu", pow3(i));
                ctr++;
            }
        }
        fprintf(stdout, " }\n");
    }
	return 0;
}