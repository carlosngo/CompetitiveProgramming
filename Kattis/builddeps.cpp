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

bitset<100001> bs; 
vi ans;
vvi adjList;

void toposort(int v) {
    for (int i = 0; i < adjList[v].size(); i++) {
        int next = adjList[v][i];
        if (!bs.test(next)) {
            bs.set(next);
            toposort(next);
        }
    }
    ans.PB(v);
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n;
    cin >> n;
    
    int index = 1;
    map<string, int> indices;
    adjList = vvi(n + 1, vi());
    vector<string> files(n + 1);
    string line;
    getline(cin, line);
    for (int ctr = 0; ctr < n; ctr++) {
        getline(cin, line);
        stringstream ss(line);
        string from, to;
        ss >> to;
        to = to.substr(0, to.length() - 1);
        if (indices[to] == 0) {
            indices[to] = index;
            files[index] = to;
            // fprintf(stdout, "Index of %s is %d\n", to.c_str(), index);
            index++;
        }
        while (ss >> from) {
            if (indices[from] == 0) {
                indices[from] = index;
                files[index] = from;
                // fprintf(stdout, "Index of %s is %d\n", from.c_str(), index);
                index++;
            }
            adjList[indices[from]].PB(indices[to]);
        }
    }
    string s;
    cin >> s;
    int start = indices[s];
    toposort(start);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << files[ans[i]] << '\n';
    }
	return 0;
}