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
	// freopen("out.txt", "wt", stdout);
	int r, c;
    int ctr = 1;
    while (fscanf(stdin, "%d%d", &r, &c), r != 0 || c != 0) {
        char grid[r][c * 4];
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch;
                SCC(ch);
                if (ch == '0') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == '1') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == '2') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == '3') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == '4') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == '5') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'b';
                }  else if (ch == '6') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == '7') {
                    grid[i][j * 4 + 0] = 'w';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == '8') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == '9') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == 'a') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == 'b') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'w';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == 'c') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == 'd') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'w';
                    grid[i][j * 4 + 3] = 'b';
                } else if (ch == 'e') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'w';
                } else if (ch == 'f') {
                    grid[i][j * 4 + 0] = 'b';
                    grid[i][j * 4 + 1] = 'b';
                    grid[i][j * 4 + 2] = 'b';
                    grid[i][j * 4 + 3] = 'b';
                } 
            }
            getchar();
        }
        c *= 4;
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         fprintf(stdout, "%c", grid[i][j]);
        //     }
        //     fprintf(stdout, "\n");
        // }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j += c - 1) {
                char ch = grid[i][j];
                if (ch == 'w') {
                    grid[i][j] = 'n';
                    queue<ii> q;
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                                if (grid[nextR][nextC] == 'w') {
                                    grid[nextR][nextC] = 'n';
                                    q.push(ii(nextR, nextC));
                                }
                            }
                        }
                    }
                }
            } 
        }
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i += r - 1) {
                char ch = grid[i][j];
                if (ch == 'w') {
                    grid[i][j] = 'n';
                    queue<ii> q;
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                                if (grid[nextR][nextC] == 'w') {
                                    grid[nextR][nextC] = 'n';
                                    q.push(ii(nextR, nextC));
                                }
                            }
                        }
                    }
                }
            }  
        }
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         fprintf(stdout, "%c", grid[i][j]);
        //     }
        //     fprintf(stdout, "\n");
        // }
        vector<char> ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'b') {
                    int whites = 0;
                    grid[i][j] = 'n';
                    queue<ii> q;
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                                if (grid[nextR][nextC] == 'w') {
                                    whites++;
                                    grid[nextR][nextC] = 'n';
                                    queue<ii> q2;
                                    q2.push(ii(nextR, nextC));
                                    while (!q2.empty()) {
                                        int curCurR = q2.front().first;
                                        int curCurC = q2.front().second;
                                        q2.pop();
                                        for (int l = 0; l < 4; l++) {
                                            int nextNextR = curCurR + fx[l][0];
                                            int nextNextC = curCurC + fx[l][1];
                                            if (nextNextR >= 0 && nextNextR < r && nextNextC >= 0 && nextNextC < c) {
                                                if (grid[nextNextR][nextNextC] == 'w') {
                                                    grid[nextNextR][nextNextC] = 'n';   
                                                    q2.push(ii(nextNextR, nextNextC));
                                                }
                                            }
                                        }
                                    }
                                } else if (grid[nextR][nextC] == 'b') {
                                    grid[nextR][nextC] = 'n';
                                    q.push(ii(nextR, nextC));
                                }
                            }
                        }
                    }
                    if (whites == 0) {
                        ans.PB('W');
                    } else if (whites == 1) {
                        ans.PB('A');
                    } else if (whites == 2) {
                        ans.PB('K');
                    } else if (whites == 3) {
                        ans.PB('J');
                    } else if (whites == 4) {
                        ans.PB('S');
                    } else if (whites == 5) {
                        ans.PB('D');
                    }
                }       
            }
        }
        sort(ans.begin(), ans.end());
        fprintf(stdout, "Case %d: ", ctr);
        for (int i = 0; i < ans.size(); i++) {
            fprintf(stdout, "%c", ans[i]);
        }
        fprintf(stdout, "\n");
        ctr++;
    }
	return 0;
}