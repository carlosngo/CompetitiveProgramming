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
    int t;
    string dummy;
    SCD(t);
    getline(cin, dummy);
    FOR(i, 1, t + 1, 1) {
        vi ans(100);
        int ptr = 0;
        string line;
        getline(cin, line);
        FOR(j, 0, line.length(), 1) {
            if (line[j] == '>') {
                ptr++;
                if (ptr == 100) ptr = 0;
            } else if (line[j] == '<') {
                ptr--;
                if (ptr == -1) ptr = 99;
            } else if (line[j] == '+') {
                ans[ptr]++;
                if (ans[ptr] == 256) ans[ptr] = 0;
            } else if (line[j] == '-') {
                ans[ptr]--;
                if (ans[ptr] == -1) ans[ptr] = 255;
            }
        }
        printf("Case %d: ", i);
        fprintf(pFile, "Case %d: ", i);
        FOR (j, 0, ans.size(), 1) {
            printf("%.2X", ans[j]);
            fprintf(pFile, "%.2X", ans[j]);
            if (j < ans.size() - 1) {
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