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
	int n, m, nums[1000];
	int ctr = 1;	
	while (SCD(n), n != 0) {
		vi sums;
		FOR (i, 0, n, 1) {
			SCD(nums[i]);
			FOR (j, 0, i, 1) 
				sums.PB(nums[i] + nums[j]);
		}
		SCD(m);
		fprintf(stdout, "Case %d:\n", ctr);
		fprintf(pFile, "Case %d:\n", ctr);
		while (m--) {
			int minDiff = INT_MAX;
			int ans = -1;
			int q; SCD(q);	
			FOR (i, 0, sums.size(), 1) {
				if (minDiff > abs(sums[i] - q)) {
					minDiff = abs(sums[i] - q);
					ans = i;
				}
			}
			fprintf(stdout, "Closest sum to %d is %d.\n", q, sums[ans]);
			fprintf(pFile, "Closest sum to %d is %d.\n", q, sums[ans]);
		}
		ctr++;
	}
	fclose(pFile);
	return 0;
}