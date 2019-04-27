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
    int n, p;
    int ctr = 1;
    string dummy;
    while (scanf("%d %d", &n, &p), !(n == 0 && p == 0)) {
        getline(cin, dummy);
        if (ctr > 1) {
            printf("\n");
            fprintf(pFile, "\n");
        }
        map<string, int> m;
        while (n-- > 0) {
            string req;
            getline(cin, req);
            m[req] = 1;
        }
        string minName;
        int maxCompliance = -1;
        double minPrice = __DBL_MAX__;
        FOR (i, 0, p, 1) {
            string name;
            getline(cin, name);
            double compliance, price;
            int num;
            SCLF(price); SCD(num);
            getline(cin, dummy);
            FOR (j, 0, num, 1) {
                string query;
                getline(cin, query);
            }
            if (num > maxCompliance) {
                minName = name;
                maxCompliance = num;
                minPrice = price;
            } else if (num == maxCompliance) {
                if (price < minPrice) {
                    minName = name;
                    maxCompliance = num;
                    minPrice = price;
                }

            }
        }
        printf("RFP #%d\n%s\n", ctr, minName.c_str());
        fprintf(pFile, "RFP #%d\n%s\n", ctr, minName.c_str());
        ctr++;
    }
	fclose(pFile);
	return 0;
}