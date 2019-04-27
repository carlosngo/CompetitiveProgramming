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

int root, rootChildren, ctr;
vi parent, low, num; 
vvi graph;

void dfs (int num) {

}

int main() {
	FILE *pFile = fopen("out.txt","w");
    int n;
    
    parent.assign(n, -1);
    low.assign(n, -1);
    graph.assign(n, vi());
    while (SCD(n), n != 0) {
        while (n-- > 0) {
            int node;
            SCD(node);
            int num;
            scanf("(%d)", &num);
            while (num-- > 0) {
                int nextNode;
                SCD(nextNode);
                graph[num].PB(nextNode);
            }
        }
    }
	fclose(pFile);
	return 0;
}