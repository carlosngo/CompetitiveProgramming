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

bool compare (const pair<double, double> a, const pair<double, double> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return false;
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n, l, w;
    while (SCD(n) == 1) {
        SCD(l); SCD(w);
        vector<pair<double, double> > sprinks;
        FOR(i, 0, n, 1) {
            int pos, rad;
            SCD(pos); SCD(rad);
            if (rad * rad - (w / 2.0) * (w / 2.0) >= 0) {
                double dx = sqrt(rad * rad - (w / 2.0) * (w / 2.0));
                sprinks.PB(pair<double, double>(pos - dx, pos + dx));
            }
        }
        sort(sprinks.begin(), sprinks.end(), compare);
        // FOR (i, 0, n, 1) printf("%lf-%lf\n", sprinks[i].first, sprinks[i].second);
        double farthestPos = 0;
        int ans = 0;
        bool poss = true;
        if (sprinks.empty() || sprinks[0].first > 0) poss = false;
        else {
            int i, j;
            for (i = 0; i < sprinks.size() && poss; i = j) {
                if (sprinks[i].first > farthestPos) {
                    poss = false;
                } else {
                    int maxLeft = sprinks[i].first;
                    for (j = i + 1; j < sprinks.size() && sprinks[j].first <= farthestPos; j++) {
                        if (sprinks[j].second > sprinks[i].second) i = j;
                    }
                    farthestPos = sprinks[i].second;
                    ans++;
                }
                if (farthestPos >= l) {
                    break;
                }
            }
            if (farthestPos < l) poss = false;
        }
        if (poss) {
            fprintf(stdout, "%d\n", ans);
            // fprintf(pFile, "%d\n", ans);
        } else {
            fprintf(stdout, "-1\n");
            // fprintf(pFile, "-1\n");
        }
        
    }
	fclose(pFile);
	return 0;
}
