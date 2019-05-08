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
vi in;
vi vars;
vvi adjList;
bitset<26> visited;
bool found;
int n;

void solve() {
    if (topo.size() == n) {
        for (int i = 0; i < n; i++) {
            if (i) fprintf(stdout, " ");
            fprintf(stdout, "%c", topo[i] + 'A');
        }
        fprintf(stdout, "\n");
        found = true;
    } else {
        for (int i = 0; i < n; i++) {
            int var = vars[i];
            // fprintf(stdout, "Is %d visited? %s! %d has %d incoming connections.\n", var, visited.test(var) ? "Yes" : "No", var, in[var]);
            if (!visited.test(var) && in[var] == 0) {
                // fprintf(stdout, "Enqueueing %d\n", var);
                for (int j = 0; j < adjList[var].size(); j++) {
                    in[adjList[var][j]]--;
                }
                visited.set(var);
                topo.PB(var);
                solve();
                // fprintf(stdout, "Done with recursive calls.\n");
                topo.pop_back();
                for (int j = 0; j < adjList[var].size(); j++) {
                    in[adjList[var][j]]++;
                }
                visited.reset(var);
            } 
        }
    }
}

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int ctr = 0;
	WHILEZ {
        if (ctr) fprintf(stdout, "\n");
        if (!ctr) getchar();
        getchar();
        vars = vi();
        found = false;
        visited = bitset<26>();
        n = 0;
        char ch;
        while (SCC(ch), ch != '\n') {
            if (ch != ' ') {
                // fprintf(stdout, "Vertex %d\n", ch - 'A');
                vars.PB(ch - 'A');
                n++;
            }
        }
        in = vi(26, 0);
        adjList = vvi(26, vi());
        topo = vi();
        char ch2, dummy;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while(ss >> ch >> dummy >> ch2) {
            int from = ch - 'A';
            int to = ch2 - 'A';
            // fprintf(stdout, "%d -> %d\n", from, to);
            adjList[from].PB(to);
            in[to]++;
            // fprintf(stdout, "%d now has an indegree of %d\n", to, in[to]);
        }
        // getchar();
        // for (int i = 0; i < n; i++) {
        //     fprintf(stdout, "%d ", vars[i]);
        // }
        sort(vars.begin(), vars.end());
        solve();
        if (!found) fprintf(stdout, "NO\n");
        ctr++;
    }
	return 0;
}