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
    int n;
    char dummy;
    while (SCD(n), n) {
        bool z = false;
        vi d, r;
        SCC(dummy);
        FOR (i, 0, n, 1) {
            char place;
            SCC(place);
            if (place == 'R')
                r.PB(i);
            else if (place == 'D')
                d.PB(i);
            else if (place == 'Z') {
                z = true;
            }
        }
        SCC(dummy);
        if (z) {
            printf("0\n");
            fprintf(pFile, "0\n");
        } else {
            sort(all(d)); sort(all(r));
            int ans = 1 << 30;
            int dIndex = 0, rIndex = 0;
            while (dIndex < d.size() && rIndex < r.size()) {
                int dVal = d[dIndex];
                int rVal = r[rIndex];
                ans = min(ans, abs(dVal - rVal));
                if (dVal > rVal)
                    rIndex++;
                else
                    dIndex++;
            }
            printf("%d\n", ans);
            fprintf(pFile, "%d\n", ans);
        }
    }

	fclose(pFile);
	return 0;
}