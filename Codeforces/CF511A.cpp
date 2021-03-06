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
    int num;
    cin >> num;
    int d1, d2, d3;
    d1 = d2 = d3 = num / 3;
    int rem = num % 3;
    while (d1 % 3 == 0 && d2 % 3 == 0 && d3 % 3 == 0) {
        if (d1 % 3 == 0) {
            if (rem > 0) {
                d1++;
                rem--;
            } else if (d2 % 3 == 0) {
                d1--;
                d2++;
            } else if (d3 % 3 == 0) {
                d1--;
                d3++;
            }
        }
        if (d2 % 3 == 0) {
            if (rem > 0) {
                d2++;
                rem--;
            } else if (d1 + 1 % 3 == 0) {
                d2--;
                d1++;
            } else if (d3 % 3 == 0) {
                d1--;
                d3++;
            }
        }
        if (d1 % 3 == 0) {
            if (rem > 0) {
                d1++;
                rem--;
            } else if (d2 % 3 == 0) {
                d1--;
                d2++;
            } else if (d3 % 3 == 0) {
                d1--;
                d3++;
            }
        }
    }

	fclose(pFile);
	return 0;
}