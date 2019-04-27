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

int isPrime(int n) {
    return n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31;
}

vi arr;
bitset<17> taken;
int n;

FILE *pFile;
void solve(int pos) {
    if (pos == n) {
        if (isPrime(arr[0] + arr[n - 1])) {
            for (int i = 0; i < arr.size(); i++) {
                if (i > 0) {
                    fprintf(stdout, " ");
                    // fprintf(pFile, " ");        
                }
                fprintf(stdout, "%d", arr[i]);
                // fprintf(pFile, "%d", arr[i]);
            }
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
    } else {
        for (int i = 2; i <= n; i++) {
            if (!taken.test(i)) {
                if (isPrime(arr[pos - 1] + i)) {
                    arr.PB(i);
                    taken.set(i);
                    solve(pos + 1);
                    arr.pop_back();
                    taken.reset(i);
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    pFile = fopen("out.txt","w");
    int ctr = 1;
    while (SCD(n) == 1) {
        taken = bitset<17>();
        arr = vi();
        taken.set(1);
        arr.PB(1);
        if (ctr > 1) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        fprintf(stdout, "Case %d:\n", ctr);
        // fprintf(pFile, "Case %d:\n", ctr);
        solve(1);
        ctr++;

    }
	fclose(pFile);
	return 0;
}