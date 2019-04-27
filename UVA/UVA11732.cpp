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
typedef pair<ii, int> iii;
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
    int n, m, a, b, c;
    while (fscanf(stdin, "%d %d", &n, &m), !(n == 0 && m == 0)) {
        int row[n];
        FOR (i, 0, n, 1) row[i] = i;
        map<int, vii> cons;
        FOR (i, 0, m, 1) {
            SCD(a); SCD(b); SCD(c);
            cons[a].PB(ii(b, c));
        }
        int ans = 0;
        do {
            bool valid = true;
            for (int i = 0; i < n && valid; i++) {
                int person = row[i];
                if (!cons[person].empty()) {
                    for (int k = 0; k < cons[person].size() && valid; k++) {
                        for (int j = 0; j < n && valid; j++) {
                            if (row[j] == cons[person][k].first) {
                                if (cons[person][k].second > 0 && abs(i - j) > cons[person][k].second) {
                                    valid = false;
                                } else if (cons[person][k].second < 0 && abs(i - j) < -cons[person][k].second) {
                                    valid = false;
                                }
                            } 
                        }
                    }
                }
            }
            if (valid) ans++;
        } while (next_permutation(row, row + n));
        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}