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

queue<int> stations[100];
int t, n, s, q;


void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    SCD(t);
    while (t--) {
        SCD(n); SCD(s); SCD(q);
        stack<int> carrier;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int num; SCD(num);
            clear(stations[i]);
            // printf("Cleared\n");
            while (num--) {
                int a; SCD(a);
                a--;
                stations[i].push(a);
                total++;
            }
        }
        int cur = 0;
        int time = 0;
        while (total > 0) {
            // printf("At Station %d. Time elapsed %d\n", cur, time);
            
            // unloading
            // while (!carrier.empty())
            while (!carrier.empty()) {
                
                if (carrier.top() == cur) {
                    // printf("Unloading cargo %d\n", carrier.top());
                    carrier.pop();
                    total--;
                }
                else {
                    if (stations[cur].size() < q) {
                        // printf("Enqueueing cargo %d\n", carrier.top());
                        stations[cur].push(carrier.top()); carrier.pop();
                    } else {
                        break;
                    }
                }
                time++;
            }
            // loading
            while (carrier.size() < s && !stations[cur].empty()) {
                // printf("Loading cargo %d\n", stations[cur].front());
                carrier.push(stations[cur].front()); stations[cur].pop();
                time++;
            }
            cur = (cur + 1) % n;
            time += 2;
        }
        fprintf(stdout, "%d\n", time - 2);
        fprintf(pFile, "%d\n", time - 2);
    }
	fclose(pFile);
	return 0;
}