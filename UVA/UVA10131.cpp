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
	FILE *pFile = fopen("out.txt","w");
    FILE *in = fopen("input.txt", "r");
    vii arr;
    int w, iq;
    map<ii, int> m;
    int x = 1;
    while (SCD(w) == 1) {
        SCD(iq);
        arr.PB(ii(w, iq));
        m[ii(w, iq)] = x;
        x++;
    }
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // FOR (i, 0, n, 1) fprintf(pFile, "%d %d\n", arr[i].first, arr[i].second);
    int L[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        int maxIQ = 0;
        int ind = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j].first < arr[i].first) {
                if (arr[j].second > arr[i].second) {
                    if (L[j] > maxIQ) {
                        maxIQ = L[j];
                        ind = j;
                    }
                }
            }
        }
        prev[i] = ind >= 0 ? ind : -1;
        L[i] = maxIQ + 1;
    }
    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > lis) {
            lis = L[i];
            lis_end = i;
        }
    }
    stack<int> s;
    s.push(lis_end);
    while (prev[lis_end] >= 0) {
        s.push(prev[lis_end]);
        lis_end = prev[lis_end];
    }
    // s.push(prev[lis_end]);
    fprintf(stdout, "%d\n", lis);
    // fprintf(pFile, "%d\n", lis);
    while (!s.empty()) {
        // fprintf(stdout, "%d, %d\n", arr[s.top()].first, arr[s.top()].second);
        // fprintf(pFile, "%d, %d\n", arr[s.top()].first, arr[s.top()].second);
        fprintf(stdout, "%d\n", m[ii(arr[s.top()].first, arr[s.top()].second)]);
        // fprintf(pFile, "%d\n", m[ii(arr[s.top()].first, arr[s.top()].second)]);
        s.pop();
    }
    
	fclose(pFile);
	return 0;
}