#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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
	FILE *pFile = fopen("out.txt","w");
    int deg;
    while (SCD(deg), deg != 0) {
        int x;
        SCD(x);
        vi polyCoef(deg + 1);
        int polyAns = 0;
        vi firstCoef(deg);
        int firstAns = 0;
        vi secondCoef(deg - 1);
        int secondAns = 0;
        FOR (i, 0, deg + 1, 1) {
            
            SCD(polyCoef[i]);
            
            if (i != firstCoef.size())
                firstCoef[i] = polyCoef[i] * (deg - i);
            
            if (i != secondCoef.size())
                secondCoef[i] = firstCoef[i] * (deg - i - 1);
            printf("%d", polyAns);
            polyAns += polyCoef[i] * pow(x, deg - i);
        }
        FOR (i, 0, firstCoef.size(), 1) {
            // printf("%d ", firstCoef[i]);
            firstAns += firstCoef[i] * pow(x, (int)firstCoef.size() - i - 1);
        }
        printf("\n");
        FOR (i, 0, secondCoef.size(), 1) {
            // printf("%d ", secondCoef[i]);
            secondAns += secondCoef[i] * pow(x, (int) secondCoef.size() - i - 1);
        }
        printf("\n");
        printf("%d %d %d\n", polyAns, firstAns, secondAns);
    }
	fclose(pFile);
	return 0;
}