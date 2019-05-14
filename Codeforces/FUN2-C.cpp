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

int p, r, k, c, n;
vector<vii> regions;
int maxNum;
bool found = false;
char grid[7][7];


void solve(char num, int pos) {
    // fprintf(stdout, "At Num = %c, pos = %d\n", num, pos);
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         fprintf(stdout, "%c ", grid[i][j]);
    //     }
    //     fprintf(stdout, "\n");
    // }
    
    if (found) return;
    if (num - '0' > maxNum) {
        fprintf(stdout, "%d\n", k);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                fprintf(stdout, "%c ", grid[i][j]);
            }
            fprintf(stdout, "\n");
        }
        found = true;
        return;
    }
    if (pos == regions.size()) {
        solve(num + 1, 0);
        return;
    }
    if (num - '0' > regions[pos].size()) {
        solve(num, pos + 1);
        return;
    }
    // fprintf(stdout, "%d > %d\n", num - '0', maxNum);
    
    
        // fprintf(stdout, " Hi");
    bool isTaken = false;
    for (int i = 0; i < regions[pos].size() && !isTaken; i++) {
        int curR = regions[pos][i].first;
        int curC = regions[pos][i].second;
        char ch = grid[curR][curC];
        if (ch == num) isTaken = true;
    }
    if (isTaken) solve(num, pos + 1);
    for (int i = 0; i < regions[pos].size(); i++) {
        int curR = regions[pos][i].first;
        int curC = regions[pos][i].second;
        char ch = grid[curR][curC];
        bool isValid = ch == '-';
        for (int j = 0; j < 8 && isValid; j++) {
            int nextR = curR + fxx[j][0];
            int nextC = curC + fxx[j][1];
            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                if (grid[nextR][nextC] == num) {
                    isValid = false;
                }
            }
        }
        // fprintf(stdout, "(%d, %d) is a(n) %s position for %c\n", curR, curC, isValid ? "valid" : "invalid", num);
        if (isValid) {
            grid[curR][curC] = num;
            solve(num, pos + 1);
            // fprintf(stdout, "Back to num = %c pos = %d\n", num, pos);
            grid[curR][curC] = ch;
        }
    }
        // fprintf(stdout, "Did not find a solution for num = %c pos = %d, backtracking...\n",num, pos);
    
}

int main() {
    cin >> p;
    while (p--) {
        found = false;
        cin >> k >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        cin >> n;
        maxNum = INT_MIN;
        regions.assign(n, vii());
        for (int i = 0; i < n; i++) {
            int size;
            fscanf(stdin, "%d", &size);
            maxNum = max(maxNum, size);
            // fprintf(stdout, "size = %d\n", size);
            for (int j = 0; j < size; j++) {
                int row, col;
                fscanf(stdin, " (%d,%d)", &row, &col);
                row--; col--;
                // fprintf(stdout, "Read %d, %d\n", row, col);
                regions[i].PB(ii(row, col));
            }
        }
        solve('1', 0);
        // fprintf(stdout, "Done");
    }
	
	return 0;
}