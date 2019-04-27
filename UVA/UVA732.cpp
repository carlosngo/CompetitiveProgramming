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

string src, tgt;
vector<char> ans;
vector<char> sStack, tStack;

FILE *pFile = fopen("out.txt","w");

void solve(int srcPos, int tgtPos) {
    // printf("solve(%d, %d)\n", srcPos, tgtPos);
    if (srcPos == src.length()) {
        int ctr = 0;
        // printf("sStack Contents:\n");
        for (int i = sStack.size() - 1; i >= 0; i--) {
            // printf("%c ", sStack.back());
            ctr++;
            ans.PB('o');
            tStack.PB(sStack[i]);
        }
        bool same = true;
        for (int i = 0; i < tStack.size(); i++) {
            if (tStack[i] != tgt[i])
                same = false;
        }
        
        if (same) {
            FOR (i, 0, ans.size(), 1) {
                fprintf(stdout, "%c", ans[i]);
                // fprintf(pFile, "%c", ans[i]);
                if (i < ans.size() - 1) {
                    fprintf(stdout, " ");
                    // fprintf(pFile, " ");
                }
            }
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        while (ctr--) {
            ans.pop_back();
            tStack.pop_back();
        }
    } else {
        char srcCh = src[srcPos];
        // char srcCh = sStack.front();
        char tgtCh = tgt[tgtPos];
        ans.PB('i');
        sStack.PB(srcCh);
        solve(srcPos + 1, tgtPos);
        sStack.pop_back();
        ans.pop_back();
        if (!sStack.empty() && sStack.back() == tgtCh) {
            ans.PB('o');
            char temp = sStack.back();
            // printf("Pushing %c to tStack\n", temp);
            tStack.PB(temp); 
            sStack.pop_back();
            solve(srcPos, tgtPos + 1);
            sStack.PB(temp);
            // printf("Popping %c to tStack\n", tStack.back());
            tStack.pop_back();
            ans.pop_back();
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    while (cin >> src) {
        sStack.clear();
        tStack.clear();
        ans.clear();
        cin >> tgt;
        string _src = src, _tgt = tgt;
        sort(all(_src));
        sort(all(_tgt));
        fprintf(stdout, "[\n");
        // fprintf(pFile, "[\n");
        if (_src == _tgt) {
            solve(0, 0);
        }
        fprintf(stdout, "]\n");
        // fprintf(pFile, "]\n");
    }
	fclose(pFile);
	return 0;
}