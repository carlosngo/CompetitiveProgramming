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

int sum;
int memo[21][201];
vi weights;
int size;
bool ans;

int knapsack(int pos, int total) {
    if (pos == size) {
        if (total + total == sum) ans = true;
        return memo[pos][total] = total + total == sum;
    } else if (memo[pos][total] != -1) {
        return memo[pos][total];
    } else {
        memo[pos + 1][total] = knapsack(pos + 1, total);
        // if (total + weights[pos] <= 200)
            memo[pos + 1][total + weights[pos]] = knapsack(pos + 1, total + weights[pos]);
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    SCD(n);
    while (n--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        sum = 0;
        weights = vi();
        memset(memo, -1, sizeof memo);
        ans = false;
        while (ss >> num) {
            weights.PB(num);
            sum += num;
        }
        size = weights.size();
        knapsack(0, 0);
        fprintf(stdout, "%s\n", ans ? "YES" : "NO");
        // fprintf(pFile, "%s\n", ans ? "YES" : "NO");
    }
	fclose(pFile);
	return 0;
}