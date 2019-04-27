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
    int b, n, r, d, c, v;
    while (scanf("%d %d", &b, &n), !(b == 0 && n == 0)) {
        vi banks(b + 1);
        vi debts(n + 1);
        FOR(i, 1, banks.size(), 1)
            SCD(banks[i]);
        while (n-- > 0) {
            SCD(d); SCD(c); SCD(v);
            banks[c] += v;
            banks[d] -= v;
        }
        bool ans = true;
        FOR(i, 1, banks.size(), 1)
            if (banks[i] < 0)
                ans = false;
        printf("%s\n", ans ? "S" : "N");
        fprintf(pFile, "%s\n", ans ? "S" : "N");
    }
	fclose(pFile);
	return 0;
}