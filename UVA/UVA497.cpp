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

int fast_atoi( const char * str )
{
    int val = 0;
    while( *str ) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    char line[100];
    getchar();
    getchar();
    int ctr = 0;
    while (t--) {
        if (ctr) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        vi arr;
        // gets(line);
        while (gets(line)) {
            if (line[0] == '\0') break;
            int num;
            sscanf(line, "%d", &num);
            arr.PB(num);
        }
        
        int n = arr.size();
        int L[n], L_id[n], prev[n];
        int lis = 0, lis_end = 0;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(L, L + lis, arr[i]) - L;
            L[pos] = arr[i];
            L_id[pos] = i; 
            prev[i] = pos ? L_id[pos - 1] : -1;
            if (pos + 1 > lis) {
                lis = pos + 1;
                lis_end = i;
            }
        }
        stack<int> s;
        s.push(arr[lis_end]);
        while (prev[lis_end] >= 0) {
            s.push(arr[prev[lis_end]]);
            lis_end = prev[lis_end];
        }
        fprintf(stdout, "Max hits: %d\n", lis);
        // fprintf(pFile, "Max hits: %d\n", lis);
        while (!s.empty()) {
            fprintf(stdout, "%d\n", s.top());
            // fprintf(pFile, "%d\n", s.top());
            s.pop();
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}