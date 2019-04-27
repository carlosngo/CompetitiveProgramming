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

bool isAdjacent(int i, int j) {
    int x = i ^ j;
    return (x & (-x)) == x;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    while (SCD(n) == 1) {
        int corners = 1 << n;
        int res = 0;
        vi pot(corners);
        
        FOR (i, 0, corners, 1) {
            int potency;
            SCD(potency);
            FOR (j, 0, corners, 1) {
                if (isAdjacent(i, j) && i != j) {
                    pot[j] += potency;
                }
            }
        }
        FOR (i, 0, corners, 1) { 
            FOR (j, 0, corners, 1) {
                if (isAdjacent(i, j) && i != j) 
                    res = max(res, pot[i] + pot[j]);
            }
        }
        printf("%d\n", res);
        fprintf(pFile, "%d\n", res);
    }
	fclose(pFile);
	return 0;
}