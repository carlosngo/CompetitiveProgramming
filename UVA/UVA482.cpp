#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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
    int cases;
    char dummy;
    scanf("%d", &cases);
    SCC(dummy);
    SCC(dummy);
    FOR (j, 0, cases, 1) {
        string s;
        if (j > 0) {
            getline(cin, s);
            printf("\n");
            fprintf(pFile, "\n");
        }
        // printf("Done reading blank line.\n");
        vi indices;
        string input;
        getline(cin, input);
        // printf("Read a line.\n");
        stringstream ss(input);
        int num;
        map<int, string> m;
        while (ss >> num) {
            indices.PB(num - 1);
            // printf("Read %d\n", num);
        }
        getline(cin, input);
        stringstream ss2(input);
        for (int i = 0; i < indices.size(); i++) {
            string val;
            ss2 >> val;
            // printf("Read %lf\n", val);
            m[indices[i]] = val;
            // printf("%d-%lf ", indices[i], m[indices[i]]);
        }
        for (int i = 0; i < indices.size(); i++) {
            
            printf("%s\n", m[i].c_str());
            fprintf(pFile, "%s\n", m[i].c_str());
        }
    }
	fclose(pFile);
	return 0;
}