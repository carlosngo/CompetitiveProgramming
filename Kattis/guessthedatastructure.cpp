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
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int, vi> pq;
        bool isStack = true;
        bool isQueue = true;
        bool isPQ = true;
        for (int i = 0; i < n; i++) {
            int cmd, num;
            cin >> cmd >> num;
            if (!isStack && !isQueue && !isPQ) continue;
            if (cmd == 1) {
                s.push(num);
                q.push(num);
                pq.push(num);
            } else {
                if (s.empty()) {
                    isStack = false;
                    isQueue = false;
                    isPQ = false;
                    continue;
                }
                int top = s.top(); s.pop();
                if (top != num) isStack = false;
                top = q.front(); q.pop();
                if (top != num) isQueue = false;
                top = pq.top(); pq.pop();
                if (top != num) isPQ = false;
            }
        }
        if ((isStack && isQueue) || (isQueue && isPQ) || (isStack && isPQ)) {
            cout << "not sure" << '\n';
        } else if (isStack) {
            cout << "stack" << '\n';
        } else if (isQueue) {
            cout << "queue" << '\n';
        } else if (isPQ) {
            cout << "priority queue" << '\n';
        } else {
            cout << "impossible" << '\n';
        }
    }
	return 0;
}