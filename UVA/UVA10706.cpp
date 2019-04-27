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
    vector<ll> arr;
    vector<ll> len;
    arr.PB(0);
    arr.PB(0);
    len.PB(0);
    ll count = 0;
    
    for (int i = 1; count <= 2147483647; i++) {
        len.PB(len[i - 1] + ((int)log10((double) i) + 1));
        arr.PB(count + len[i]);
        count += len[i];
    }
    // for (int i = 0; i < arr.size(); i++) printf("%d ", arr[i]);
    int t;
    SCD(t);
    
    while (t--) {
        int i;
        SCD(i);
        i--;
        int pos = upper_bound(arr.begin(), arr.end(), i) - arr.begin() - 1;
        // printf("Pos = %d\n", pos);
        string ans = "";
        for (int l = 1; l <= pos; l++) {
            ans += to_string(l);
        }
        // fprintf(stdout, "%s\n", ans.c_str());
        // fprintf(stdout, "%d\n", ans.length());
        // printf("arr[pos] = %d\n", arr[pos]);
        // printf("i - arr[pos] = %d\n", i - arr[pos]);
        fprintf(stdout, "%c\n", ans[i - arr[pos]]);
        // fprintf(pFile, "%c\n", ans[i - arr[pos]]);
    }
    // printf("done!");
    fclose(pFile);
	return 0;
}