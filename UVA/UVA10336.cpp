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


bool compare(ii a, ii b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return false;
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	int t;
    SCD(t);
    for (int ctr = 1; ctr <= t; ctr++) {
        int r, c;
        SCD(r); SCD(c);
        char grid[r][c];
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        int ans[26];
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch = grid[i][j];
                if (ch != ' ') {
                    ans[ch - 'a']++;
                    queue<ii> q;
                    grid[i][j] = ' ';
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c && grid[nextR][nextC] == ch) {
                                grid[nextR][nextC] = ' ';
                                q.push(ii(nextR, nextC));
                            }
                        }
                    }
                }
            }
        }
        fprintf(stdout, "World #%d\n", ctr);
        vii arr;
        for (int i = 0; i < 26; i++) {
            if (ans[i] > 0) {
                arr.PB(ii(ans[i], i));
                // fprintf(stdout, "%c: %d\n", i + 'a', ans[i]);
            }
        }
        sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < arr.size(); i++) fprintf(stdout, "%c: %d\n", arr[i].second + 'a', arr[i].first);
    }
	return 0;
}