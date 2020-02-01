#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCC(t) fscanf(stdin, "%col",&t)

#define LIN(i,l,r) (l<=i&&i<r)
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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;


int main() {
    vector<vector<vector<char>>> blueprint(100, vector<vector<char>>(100, vector<char>(100)));
    vector<vector<vector<int>>> ans(100, vector<vector<int>>(100, vector<int>(100)));
    vector<vector<vector<char>>> dist(100, vector<vector<char>>(100, vector<char>(100)));
    vi r(100);
    vi c(100);
    vector<vector<iii> > stairs(56, vector<iii>());
    int f;
    SCD(f);
    for (int i = 0; i < f; i++) {
        int row, col;
        SCD(row);
        SCD(col);
        r[i] = row;
        c[i] = col;
        getchar();
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                char ch;
                SCC(ch);
                blueprint[i][j][k] = ch;
                ans[i][j][k] = UNVISITED;
                if (ch != '.' && ch != '#') {
                    if (isupper(ch)) {
                        stairs[ch - 'A'].PB(iii(i, ii(j, k)));
                    } else {
                        stairs[ch - 'a' + 26].PB(iii(i, ii(j, k)));
                    }
                }
            }
            getchar();
        }
    }
    vector<vector<iii> > corners;
    int components = 0;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < r[i]; j++) {
            for (int k = 0; k < c[i]; k++) {
                if (blueprint[i][j][k] != '#' && ans[i][j][k] == UNVISITED) {
                    queue<iii> q;
                    q.push(iii(i, ii(j, k)));
                    ans[i][j][k] = components;
                    corners.PB(vector<iii>());
                    while (!q.empty()) {
                        int curF = q.front().first;
                        int curR = q.front().second.first;
                        int curC = q.front().second.second;
                        q.pop();
                        bool hasAdjacentWall = false;
                        for (int i = 0; i < 4; i++) {
                            int nextF = curF;
                            int nextR = curR + fx[i][0];
                            int nextC = curC + fx[i][1];
                            if (LIN(nextR, 0, r[nextF]) && LIN(nextC, 0, c[nextF])) {

                                if (ans[nextF][nextR][nextC] == UNVISITED) {
                                    if (blueprint[nextF][nextR][nextC] != '#') {
                                        ans[nextF][nextR][nextC] = components;
                                        q.push(iii(nextF, ii(nextR, nextC)));
                                    } else hasAdjacentWall = true;
                                } 
                            }
                        }
                        if (hasAdjacentWall) {
                            corners[components].PB(iii(curF, ii(curR, curC)));
                        }
                        char ch = blueprint[curF][curR][curC];
                        if (ch != '#' && ch != '.') {
                            int stair = isupper(ch) ? ch - 'A' : ch - 'a' + 26;
                            for (int l = 0; l < stairs[stair].size(); l++) {
                                int nextF = stairs[stair][l].first;
                                int nextR = stairs[stair][l].second.first;
                                int nextC = stairs[stair][l].second.second;
                                if (ans[nextF][nextR][nextC] == UNVISITED) {
                                    ans[nextF][nextR][nextC] = components;
                                    q.push(iii(nextF, ii(nextR, nextC)));
                                }
                            }
                        }
                    }
                    components++;
                }
            }
        }
    }
    
    priority_queue<ii, vii, greater<ii> > pq;
    vi dijkstra(components, INF);
    unordered_set<int> src;
    unordered_set<int> dest;
    for (int i = 0; i < r[0]; i++) {
        for (int j = 0; j < c[0]; j++) {
            if (ans[0][i][j] != UNVISITED) {
                int u = ans[0][i][j];
                src.insert(u);
            }
        }
    }
    for (unordered_set<int>::iterator itr = src.begin(); itr != src.end(); itr++) {
        int u = *itr;
        pq.push(ii(0, u));
        dijkstra[u] = 0;
    }

    for (int i = 0; i < r[f - 1]; i++) {
        for (int j = 0; j < c[f - 1]; j++) {
            if (ans[f - 1][i][j] != UNVISITED) {
                int u = ans[f - 1][i][j];
                dest.insert(u);
            }
        }
    }
    
    vvi adjList = vvi(components, vi());
    vvi adjMatrix = vvi(components, vi(components, INF));
    for (int u = 0; u < components; u++) {
        queue<iii> q;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < r[i]; j++) {
                for (int k = 0; k < c[i]; k++) {
                    dist[i][j][k] = UNVISITED;
                }
            }
        }
        
        for (int i = 0; i < corners[u].size(); i++) {
            int floor = corners[u][i].first;
            int row = corners[u][i].second.first;
            int column = corners[u][i].second.second;
            dist[floor][row][column] = 0;
            q.push(iii(floor, ii(row, column)));
        }
        while (!q.empty()) {
            int curF = q.front().first;
            int curR = q.front().second.first;
            int curC = q.front().second.second;
            int curD = dist[curF][curR][curC];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextF = curF;
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                if (LIN(nextR, 0, r[nextF]) && LIN(nextC, 0, c[nextF])) {
                    if (dist[nextF][nextR][nextC] == UNVISITED) {

                        if (blueprint[nextF][nextR][nextC] == '#') {
                            dist[nextF][nextR][nextC] = curD + 1;
                            q.push(iii(nextF, ii(nextR, nextC)));
                        } else if (ans[nextF][nextR][nextC] != u) {
                            int v = ans[nextF][nextR][nextC];
                            if (adjMatrix[u][v] == INF) adjList[u].PB(v);
                            adjMatrix[u][v] = min(adjMatrix[u][v], curD);
                        }
                    }
                }
            }
        }
    }
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        // fprintf(stdout, "processing %d with shortest distance %d\n",u, d);
        pq.pop();
        if (d > dijkstra[u]) continue;
        if (dest.find(u) != dest.end()) {
            fprintf(stdout, "%d", d);
            return 0;
        }
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            int w = adjMatrix[u][v];
            if (dijkstra[v] > dijkstra[u] + w) {
                // fprintf(stdout, "found a shorter path for %d : %d\n", v, dijkstra[u] + w);
                dijkstra[v] = dijkstra[u] + w;
                pq.push(ii(dijkstra[v], v));
            }
        }
    }
    
    
    // for (int i = 0; i < components; i++) {
    //     fprintf(stdout, "%d: ", i);
    //     for (int j = 0; j < adjList[i].size(); j++) {
    //         fprintf(stdout, "%d - %d, ", adjList[i][j], adjMatrix[i][j]);
    //     }
    //     fprintf(stdout, "\n");
    // }

    // for (int i = 0; i < components; i++) {
    //     fprintf(stdout, "corners of component %d:\n", i);
    //     while (!vq[i].empty()) {
    //         fprintf(stdout, "%d %d %d\n", vq[i].front().first, vq[i].front().second.first, vq[i].front().second.second);
    //         vq[i].pop();
    //     }
    // }
    fprintf(stdout, "DAMN, THE ABSCONDER ABSCONDS AGAIN!");
	return 0;
}