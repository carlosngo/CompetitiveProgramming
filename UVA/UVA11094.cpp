#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define PB push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

vector<string> grid;
int rOff[] = {-1, 0, 0, 1, -1, 1, 1, -1};
int cOff[] = {0, -1, 1, 0, 1, -1, 1, -1};
int m, n, x, y;

int floodfill(int row, int col) {
    queue<ii> q;
            
            q.push(ii(row, col));
            char cur = grid[row][col];
            grid[row][col] = '!';
            int count = 1;
            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                FOR(i, 0, 4, 1) {
                    int newR = r + rOff[i];
                    int newC = c + cOff[i];
                    if (newC == -1)
                        newC = n - 1;
                    if (newC == n)
                        newC = 0;
                    if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == cur) {
                        count++;
                        q.push(ii(newR, newC));
                        grid[newR][newC] = '!';
                    }
                }
            }
    return count;
}

int main() {
	FILE *pFile = fopen("out.txt","w");
    while (scanf("%d %d\n", &m, &n) == 2) {
        int ans = 0;
        if (m != 0 && n != 0) {
            grid.assign(m, "");
            FOR(i, 0, m, 1) {
                getline(cin, grid[i]);
            }
            // printf("Done getting lines!");
            scanf("%d %d", &x, &y);
            char cur = grid[x][y];
            floodfill(x, y);
            
            FOR(i, 0, m, 1) {
                FOR (j, 0, n, 1) {
                    if (grid[i][j] == cur)
                        ans = max(ans, floodfill(i, j));       
                }
            }
        }
        
        printf("%d\n", ans);
        fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}