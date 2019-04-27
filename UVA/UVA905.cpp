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

bool compare(const ii &a, const ii &b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
	FILE *pFile = fopen("out.txt","w");
    int x, y, w, h;
    bool first = true;
    while (scanf("%d", &x) == 1) {
        SCD(y); SCD(w); SCD(h);
        vii arr;
        FOR (i, 0, h, 1) {
            int n;
            SCD(n);
            FOR (j, 0, n, 1) {
                int num;
                SCD(num);
                arr.push_back(ii(num, h - i));
            }
        }
        vii coord;
        FOR (i, 0, arr.size(), 1) {
            int diag1;
            int diag2;
            int num = arr[i].second - y;
            int a, b;
            a = arr[i].first - x;
            b = arr[i].second - y;
            if (a == b) {
                diag1 = 0;
            } else if (a > b) {
                diag1 = -1;
            } else if (a < b) {
                diag1 = 1;
            }
            if (a == -b) {
                diag2 = 0;
            } else if (a > -b) {
                diag2 = 1;
            } else if (a < -b) {
                diag2 = -1;
            }
            if (diag1 >= 0 && diag2 > 0) {
                a = arr[i].first;
                b = arr[i].second + 1;
            } else if (diag1 > 0 && diag2 <= 0) {
                a = arr[i].first - 1;
                b =  arr[i].second;
            } else if (diag1 <= 0 && diag2 < 0) {
                a = arr[i].first;
                b = arr[i].second - 1 ;
            } else {
                a = arr[i].first + 1;
                b = arr[i].second;
            }
            // printf("Sign at %d %d will have movable at %d %d\n",arr[i].first,arr[i].second,a,b);
            if (a >= 1 && a <= w && b >= 1 && b <= h) {
                coord.PB(ii(a, b));
            }
        }
        sort(all(coord),compare);
        // printf("\n");
        // FOR(i, 0, coord.size(), 1) printf("WHAT %d %d\n", coord[i].first, coord[i].second);
        if(first) {
            first = false;
        } else {
            printf("\n");
        }
        printf("%d %d %d %d\n",x,y,w,h);
        int count;
        vi nums;
        int ind = 0;
        for(int i = h; i >= 1; i--) {
            while(ind < (int) coord.size() && coord[ind].second == i) {
                nums.push_back(coord[ind].first);
                count++;
                ind++;
            }
            printf("%d",count);
            for(int j = 0; j < (int)nums.size(); j++) {
                printf(" %d",nums[j]);
            }
            printf("\n");
            nums = vi();
            count = 0;
        }
    }
	fclose(pFile);
	return 0;
}