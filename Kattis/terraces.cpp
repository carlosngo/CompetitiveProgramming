#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define PB push_back

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    int x, y;
    SCD(y); SCD(x);
    int grid[x][y];
    unordered_set<int> list;
    vii heights[1000];
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            SCD(grid[i][j]);
            list.insert(grid[i][j]);
            heights[grid[i][j]].PB(ii(i, j));
        }
    }
    bool visited[x][y];
    memset(visited, false, sizeof(visited));
    int ans = 0;
    for (unordered_set<int>::iterator itr = list.begin(); itr != list.end(); itr++) {
        int h = *itr;
        for (int i = 0; i < heights[h].size(); i++) {
            int srcR = heights[h][i].first;
            int srcC = heights[h][i].second;
            if (!visited[srcR][srcC]) {
                queue<ii> q;
                q.push(ii(srcR, srcC));
                visited[srcR][srcC] = true;
                bool hasLower = false;
                int nodes = 0;
                while (!q.empty()) {
                    int curR = q.front().first;
                    int curC = q.front().second;
                    int curH = grid[curR][curC];
                    q.pop();
                    nodes++;
                    for (int j = 0; j < 4; j++) {
                        int nextR = curR + fx[j][0];
                        int nextC = curC + fx[j][1];
                        if (nextR >= 0 && nextR < x && nextC >= 0 && nextC < y) {
                            int nextH = grid[nextR][nextC];
                            if (curH == nextH && !visited[nextR][nextC]) {
                                q.push(ii(nextR, nextC));
                                visited[nextR][nextC] = true;
                            }
                            else if (curH > nextH) hasLower = true;
                        }
                    }
                }   
                if (!hasLower) ans += nodes;
            }
        }
    }
    fprintf(stdout, "%d", ans);
	return 0;
}