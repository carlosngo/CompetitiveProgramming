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
const int UNVISITED = -1;

int main() {
	// ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int t;
    cin >> t;
    getchar();
    getchar();
    int ctr = 0;
    while (t--) {
        if (ctr) cout << '\n';
        ctr++;
        string word;
        vector<string> dict;
        map<string, int> indices;
        while (getline(cin, word), word != "*") {
            indices[word] = dict.size();
            dict.PB(word);
        }
        int n = dict.size();
        vvi adjList(n, vi());
        for (int i = 0; i < dict.size(); i++) {
            for (int j = i + 1; j < dict.size(); j++) {
                string a = dict[i];
                string b = dict[j];
                bool connected = a.length() == b.length();
                int diff = 0;
                for (int k = 0; k < a.length() && connected; k++) {
                    if (a[k] != b[k]) diff++;
                    if (diff > 1) connected = false;
                } 
                if (connected) {
                    adjList[i].PB(j);
                    adjList[j].PB(i);
                }
            }
        }
        while (getline(cin, word), word != "") {
            stringstream ss(word);
            string srcStr, destStr;
            ss >> srcStr >> destStr;
            int src = indices[srcStr];
            int dest = indices[destStr];
            int ans = 0;
            queue<int> q;
            q.push(src);
            vi dist(n, UNVISITED);
            dist[src] = 0;
            bool found = false;
            while (!q.empty() && !found) {
                int cur = q.front();
                q.pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int next = adjList[cur][i];
                    if (dist[next] == UNVISITED) {
                        dist[next] = dist[cur] + 1;
                        if (next == dest) {
                            found = true;
                            break;
                        }
                        q.push(next);
                    }
                }
            }
            cout << srcStr << ' ' << destStr << ' ' << dist[dest] << '\n';
        }
    }
	return 0;
}