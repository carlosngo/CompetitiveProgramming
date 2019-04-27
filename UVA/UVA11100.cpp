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
    int ctr = 0;
    while (SCD(n), n != 0) {
        if (ctr > 0) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        map<int, int> sizes;
        int ans = 0;
        FOR(i, 0, n, 1) {
            int num;
            SCD(num);
            sizes[num]++;
            ans = max(ans, sizes[num]);
        }
        
        // priority_queue<ii, vii, greater<ii> > pq;
        vvi bags = vvi(ans, vi());
        int curPos = 0;
        for (map<int, int>::iterator itr = sizes.begin(); itr != sizes.end(); itr++) {
            int numOfSameBags = itr->second;
            // if (numOfSameBags)
            for (int i = 0; i < numOfSameBags; i++) {
                bags[curPos].PB(itr->first);
                curPos = (curPos + 1) % ans;
            }
        }
        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
        for (int i = 0; i < bags.size(); i++) {
            for (int j = 0; j < bags[i].size(); j++) {
                if (j > 0) {
                    fprintf(stdout, " ");    
                    // fprintf(pFile, " ");   
                }
                fprintf(stdout, "%d", bags[i][j]);
                // fprintf(pFile, "%d", bags[i][j]);
            }
            fprintf(stdout, "\n");    
            // fprintf(pFile, "\n");      
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}
