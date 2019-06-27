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
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vi arr(n);
    int subs[6] = {4, 8, 15, 16, 23, 42};
    queue<int> queues[6];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < 6; j++) {
            if (arr[i] == subs[j]) queues[j].push(i);
        }
    }
    int correct = 0;
    int pos = 0;
    int cur = -1;
    bool valid = true;
    while (valid) {
        if (queues[0].empty()) break;
        cur = queues[0].front();
        queues[0].pop();
        for (int i = 1; i < 6 && valid; i++) {
            bool found = false;
            while (!queues[i].empty() && queues[i].front() < cur) {
                queues[i].pop();
            } 
            if (!queues[i].empty()) {
                cur = queues[i].front();
                queues[i].pop();
                found = true;
            }
            if (!found) {
                valid = false;
                break;
            }
        }
        if (valid) correct++;
    }
    cout << (n - correct * 6);
	
	return 0;
}