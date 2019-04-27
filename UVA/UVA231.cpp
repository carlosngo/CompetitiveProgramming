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
	FILE *pFile = fopen("out.txt","w");
    int first;
    int ctr = 1;
    while (SCD(first), first != -1) {
        if (ctr > 1) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        int num;
        vi arr;
        arr.PB(first);
        while (SCD(num), num != -1) {
            arr.PB(num);
        }
        int n = arr.size();
        int L[n];
        int lds = 0;
        for (int i = 0; i < n; i++) {
            int pos = upper_bound(L, L + lds, arr[i], greater<int>()) - L;
            L[pos] = arr[i];
            if (pos + 1 > lds) {
                lds = pos + 1;
            }
        }
        // FOR (i, 0, n, 1) {
        //     fprintf(stdout, "%d ", L[i]);
        // }
        fprintf(stdout, "Test #%d:\n  maximum possible interceptions: %d\n", ctr, lds);
        // fprintf(pFile, "Test #%d:\n  maximum possible interceptions: %d\n", ctr, lds);
        ctr++;
    }
	fclose(pFile);
	return 0;
}