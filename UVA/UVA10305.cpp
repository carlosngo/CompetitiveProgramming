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
    while (scanf("%d %d", &m, &n), m != 0 || n != 0) {
        
        vi degrees;
        vvi graph;
        graph.assign(m, vi());
        degrees.assign(m, 0);
        vi topo;
        while (n-- > 0) {
            int src, dest;
            SCD(src); SCD(dest);
            src--; dest--;
            graph[src].PB(dest);
            degrees[dest]++;
        }
        // FOR(i, 0, degrees.size(), 1)
        //     printf("%d ", degrees[i]);
        priority_queue<int, vi, greater<int> > q;
        for (int i = 0; i < degrees.size(); i++) {
            if (degrees[i] == 0){
                q.push(i);
                // printf("Pushing %d into pq.\n",i);
            }
        }
        while (!q.empty()) {
            int task = q.top(); q.pop();
            // printf("Exploring task #%d\n", task);
            topo.PB(task + 1);
            FOR (i, 0, graph[task].size(), 1) {
                
                int newTask = graph[task][i];
                // printf("Checking task#%d\n", newTask);
                degrees[newTask]--;
                // printf("Task #%d has %d indegrees.\n", newTask, degrees[newTask]);
                if (degrees[newTask] == 0)
                    q.push(newTask);
            }
        }
        
        FOR (i, 0, topo.size(), 1) {
            printf("%d", topo[i]);
            fprintf(pFile, "%d", topo[i]);
            if (i < topo.size() - 1) {
                printf(" ");
                fprintf(pFile, " ");
            }
                
        }
        printf("\n");
        fprintf(pFile, "\n");
    }
	fclose(pFile);
	return 0;
}