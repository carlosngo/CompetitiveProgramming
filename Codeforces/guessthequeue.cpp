#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCLD(t) fscanf(stdin, "%ld",&t)
#define SCLLD(t) fscanf(stdin, "%lld",&t)
#define SCC(t) fscanf(stdin, "%c",&t)
#define SCS(t) fscanf(stdin, "%s",t)
#define SCF(t) fscanf(stdin, "%f",&t)
#define SCLF(t) fscanf(stdin, "%lf",&t)
// CHECKING BOUNDS
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// LOOPS
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define WHILEZ int T; SCD(T); while(T--) 
// MISC
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define PB push_back
#define INF 1000000000

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
    int t;
    SCD(t);
    for (int ctr = 1; ctr <= t; ctr++) {
        fprintf(stdout, "Case %d:\n", ctr);
        map<int, int> idMap;
        map<int, int> posMap;
        int front = -1;
        int back = 0;
        int n;
        SCD(n);
        for (int i = 0; i < n; i++) {
            int cmd, y; 
            char x;
            SCD(cmd);
            getchar();
            SCC(x);
            if (cmd == 1) {
                SCD(y);
                if (x == 'B') {
                    idMap[y] = back;
                    posMap[back] = y;
                    back++;
                } else {
                    idMap[y] = front;
                    posMap[front] = y;
                    front--;
                }
            } else if (cmd == 2) {
                if (x == 'B') {
                    back--;
                } else {
                    front++;
                }
            } else {
                SCD(y);
                if (x == 'D') {
                    fprintf(stdout, "%d\n", posMap[y + front]);
                } else {
                    fprintf(stdout, "%d\n", idMap[y] - front);
                }
            }
        }
        // printf("Front = %d, Back = %d\n", front, back);
        // printf("ID Map Contents:\n");
        // for (map<int, int>::iterator itr = idMap.begin(); itr != idMap.end(); itr++) {
        //     printf("%d->%d\n", itr->first, itr->second);
        // }
        // printf("Pos Map Contents:\n");
        // for (map<int, int>::iterator itr = posMap.begin(); itr != posMap.end(); itr++) {
        //     printf("%d->%d\n", itr->first, itr->second);
        // }
    }
	return 0;
}