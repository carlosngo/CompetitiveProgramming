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
	// freopen("out.txt", "wt", stdout);
	int p, n;
    int ctr = 1;
    while (SCD(p) == 1) {
        SCD(n);
        int arr[100001];
        int instru[100001];
        priority_queue<ii, vii, less<ii> > pq;
        for (int i = 0; i < n; i++) {
            int num;
            SCD(num);
            arr[i] = num;
            instru[i] = 1;
            pq.push(ii(num, i));
        }
        p -= n;
        while (p > 0) {
            ii maxi = pq.top(); pq.pop();
            // printf("top of queue = %d, %d\n", maxi.first, maxi.second);
            ii next = pq.top();
            // printf("arr[maxi.second] = %d, instru[maxi.second] = %d\n", arr[maxi.second], instru[maxi.second]);
            int quo = ceil(1.0 * arr[maxi.second] / instru[maxi.second]);
            while (quo >= next.first && p > 0) {
                instru[maxi.second]++;
                p--;
                quo = ceil(1.0 * arr[maxi.second] / instru[maxi.second]);
                // printf("quo = %d\n", quo);
            }
            // printf("pushing %d, %d\n", quo, maxi.second);
            pq.push(ii(quo, maxi.second));
            // p--;
        }
        fprintf(stdout, "%d\n", pq.top());
        // fprintf(stdout, "Case %d: %d\n", ctr, pq.top());
        ctr++;
    }
	return 0;
}