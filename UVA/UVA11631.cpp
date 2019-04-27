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
    int x, y, z;
    while (scanf("%d %d", &m, &n), m != 0 || n != 0) {
        vector<vii> graph;
        graph.assign(m, vii());
        int curCost = 0;
        while (n-- > 0) {
            scanf("%d %d %d", &x, &y, &z);
            graph[x].PB(ii(y, z));
            graph[y].PB(ii(x, z));
            curCost += z;
        }
        priority_queue<ii> edges;
        bitset<200000> bs;
        edges.push(ii(0, 0));
        int leastCost = 0;
        while (!edges.empty()) {
            ii top = edges.top(); edges.pop();
            if (!bs.test(-(top.second))) {
                leastCost += -(top.first);
                bs.set(-top.second);
                FOR(i, 0, graph[-top.second].size(), 1) {
                    ii v = graph[-top.second][i];
                    if (!bs.test(v.first)) {
                        edges.push(ii(-v.second, -v.first));
                    }
                }
            }
    
        }
        fprintf(pFile, "%d\n", curCost - leastCost);
        printf("%d\n", curCost - leastCost);
    }
	fclose(pFile);
	return 0;
}