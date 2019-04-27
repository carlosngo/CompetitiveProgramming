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
    int k;
    while (SCD(k) == 1) {
        vector<string> ans;
        // fprintf(stdout, "Read input.");
        for (int i = k + 1; i <= 2 * k; i++) {
            if ((k * i) % (i - k) == 0) {
                int x = i;
                int y = k * x / (x - k);
                char output[100];
                sprintf(output, "1/%d = 1/%d + 1/%d", k, y, x);
                // fprintf(stdout, "1/%d = 1/%d + 1/%d", k, y, x);
                // fprintf(stdout, "%s", output);
                ans.PB(string(output));
            }
        }
        fprintf(stdout, "%d\n", ans.size());
        fprintf(pFile, "%d\n", ans.size());
        FOR (i, 0, ans.size(), 1) {
            fprintf(stdout, "%s\n", ans[i].c_str());
            fprintf(pFile, "%s\n", ans[i].c_str());
        }
    }
	fclose(pFile);
	return 0;
}