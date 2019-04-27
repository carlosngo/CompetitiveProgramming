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
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int k, s[13];
    int ctr = 0;
    while (SCD(k), k != 0) {
        if (ctr > 0) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        FOR (i, 0, k, 1) SCD(s[i]);
        for (int a = 0; a < k; a++) {
            for (int b = a + 1; b < k; b++) {
                for (int c = b + 1; c < k; c++) {
                    for (int d = c + 1; d < k; d++) {
                        for (int e = d + 1; e < k; e++) {
                            for (int f = e + 1; f < k; f++) {
                                fprintf(stdout, "%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
                                // fprintf(pFile, "%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
                            }
                        }
                    }
                }
            }
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}