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
    while (SCD(n) == 1) {
        int grid[n][n];
        FOR (i, 0, n, 1) 
            FOR (j, 0, n, 1)
                SCD(grid[i][j]);
        vector<iii> ans;
        // int ans = 0;
        for (int firstR = 0; firstR < n; firstR++) {
            for (int firstC = 0; firstC < n; firstC++) {
                if (grid[firstR][firstC] == 1) {
                    int secondR = firstC;
                    for (int secondC = 0; secondC < n; secondC++) {
                        if (grid[secondR][secondC] == 1 && secondC != firstR) {
                            int thirdR = secondC;
                            if (grid[thirdR][firstR] == 1) {
                                // ans++;
                                iii chain = iii(firstR + 1, ii(secondR + 1, thirdR + 1));
                                if (chain.first > chain.second.first && chain.second.first > chain.second.second
                                ||  chain.first < chain.second.first && chain.second.first < chain.second.second)
                                    ans.PB(chain);
                            }
                        }
                    }
                }
            }
        }
        // set<iii>::iterator itr;
        for (int i = 0; i < ans.size(); i++) {
            fprintf(stdout, "%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
            fprintf(pFile, "%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
        }
        fprintf(stdout, "total:%d\n\n", ans.size());
        fprintf(pFile, "total:%d\n\n", ans.size());
    }
	fclose(pFile);  
	return 0;
}