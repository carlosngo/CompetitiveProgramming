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
    int n, r;
    SCD(n); SCD(r);
    vii arr;
    queue<int> pts;
    FOR (i, 0, n, 1)
        pts.push(i + 1);
    
    FOR(i, 0, n, 1) {
        int pos;
        SCD(pos);
        arr.PB(ii(pos - r + 1, pos + r - 1));
    }
    int ans = 0;
    // sort(all(arr));
    while (!pts.empty()) {
        int pt = pts.front(); pts.pop();
        vii I;
        FOR (i, 0, arr.size(), 1) {
            if (arr[i].first <= pt)
                I.PB(arr[i]);
        }
        if (I.empty()) {
            printf("-1");
            return 0;
        }
        ii most(0, -1);

        FOR (i, 0, I.size(), 1) {
            
                int reach = arr[i].second;
                if (reach > most.first) {
                    most.first = reach;
                    most.second = i;
                }
            
        }
        int chosenIndex = most.second;
        int lb = arr[chosenIndex].first;
        int hb = arr[chosenIndex].second;
        printf("Loopinnggg");
        ans++;
        while (pts.front() <= hb) pts.pop();

    }
    printf("%d", ans);
	fclose(pFile);
	return 0;
}