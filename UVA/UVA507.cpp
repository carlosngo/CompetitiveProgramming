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
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int b, r, s;
    SCD(b);
    int ctr = 1;
    while (b--) {
        SCD(r);
        int routes[r + 1];
        int sum = 0;
        int ans = 0;
        ii range;
        int start = 1;
        FOR (i, 1, r, 1) {
            SCD(routes[i]);
            sum += routes[i];
            if (sum > ans) {
                range.first = start; 
                range.second = i + 1;
                ans = sum;
            } else if (sum == ans) {
                if (i + 1 - start > range.second - range.first) {
                    range.first = start;
                    range.second = i + 1;
                }
            }
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        if (ans > 0) {
            fprintf(stdout, "The nicest part of route %d is between stops %d and %d\n", ctr, range.first, range.second);
            fprintf(pFile, "The nicest part of route %d is between stops %d and %d\n", ctr, range.first, range.second);
        } else {
            fprintf(stdout, "Route %d has no nice parts\n", ctr);
            fprintf(pFile, "Route %d has no nice parts\n", ctr);
        }
        
        ctr++;
    }
	fclose(pFile);
	return 0;
}