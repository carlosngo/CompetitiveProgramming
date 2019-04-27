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
    int n;
    int ctr = 1;
    while (SCD(n) == 1) {
        string img[n];
        FOR (i, 0, n, 1) cin >> img[i];
        int ans = 0;
        FOR (i, 0, n, 1) {
            FOR (j, 0, n, 1) {
                if (img[i][j] == '1') {
                    // printf("Found 1 at row %d and col %d\n", i, j);
                    ans++;
                    // img[i][j] = '0';
                    queue<ii> bfs;
                    bfs.push(ii(i, j));
                    while (!bfs.empty()) {
                        ii top = bfs.front(); bfs.pop();
                        // printf("Front of queue is %d %d", top.first, top.second);
                        img[top.first][top.second] = '0';
                        FOR (k, 0, 8, 1) {
                            int r = top.first + fxx[k][0];
                            int c = top.second + fxx[k][1];
                            // printf("Checking row %d col %d\n", r, c);
                            if (r >= 0 && c >= 0 && r < n && c < n && img[r][c] == '1') {
                                bfs.push(ii(r, c));
                            }
                        }
                    }
                    
                }
            }
        }
        fprintf(stdout, "Image number %d contains %d war eagles.\n", ctr, ans);
        // fprintf(pFile, "Image number %d contains %d war eagles.\n", ctr, ans);
        ctr++;
    } 
	fclose(pFile);
	return 0;
}