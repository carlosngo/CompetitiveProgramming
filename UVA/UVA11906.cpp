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

int main() {
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    for (int i = 1; i <= t; i++) {
        int r, c, m, n, w;
        SCD(r);
        SCD(c);
        SCD(m);
        SCD(n);
        char grid[r][c];
        bool visited[r][c];
        FOR(j, 0, r, 1) {
            FOR(k, 0, c, 1) { 
                grid[j][k] = 'L';
                visited[j][k] = false;
            }
        }
        

        int rOff [] = {-m, -m, m, m, -n, n, -n, n};
        int cOff [] = {n, -n, n, -n, m, m, -m, -m};
        
       
        SCD(w);
        while (w-- > 0) {
            int wRow, wCol;
            SCD(wRow);
            SCD(wCol);
            grid[wRow][wCol] = 'W';
        }
        // FOR(j, 0, r, 1) {
        //     FOR(k, 0, c, 1) { 
        //         // grid[j][k] = 'L';
        //         // printf("%c ", grid[j][k]);
        //         // visited[j][k] = false;
        //     }
        //     // printf("\n");
        // }
        queue<ii> q;
        q.push(ii(0,0));
        visited[0][0] = true;
        int odd = 0;
        int even = 0;
        while (!q.empty()) {
            ii coord = q.front(); q.pop();
            // FOR(j, 0, offsets, 1)
            //     printf("Row Offset: %d, Col Offset: %d\n", rOff[j], cOff[j]);

            // printf("Exploring coordinate (%d, %d)\n", coord.first, coord.second);
            int count = 0;
            set<ii> distinct;
            FOR(j, 0, 8, 1) {
                
                int newRow = coord.first + rOff[j];
                int newCol = coord.second + cOff[j];
                distinct.insert(ii(newRow, newCol));
            }
                // printf("Checking coordinate (%d + %d, %d + %d)\n",  coord.first, rOff[j], coord.second, cOff[j]);
            for (set<ii>::iterator iter = distinct.begin(); iter != distinct.end(); iter++) { 
                int newRow = (*iter).first;
                int newCol = (*iter).second;
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c 
                    && grid[newRow][newCol] == 'L') {
                    count++;
                    if (!visited[newRow][newCol]) {
                        q.push(ii(newRow, newCol));
                        visited[newRow][newCol] = true;
                    }
                }
            
            }
            // printf("Found %d reachable squares in coordinate (%d, %d).\n", count, coord.first, coord.second);
            if (count % 2) odd++;
            else even++;
        }
   
       
        printf("Case %d: %d %d\n", i, even, odd);
        fprintf(pFile, "Case %d: %d %d\n", i, even, odd);
    }
	fclose(pFile);
	return 0;
}