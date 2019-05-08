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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int ctr = 0;
	int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvi adjList(n, vi());
        vi in(n, 0);
        vi setting(n);
        for (int i = 0; i < n; i++) cin >> setting[i];
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            from--; to--;
            adjList[from].PB(to);
            in[to]++;
        }
        queue<int> labs[3];
        labs[1] = queue<int>();
        labs[2] = queue<int>();
        vi temp = in;

        int count = 0;
        int lab = 1;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                labs[setting[i]].push(i);
            }
        }
        while (!labs[1].empty() || !labs[2].empty()) {
            while (!labs[lab].empty()) {
                int cur = labs[lab].front();
                // cout << "Popping off " << cur << '\n';
                labs[lab].pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int next = adjList[cur][i];
                    in[next]--;
                    if (in[next] == 0) {
                        labs[setting[next]].push(next);
                    }
                }
            }
            if (lab == 1) lab = 2;
            else lab = 1;
            count++;
        }
        
        int ans = count - 1;
        // cout << ans << '\n';
        count = 0;
        labs[1] = queue<int>();
        labs[2] = queue<int>();
        lab = 2;
        in = temp;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                labs[setting[i]].push(i);
            }
        }
        while (!labs[1].empty() || !labs[2].empty()) {
            while (!labs[lab].empty()) {
                int cur = labs[lab].front();
                labs[lab].pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int next = adjList[cur][i];
                    in[next]--;
                    if (in[next] == 0) {
                        labs[setting[next]].push(next);
                    }
                }
            }
            if (lab == 1) lab = 2;
            else lab = 1;
            count++;
        }
        // cout << count << '\n';
        ans = min(ans, count - 1);
        if (ctr) cout << '\n';
        cout << ans;
        ctr++;
    }
	return 0;
}