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
const int seg[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
};

int n;
vector<string> seq;
bool ans;
bitset<7> burnt;

bool isPossible(int pos, int led) {
    for (int i = 0; i < seq[pos].length(); i++) {
        if (seq[pos][i] == 'Y' && seg[led][i] == 0) return false;
        else if (seq[pos][i] == 'Y' && seg[led][i] == 1) burnt.reset(i);
        else if (seq[pos][i] == 'N' && seg[led][i] == 1 && !burnt.test(i)) return false;
        else if (seq[pos - 1][i] == 'Y' && seq[pos][i] == 'N' && burnt.set(i);
    }
    return true;
}

void solve(int pos, int num) {
    if (pos == n) {
        ans = true;
    } else { 
    // } else if (num >= 0) {
        for (int i = num; i >= 0 && !ans; i--) {
            if (isPossible(pos, i)) {
                // printf("%d is possible\n", i);
                solve(pos + 1, i - 1);
            } 
        }
    }
    
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    while (SCD(n), n != 0) {
        ans = false;
        seq = vector<string>();
        burnt = bitset<7>();
        FOR (i, 0, n, 1) {
            string line;
            cin >> line;
            seq.PB(line);
        }
        for (int i = 9; i >= n; i--) {
            bool pos = true;
            for (int j = 0; j < seq[0].length(); j++) {
                if (seq[0][j] == 'Y' && seg[i][j] == 0) pos = false;
                else if (seq[0][j] != 'Y' || seg[i][j] != 1) burnt.set(j);
            }
            if (pos) {
                solve(1, i - 1);
            }
        }
        fprintf(stdout, "%s", ans ? "MATCH\n" : "MISMATCH\n");
        fprintf(pFile, "%s", ans ? "MATCH\n" : "MISMATCH\n");
    }
	fclose(pFile);
	return 0;
}