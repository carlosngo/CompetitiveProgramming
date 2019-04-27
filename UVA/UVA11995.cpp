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
    while (SCD(n) == 1) {
        int cmd, val;
        stack<int> s;
        queue<int> q;
        priority_queue<int, vi, less<int> > pq;
        bool isS = true, isQ = true, isPQ = true;
        FOR (i, 0, n, 1) {
            SCD(cmd); SCD(val);
            switch (cmd) {
                case 1:
                    if (isS)
                        s.push(val);
                    if (isQ)
                        q.push(val);
                    if (isPQ)
                        pq.push(val);
                    break;
                case 2:
                    if (isS) {
                        if (s.empty() || s.top() != val)
                            isS = false;
                        else
                            s.pop();
                    }
                    if (isQ) {
                        if (q.empty() || q.front() != val)
                            isQ = false;
                        else
                            q.pop();
                    }
                    if (isPQ) {
                        if (pq.empty() || pq.top() != val)
                            isPQ = false;
                        else
                            pq.pop();
                    }
                    break;
			}
        }
        if (!isS && !isQ && !isPQ) {
            printf("impossible\n");
            fprintf(pFile, "impossible\n");
        } else {
            if ((isS && isQ) || (isQ && isPQ) || (isS && isPQ)) {
                printf("not sure\n");
                fprintf(pFile, "not sure\n");
            } else if (isS) {
                printf("stack\n");
                fprintf(pFile, "stack\n");
            } else if (isQ) {
                printf("queue\n");
                fprintf(pFile, "queue\n");
            } else {
                printf("priority queue\n");
                fprintf(pFile, "priority queue\n");
            }
        }
    }
	fclose(pFile);
	return 0;
}