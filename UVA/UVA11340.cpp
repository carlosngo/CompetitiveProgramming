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
    SCD(n);
    char dummy;
    string dummy2;
    while (n-- > 0) {
        int k;
        int total = 0;
        map<char, int> prices;
        SCD(k);
        SCC(dummy);
        while (k-- > 0) {
            char ch;
            int cents;
            scanf(" %c %d", &ch, &cents);
            // printf("Debugging: %c %d\n", ch, cents);
            prices[ch] = cents;
            // getline(cin, dummy2);
        }
        // cout << "DONE READING PRICES\n";
        int m;
        SCD(m);
        string line;
        getline(cin, line);
        while (m-- > 0) {
            getline(cin, line);
            FOR (i, 0, line.length(), 1) {
                char ch = line[i];
                if (prices.find(ch) != prices.end())
                    total += prices[ch];
            }
        }
        double ans = total / 100.0;
        printf("%.2lf$\n", ans);
        fprintf(pFile, "%.2lf$\n", ans);
    }
	fclose(pFile);
	return 0;
}