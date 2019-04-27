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
    int k, m, c, r;
    while (SCD(k), k) {
        set<int> selected;
        bool ans = true;;
        SCD(m);
        FOR(i, 0, k, 1) {
            int courseNum;
            SCD(courseNum);
            selected.insert(courseNum);
        }
        FOR(i, 0, m, 1) {
            SCD(c); SCD(r);
            while (c-- > 0) {
                int courseNum;
                SCD(courseNum);
                if (selected.find(courseNum) != selected.end()) {
                    r--;
                }
            }
            if (r > 0)
                ans = false;
        }
        printf("%s", ans ? "yes\n" : "no\n");
        fprintf(pFile, "%s", ans ? "yes\n" : "no\n");
    }
	fclose(pFile);
	return 0;
}