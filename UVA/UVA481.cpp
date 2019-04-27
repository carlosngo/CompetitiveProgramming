#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(input, "%d",&t)
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
	FILE *pFile = fopen("out.txt","w");
    FILE *input = fopen("input.txt", "r");
    vi arr;
    int n;
    while (SCD(n) == 1) {
        arr.PB(n);
    }
    int lis = 0, lis_end = 0;
    int sz = arr.size();
    int L[sz], L_id[sz], P[sz];

    for (int i = 0; i < sz; i++) {
        int pos = lower_bound(L, L + lis, arr[i]) - L;
        L[pos] = arr[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;
        if (pos + 1 > lis) {
            lis = pos + 1;
            lis_end = i;
        }
    }

    fprintf(stdout, "%d\n-\n", lis);
    fprintf(pFile, "%d\n-\n", lis);
    stack<int> s;
    // int x = lis_end;
    do { 
        s.push(arr[lis_end]);  
        lis_end = P[lis_end];
    } while (P[lis_end] >= 0);

    fprintf(stdout, "%d\n", arr[lis_end]);
    fprintf(pFile, "%d\n", arr[lis_end]);
    while (!s.empty()) {
        fprintf(stdout, "%d\n", s.top());
        fprintf(pFile, "%d\n", s.top());
        s.pop();
    }
	fclose(pFile);
	return 0;
}