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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
	FILE *pFile = fopen("out.txt","w");
    char dummy;
    int cases; SCD(cases);
    while (cases--) {
        int i;
        SCD(i);
        int coef[i + 1];
        for (int a = 0; a < i + 1; a++) {
            SCD(coef[a]);
            // printf("Read %d.\n", coef[a]);
        }
        int num;
        int d, k, pos = 1, ans;
        SCD(d); SCD(k);
        int n = 1;
        while (pos <= k) {
            pos += n * d;
            n++;
        }
        ll sum = 0;
        for (int a = 0; a < i + 1; a++) {
            // printf("%d ", coef[a]);
            sum += coef[a] * pow(n - 1, a);
        }
        fprintf(stdout, "%lld\n", sum);
        fprintf(pFile, "%lld\n", sum);
    }
	fclose(pFile);
	return 0;
}