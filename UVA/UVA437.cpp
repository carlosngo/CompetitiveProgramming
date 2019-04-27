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

bool compare(const iii a, const iii b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second.first > b.second.first) {
            return true;
        } else if (a.second.first == b.second.first) {
            return a.second.second > b.second.second;
        } else {
            return true;
        }
    } else {
        return false;
    }
}
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    int ctr =1;
    while (SCD(n), n != 0) {
        
        vector<iii> arr;
        FOR (i, 0, n, 1) { 
            int x, y, z;
            SCD(x); SCD(y); SCD(z);
            arr.PB(iii(x, ii(y, z)));
            arr.PB(iii(x, ii(z, y)));
            arr.PB(iii(y, ii(x, z)));
            arr.PB(iii(y, ii(z, x)));
            arr.PB(iii(z, ii(y, x)));
            arr.PB(iii(z, ii(x, y)));
        }
        sort(arr.begin(), arr.end(), compare);
        int L[arr.size()];
        // printf("Blocks:\n");
        // FOR (i, 0, arr.size(), 1) {
        //     printf("%d %d %d\n", arr[i].first, arr[i].second.first, arr[i].second.second);
        // }
        FOR (i, 0, arr.size(), 1) {
            int maxH = 0;
            FOR (j, 0, i, 1) {
                if (arr[j].first > arr[i].first) {
                    if (arr[j].second.first > arr[i].second.first) {
                        maxH = max(maxH, L[j]);
                    }
                }
            }
            L[i] = maxH + arr[i].second.second;
            // printf("At i = %d, L[i] = %d\n", i, L[i]);
        }
        int ans = 0;
        FOR (i, 0, arr.size(), 1) ans = max(ans, L[i]);
        fprintf(stdout, "Case %d: maximum height = %d\n", ctr, ans);
        fprintf(pFile, "Case %d: maximum height = %d\n", ctr, ans);
        ctr++;
    }
	fclose(pFile);
	return 0;
}