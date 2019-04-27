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
    int ans[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 20, 22, 23, 23, 25, 26, 26, 28, 29, 29, 29, 33, 33, 33, 36, 36, 36, 39, 39, 40, 40, 40, 44, 44, 45, 46, 47, 48, 49, 50, 50, 50, 55, 55, 55, 56, 56, 58, 59, 59, 59, 59, 66, 66, 66, 66, 66, 69, 69, 70, 70, 70, 70, 77, 77, 77, 77, 78, 79, 80, 80, 80, 80, 80, 88, 88, 88, 88, 89, 89, 89, 89, 89, 89, 99, 99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 110, 110, 110, 110, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 122, 123, 123, 125, 126, 126, 128, 129, 129, 129, 133, 133, 133, 136, 136, 136, 139, 139, 140, 140, 140, 144, 144, 145, 146, 147, 148, 149, 150, 150, 150, 155, 155, 155, 156, 156, 158, 159, 159, 159, 159, 166, 166, 166, 166, 166, 169, 169, 170, 170, 170, 170, 177, 177, 177, 177, 178, 179, 180, 180, 180, 180, 180, 188, 188, 188, 188, 189, 189, 189, 189, 189, 189, 199, 199, 199, 199, 199, 200};
    int t;
    SCD(t);
    while (t--) {
        int n;
        SCD(n);
        fprintf(stdout, "%d\n", ans[n]);
    }
    
	return 0;
}