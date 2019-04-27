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
#define INF 1000000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;


int main() {
	FILE *pFile = fopen("out.txt","w");
    int l, u, r;
    int a = 1;
    while (scanf("%d %d %d", &l, &u, &r), !(l == 0 && u == 0 && r == 0)) {
        vi codes(r);
        int ans = 0;
        FOR(i, 0, r, 1)
            scanf("%d", &codes[i]);
        queue<int> q;
        bitset<1000000> bs;
        q.push(l);
        bs.set(l);
        vi dist(1000000, INF);
        dist[l] = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == u) {
                    // dist[nextState] = dist[cur] + 1;
                    break;
            }
            FOR (i, 0, codes.size(), 1) {
                int nextState = (cur + codes[i]) % 10000;
                // printf("Checking %d\n", nextState);
                
                    
                if (!bs.test(nextState)) {
                    q.push(nextState);
                    bs.set(nextState);
                    dist[nextState] = dist[cur] + 1;
                }
            }
        }
        printf("Case %d: ", a);
        fprintf(pFile, "Case %d: ", a);
        if (dist[u] == INF) {
            printf("Permanently Locked\n");
            fprintf(pFile,"Permanently Locked\n");
        } else {
            printf("%d\n", dist[u]);
            fprintf(pFile, "%d\n", dist[u]);
        }
        a++;
    }
	fclose(pFile);
	return 0;
}