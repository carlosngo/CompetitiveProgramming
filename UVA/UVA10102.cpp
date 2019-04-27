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
    int m;
    while (SCD(m) == 1) {
        vii threes;
        vii ones;
        string line;
        FOR (i, 0, m, 1) {
            cin >> line;
            FOR (j, 0, line.length(), 1) {
                if (line[j] == '3') {
                    threes.PB(ii(i, j));
                } else if (line[j] == '1') {
                    ones.PB(ii(i, j));
                }
            }
        }
        int ans = INT_MIN;
        FOR (i, 0, ones.size(), 1) {
            int minDist = INT_MAX;
            FOR (j, 0, threes.size(), 1) {
                int manh = abs(threes[j].first - ones[i].first) + abs(threes[j].second - ones[i].second);
                minDist = min(minDist, manh);
            }
            ans = max(ans, minDist);
        }
        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}