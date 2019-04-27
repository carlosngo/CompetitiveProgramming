#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

int start;
vii pts;
vvi memo;

int dist(int a, int b) {
    return abs(pts[a].first - pts[b].first) 
         + abs(pts[a].second - pts[b].second);
}

int tsp (int pos, int mask) {
    if (mask == (1 << ((int)pts.size())) - 1) {
        return dist(start, pos);
    } else if (memo[pos][mask] != -1) {
        return memo[pos][mask];
    } else {
        int ans = 1 << 30;
        for (int i = 0; i < (int)pts.size(); i++) {
            if((mask & (1 << i)) == 0) {
                ans = min(ans, dist(pos, i) + tsp (i, mask | (1 << i)));
                memo[pos][mask] = ans;
            }
        }
        // printf("solve(%d,%d) = %d;\n",pos,mask,ans);
        return ans;
    }
}

int main() {
	FILE *pFile = fopen("out.txt","w");
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        int x, y;
        pts.clear();
        scanf("%d %d", &x, &y);
        scanf("%d %d", &x, &y);
        
        pts.push_back(ii(x, y));
        start = 0;
        int beepers;
        scanf("%d", &beepers);
        memo.assign(beepers + 1, vi(1 << (beepers + 1), -1));
        while (beepers-- > 0) {
            scanf("%d %d", &x, &y);
            pts.push_back(ii(x, y));
        }
        printf("The shortest path has length %d\n", tsp(0, 1));
        fprintf(pFile,"The shortest path has length %d\n", tsp(0, 1));
    }
	fclose(pFile);
	return 0;
}