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
    int ctr = 0;
    while (SCD(n) == 1) {
        vector<pair<string, int> > grp(n);
        map<string, int> map;
        if (ctr > 0) {
            printf("\n");
            fprintf(pFile, "\n");
        }
        FOR (i, 0, n, 1) {
            string name;
            cin >> name;
            grp[i].first = name;
            grp[i].second = 0;
            map[name] = i;
        }
        FOR (i, 0, n, 1) {
            string name;
            int amt, num;
            cin >> name;
            cin >> amt;
            cin >> num;
            int giverIndex = map[name];
            int divideBy = num;
            grp[giverIndex].second -= amt;
            grp[giverIndex].second += divideBy == 0 ? amt : amt % divideBy;
            while (num-- > 0) {
                cin >> name;

                int receiverIndex = map[name];
                grp[receiverIndex].second += amt / divideBy;
            }

        }

        FOR(i, 0, n, 1) {
            printf("%s %d\n", grp[i].first.c_str(), grp[i].second);
            fprintf(pFile, "%s %d\n", grp[i].first.c_str(), grp[i].second);
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}