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
    int n, m;
    SCD(n);
    SCD(m);
    char grid[n][m];
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            SCC(grid[i][j]);
        }
        getchar();
    }
    int arr[5];
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cars = 0;
            bool valid = true;
            if (i + 1 < n && j + 1 < m) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        
                        // printf("Checking (%d, %d)\n", i + k, j + l);
                        if (grid[i + k][j + l] == 'X') cars++;
                        else if (grid[i + k][j + l] == '#') valid = false;
                    
                    }
                }
            } else {
                valid = false;
            }
            if (valid) arr[cars]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        fprintf(stdout, "%d\n", arr[i]);
    }
	return 0;
}