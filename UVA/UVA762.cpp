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

vi parent;
vii cities;
        
void print_route(int cur) {
    if (parent[cur] == -1) return;
    print_route(parent[cur]);
    fprintf(stdout, "%c%c %c%c\n", cities[parent[cur]].first + 'A', cities[parent[cur]].second + 'A', 
                                   cities[cur].first + 'A', cities[cur].second + 'A');
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int m;
    int ctr = 0;
    while (SCD(m) == 1) {
        if (ctr) fprintf(stdout, "\n");
        getchar();
        int indices[26][26];
        vvi adjList(700, vi());
        cities = vii();
        memset(indices, -1, sizeof indices);
        int ind = 0;
        for (int i = 0; i < m; i++) {
            char srcF, srcS, destF, destS;
            SCC(srcF); SCC(srcS); 
            getchar();
            SCC(destF); SCC(destS);
            getchar();
            int srcR = srcF - 'A';
            int srcC = srcS - 'A';
            if (indices[srcR][srcC] == -1) {
                indices[srcR][srcC] = ind;
                cities.PB(ii(srcR, srcC));
                ind++;
            }
            int destR = destF - 'A';
            int destC = destS - 'A';
            if (indices[destR][destC] == -1) {
                indices[destR][destC] = ind;
                cities.PB(ii(destR, destC));
                ind++;
            }
            adjList[indices[srcR][srcC]].PB(indices[destR][destC]);
            adjList[indices[destR][destC]].PB(indices[srcR][srcC]);
        }
        char startF, startS, endF, endS;
        SCC(startF); SCC(startS); 
        getchar();
        SCC(endF); SCC(endS);
        int start = indices[startF - 'A'][startS - 'A'];
        int end = indices[endF - 'A'][endS - 'A'];
        if (start == -1 || end == -1) {
            fprintf(stdout, "No route\n");
            ctr++;
            continue;
        }
        // fprintf(stdout, "Start = %d, End = %d\n", start, end);
        parent.assign(cities.size(), -1);
        vi dist(cities.size(), -1);
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < adjList[cur].size(); i++) {
                int next = adjList[cur][i];
                if (dist[next] == UNVISITED) {
                    dist[next] = dist[cur] + 1;
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }
        // fprintf(stdout, "Done\n");
        if (parent[end] == UNVISITED) {
            fprintf(stdout, "No route\n");
        } else {
            print_route(end);
        }
        ctr++;
    }
	return 0;
}