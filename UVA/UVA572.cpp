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
    int m, n;
    int rOff[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cOff[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (SCD(m), m != 0) {
        int ans = 0;
        SCD(n);
        scanf("\n");
        vector<string> grid(m);
        FOR(i, 0, m, 1) getline(cin, grid[i]);
        FOR(i, 0, m, 1) {
            FOR(j, 0, n, 1) {
                if (grid[i][j] == '@') {
                    ii start(i, j);
                    grid[i][j] = '*';
                    queue<ii> q;
                    q.push(start);
                    while (!q.empty()) {
                        ii start = q.front(); q.pop();
                        int r = start.first;
                        int c = start.second;
                        FOR(k, 0, 8, 1) {
                            int newR = r + rOff[k]; 
                            int newC = c + cOff[k];
                            if (newR >= 0 && newR < m && newC >= 0 && newC < n 
                                && grid[newR][newC] == '@') {
                                q.push(ii(newR, newC));
                                grid[newR][newC] = '*';
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}