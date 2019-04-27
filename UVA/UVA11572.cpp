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
    int t, n;
    SCD(t);
    int ctr = 1;
    while (t--) {
        map<int, int> m;
        SCD(n);
        int ans = 0;
        int maxi = 0;
        // int prev = 0;
        while (n--) {
            int num; SCD(num);
            // printf("Checking key %d with val %s\n", num, m[num].c_str());
            ans++;
            if (!m[num]) {
                // ans++;
                
                m[num] = ans;
                // prev++;
            } else {
                // m = map<int, string>();
                // m.clear();
                ans -= m[num];
                m.clear();
                m[num] = ans;
            }
            if (ans > maxi) maxi = ans;
        }
        fprintf(stdout, "%d\n", maxi);
        fprintf(pFile, "%d\n", maxi);
        // fprintf(stdout, "Output #%d: %d\n", ctr, maxi);
        // fprintf(pFile, "Output #%d: %d\n", ctr, maxi);
        ctr++;
    }
	fclose(pFile);
	return 0;
}