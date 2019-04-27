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

int dir[8];
int h, w;
int grid[21][61];
set<int> ans;
int minimumDist;

void dijkstra(int src) {
    vi dist(h * w, INF);
    vi prev(h * w);
    prev[src] = -1;
    priority_queue<ii, vii, greater<ii> >pq;
    dist[src] = grid[src / w][src % w];
    
    pq.push(ii(grid[src / w][src % w], src));
    while (!pq.empty()) {
        int curV = pq.top().second;
        pq.pop();
        int curR = curV / w;
        int curC = curV % w;
        for (int i = 0; i < 8; i++) {
            int nextR = curR + fxx[i][0];
            int nextC = curC + fxx[i][1];
            // int nxtV = curV + dir[i];
            // if ((i != 2 && i != 7) && abs(nxtV % w - curV % w) == 0) continue;
            // if (nxtV < 0 || nxtV >= h * w || (abs(nxtV % w - curV % w) > 1))
            //     continue;
            if (nextR < 0 || nextR >= h || nextC < 0 || nextC >= w) continue;
            int nxtV = nextR * w + nextC;
            int nxtW = grid[nxtV / w][nxtV % w];
            if (dist[nxtV] > dist[curV] + nxtW) {
                dist[nxtV] = dist[curV] + nxtW;
                prev[nxtV] = curV;
                pq.push(ii(dist[nxtV], nxtV));
            }
        }
        
    }
   
    int minDist = INT_MAX;
    int minInd;
    for (int i = (h - 1) * w; i < h * w; i++) {
        if (dist[i] < minDist) {
            minDist = dist[i];
            minInd = i;
        }
    } 
    
    if (minDist < minimumDist) {
        minimumDist = minDist;
        ans = set<int>();
        while (prev[minInd] != -1) {
            ans.insert(minInd);
            minInd = prev[minInd];
        }
        ans.insert(minInd);
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
    while (fscanf(stdin, "%d %d", &h, &w), h != 0 || w != 0) {
        dir[0] = -1; // LEFT
        dir[1] = 1; // RIGHT
        dir[2] = w; // DOWN
        dir[3] = w - 1; // LOWER LEFT
        dir[4] = w + 1; // LOWER RIGHT
        dir[5] = -w + 1; // UPPER RIGHT
        dir[6] = -w - 1; // UPPER LEFT
        dir[7] = -w; // UP
        getchar();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char ch;
                SCC(ch);
                grid[i][j] = ch - '0';
            }
            getchar();
        }
        ans = set<int>();
        minimumDist = INT_MAX;
        for (int i = 0; i < w; i++) {
            dijkstra(i);
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (ans.find(i * w + j) != ans.end()) {
                    printf(" ");
                } else {
                    printf("%d", grid[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
	return 0;
}