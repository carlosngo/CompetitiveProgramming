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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    SCD(n);
    map<int, ii> loc;
    vvi world(n, vi());
    FOR (i, 0, n, 1) {
        world[i].PB(i);
        loc[i] = ii(i, 0);
    }
    string input;
    while (getline(cin, input), input != "quit") {
        
        stringstream ss(input);
        string cmd, wer;
        int from, to;
        ss >> cmd >> from >> wer >> to;
        ii fromPos = loc[from];
        ii toPos = loc[to];
        if (!(from == to || fromPos.first == toPos.first)) {
            if (cmd == "move") {
                // pop blocks on top of a and put it back to initial pos
                for (int i = world[fromPos.first].size() - 1; i > fromPos.second; i--) {
                    int block = world[fromPos.first].back();
                    world[fromPos.first].pop_back();
                    world[block].push_back(block);
                    loc[block] = ii(block, 0);
                }
                if (wer == "onto") {  
                    // pop blocks on top of b 
                    for (int i = world[toPos.first].size() - 1; i > toPos.second; i--) {
                        int block = world[toPos.first].back();
                        world[toPos.first].pop_back();
                        world[block].push_back(block);
                        loc[block] = ii(block, 0);
                    }
                } 
                // pop a and push above b
                world[toPos.first].push_back(world[fromPos.first].back());
                world[fromPos.first].pop_back();
                loc[from] = ii(toPos.first, world[toPos.first].size() - 1);
            } else {
                if (wer == "onto") {
                    for (int i = world[toPos.first].size() - 1; i > toPos.second; i--) {
                        int block = world[toPos.first].back();
                        world[toPos.first].pop_back();
                        world[block].push_back(block);
                        loc[block] = ii(block, 0);
                    }
                } 
                stack<int> s;
                while (world[fromPos.first].back() != from) {
                    s.push(world[fromPos.first].back()); world[fromPos.first].pop_back();
                }
                s.push(world[fromPos.first].back()); world[fromPos.first].pop_back();
                while(!s.empty()) {
                    int block = s.top();
                    printf("%d ", block);
                    world[toPos.first].push_back(block); s.pop();
                    loc[block] = ii(toPos.first, world[toPos.first].size() - 1);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < world[i].size(); j++) {
            printf(" %d", world[i][j]);
        }
        printf("\n");
    }

	fclose(pFile);
	return 0;
}