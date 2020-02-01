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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

int minNode = -1;
vector<string> names;
vvi adjMatrix;
vvi parent;

void printPath(int i, int j) {
    if (i != j) printPath(i, parent[i][j]);
    // cout << "i = " << i << " j = " << j << '\n';
    // if (parent[i][j] != minNode) printPath(parent[i][j], parent[i][j]);
    cout << names[j] << ' ';
}

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int n;
    cin >> n;
    
    names = vector<string>(n);
    adjMatrix = vvi(n, vi(n, INF));
    parent = vvi(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            parent[i][j] = i;
        }
    }
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        m[name] = i;
        names[i] = name;
        // cout << "m[" << name << "] = " << m[name] << '\n';
    }

    for (int i = 0; i < n; i++) {
        string name;
        int k;
        cin >> name >> k;
        string line;
        getline(cin, line);
        for (int j = 0; j < k; j++) {
            getline(cin, line);
            stringstream ss(line);
            ss >> name;
            while (getline(ss, name, ',')) {
                name.erase(0, 1);
                int v = m[name];
                adjMatrix[i][v] = 1;
            }
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
                    parent[i][j] = parent[k][j];
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                }
            }
        }
    }

    int minCycle = INF;
    minNode = -1;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[i][i] < INF) {
            if (minCycle > adjMatrix[i][i]) {
                minCycle = adjMatrix[i][i];
                minNode = i;
            }
        }
    }
    if (minCycle == INF) {
        cout << "SHIP IT";
    } else {
        printPath(minNode, parent[minNode][minNode]);
        // cout << "minCycle starts at " << names[minNode] << '\n';
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << parent[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
	return 0;
}