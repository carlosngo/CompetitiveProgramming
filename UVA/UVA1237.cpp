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
    int t, m, d, l, h, q;
    string name;
    fscanf(stdin, "%d", &t);
    int ctr = 0;
    while (t--) {
        if (ctr > 0) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        fscanf(stdin, "%d", &m);
        vector<pair<string, ii> > makers(m);
        FOR (i, 0, makers.size(), 1) {
            cin >> name >> l >> h;
            makers[i] = pair<string, ii>(name, ii(l, h));
            
        }
        SCD(q);
        while (q--) {
            int price, count = 0;
            string ans;
            SCD(price);
            FOR (i, 0, makers.size(), 1) {
                if (price >= makers[i].second.first && price <= makers[i].second.second) {
                    count++;
                    ans = makers[i].first;
                    if (count > 1) break;
                }
            }
            if (count == 1) {
                fprintf(stdout, "%s\n", ans.c_str());
                // fprintf(pFile, "%s\n", ans.c_str());
            } else {
                fprintf(stdout, "UNDETERMINED\n");
                // fprintf(pFile, "UNDETERMINED\n");
            }
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}