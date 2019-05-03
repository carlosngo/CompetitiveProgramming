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
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
    int n, m;
    int ctr = 1;
    while (fscanf(stdin, "%d %d", &n, &m), n != 0 || m != 0) {
        vector<double> timeToFall;
        timeToFall.assign(n, -1);
        vector<vii> adjList(n, vii());
        double ans = 0;
        int finalD1 = -1;
        int finalD2 = -1;
        for (int i = 0; i < m; i++) {
            int a, b, l;
            SCD(a); SCD(b); SCD(l);
            a--; b--;
            adjList[a].PB(ii(b, l));
            adjList[b].PB(ii(a, l));
        }

        priority_queue<pair<double, int>, vector<pair<double, int> >, less<pair<double, int> > > pq;
        timeToFall[0] = 0;
        pq.push(pair<double, int>(0, 0));
        while (!pq.empty()) {
            double curT = pq.top().first;
            int curD = pq.top().second;
            // fprintf(stdout, "curD = %d, curT = %llf\n", curD, curT);
            if (curT > ans) {
                finalD1 = curD;
                finalD2 = -1;
                ans = curT;
            }
            pq.pop();
            for (int i = 0; i < adjList[curD].size(); i++) {
                int nextD = adjList[curD][i].first;
                int nextW = adjList[curD][i].second;
                if (timeToFall[nextD] == -1) {
                    timeToFall[nextD] = curT + nextW;
                    pq.push(ii(curT + nextW, nextD));
                } else {
                    double diff = fabs(timeToFall[nextD] - curT);
                    double maxTime = max(timeToFall[nextD], curT);
                    double minTime = min(timeToFall[nextD], curT);
                    if (nextW - diff > 0) {
                        double finalTime = maxTime + (nextW - diff) / 2.0;
                        if (finalTime > ans) {
                            finalD1 = curD;
                            finalD2 = nextD;
                            ans = finalTime;
                        }
                    } else {
                        double newTime = minTime + nextW;
                        
                        if (finalD1 == nextD) {
                            ans = (newTime + timeToFall[nextD]) / 2.0;
                            finalD2 = nextD;
                        }
                        timeToFall[nextD] = newTime;
                    }
                }
            }
        }
        fprintf(stdout, "System #%d\n", ctr);
        if (finalD2 == -1) fprintf(stdout, "The last domino falls after %.1llf seconds, at key domino %d.\n\n", ans, finalD1 + 1);
        else fprintf(stdout, "The last domino falls after %.1llf seconds, between key dominoes %d and %d\n\n", ans, finalD1 + 1, finalD2 + 1);
        

        ctr++;
    }
	
	return 0;
}