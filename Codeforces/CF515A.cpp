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
    cin >> n;
    while(n-- > 0) {
        int L, v, l, r;
        int ans = 0;
        cin >> L;
        cin >> v;
        cin >> l;
        cin >> r;
        int lanterns = L / v;
        // r = r / v * v;
        // l = (l / v + 1) * v;
        int bla = max(floor(r * 1.0 / v) - ceil(l * 1.0 / v ) + 1, 0.0);
        // (r - l) / v + 1;
        // FOR (i, 1, lanterns + 1, 1) {
        //     int j = i * v;
        //     if (j < l || j > r)
        //         ans++;
        // }
            cout << (lanterns - bla);
            cout << "\n";
        // printf("%d\n", ans);
    }
	fclose(pFile);
	return 0;
}