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
    int s, b;
    while (scanf("%d %d", &s, &b), s && b) {
        vii buddies(s + 2);
        FOR (i, 1, s + 1, 1) 
            buddies[i] = ii(i - 1, i + 1);
        while (b--) {
            int l, r;
            scanf("%d %d", &l, &r);
            int left = buddies[l].first;
            int right = buddies[r].second;
            buddies[left].second = right;
            buddies[right].first = left;
            if (left == 0) {
                printf("* ");
                fprintf(pFile, "* ");
            } else {
                printf("%d ", left);
                fprintf(pFile, "%d ", left);
            }
            if (right == s + 1) {
                printf("*\n");
                fprintf(pFile, "*\n");
            } else {
                printf("%d\n", right);
                fprintf(pFile, "%d\n", right);
            }
        }
        printf("-\n");
        fprintf(pFile,"-\n");
    }
	fclose(pFile);
	return 0;
}