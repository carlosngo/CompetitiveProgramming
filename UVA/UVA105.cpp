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
    // FILE *in = fopen("input.txt", "r");
    vector<iii> bldgs;
    int l, r, h;
    int end = 0;
    while (SCD(l) == 1) {
        SCD(h);
        SCD(r);
        end = max(end, r);
        bldgs.PB(iii(l, ii(h, r)));
    }
    vii ans;
    int hMap[end + 1];
    for (int i = 1; i <= end; i++) {
        int tallest = 0;
        for (int j = 0; j < bldgs.size(); j++) {
            if (i >= bldgs[j].first && i <= bldgs[j].second.second - 1) {
                tallest = max(tallest, bldgs[j].second.first);
            }
        }
        hMap[i] = tallest;
    }
    int cur;
    int ctr = 0;
    for (int i = 1; i <= end; i++) {
        if (i == 1) {
            cur = hMap[i];
            if (ctr) {
                fprintf(stdout, " ");
                // fprintf(pFile, " ");
            }
            fprintf(stdout, "%d %d", i, cur);
            // fprintf(pFile, "%d %d", i, cur);
            ctr++;
        } else {
            if (hMap[i] != cur) {
                cur = hMap[i];
                // if (cur == 0) {
                    if (ctr) {
                        fprintf(stdout, " ");
                        // fprintf(pFile, " ");
                    }
                    fprintf(stdout, "%d %d", i, cur);
                    // fprintf(pFile, "%d %d", i, cur);
                    ctr++;
                // }
            }
        }

    }
    fprintf(stdout, "\n");
    fprintf(pFile, "\n");
	fclose(pFile);
	return 0;
}