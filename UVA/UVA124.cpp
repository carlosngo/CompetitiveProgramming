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

vi topo;
vi vars;
vi in;
vvi adjList;
bitset<26> visited;
int n;

void solve() {
    if (topo.size() == n) {
        for (int i = 0; i < n; i++) {
            fprintf(stdout, "%c", topo[i] + 'a');
        }
        fprintf(stdout, "\n");
    } else {
        for (int i = 0; i < n; i++) {
            int cur = vars[i];
            if (!visited.test(cur) && in[cur] == 0) {
                for (int j = 0; j < adjList[cur].size(); j++) {
                    in[adjList[cur][j]]--;
                }
                visited.set(cur);
                topo.PB(cur);
                solve();
                topo.pop_back();
                visited.reset(cur);
                for (int j = 0; j < adjList[cur].size(); j++) {
                    in[adjList[cur][j]]++;
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	string line;
    int ctr = 0;
    while (getline(cin, line)) {
        topo = vi();
        vars = vi();
        n = 0;
        stringstream ss(line);
        char ch;
        while (ss >> ch) {
            vars.PB(ch - 'a');
            n++;
        }
        adjList = vvi(26, vi());
        in = vi(26, 0);
        visited = bitset<26>();
        getline(cin, line);
        stringstream ss2(line);
        while (ss2 >> ch) {
            int from = ch - 'a';
            ss2 >> ch;
            int to = ch - 'a';
            adjList[from].PB(to);
            in[to]++;
        }
        sort(vars.begin(), vars.end());
        if (ctr) fprintf(stdout, "\n");
        ctr++;
        solve();
    }
	return 0;
}