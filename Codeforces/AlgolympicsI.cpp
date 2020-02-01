#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCC(t) fscanf(stdin, "%c",&t)

#define LIN(i,l,r) (l<=i&&i<r)

typedef pair<int,int> ii;

const int kxx[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

const int UNVISITED = -1;

int main() {
	int t;
    SCD(t);
    while (t--) {
        int r, c;
        SCD(r); SCD(c);
        getchar();
        char grid[r][c];
        int srcR, srcC, destR, destC;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
                if (grid[i][j] == 'K') {
                    srcR = i; srcC = j;
                }
                if (grid[i][j] == 'F') {
                    destR = i; destC = j;
                }
            }
            getchar();
        }
        vector<vector<bool> > visited(r, vector<bool>(c, false));
        char ans[r][c];
        ii parent[r][c];
        queue<ii> q;
        q.push(ii(srcR, srcC));
        visited[srcR][srcC] = true;
        parent[srcR][srcC] = ii(-1, -1);
        while (!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nextR = curR + kxx[i][0];
                int nextC = curC + kxx[i][1];
                if (LIN(nextR, 0, r) && LIN(nextC, 0, c) && grid[nextR][nextC] != 'X' && !visited[nextR][nextC]) {
                    q.push(ii(nextR, nextC));
                    ans[nextR][nextC] = (char)('A' + i);
                    parent[nextR][nextC] = ii(curR, curC);
                    visited[nextR][nextC] = true;
                }
            }
        }
        
        
        if (visited[destR][destC]) {
            stack<char> s;
            int curR = destR, curC = destC;
            while (parent[curR][curC].first != -1 && parent[curR][curC].second != -1) {
                int tempR = parent[curR][curC].first, tempC = parent[curR][curC].second;
                s.push(ans[curR][curC]);
                curR = tempR; curC = tempC;
            }
            fprintf(stdout, "Whinny\n");
            while (!s.empty()){
                fprintf(stdout, "%c", s.top());
                s.pop();
            }
            fprintf(stdout, "\n");
        } else fprintf(stdout, "Neigh\n");
        

    }
	return 0;
}