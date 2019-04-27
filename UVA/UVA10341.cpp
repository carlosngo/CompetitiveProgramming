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

double equation(int p, int q, int r, int s, int t, int u, double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
	int p, q, r, s, t, u;

	while (fscanf(stdin, "%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
		double lo = 0.0;
		double hi = 1.0;
		if ((equation(p,q,r,s,t,u,hi) >= 0 && equation(p,q,r,s,t,u,lo) <= 0) || (equation(p,q,r,s,t,u,hi) <= 0 && equation(p,q,r,s,t,u,lo) >= 0)) {
			double x;
			double f;
			do {
				x = (lo + hi) / 2;
				f = equation(p,q,r,s,t,u,x);
				if (f < 0) {
					hi = x;
				} else {
					lo = x;
				}
			} while (!(f < 1e-10 && f >= 0));
			fprintf(stdout, "%.4lf\n", x);
			// fprintf(pFile, "%.4lf\n", x);
		} else {
			fprintf(stdout, "No solution\n");
			// fprintf(pFile, "No solution\n");
		}
		
	}
	fclose(pFile);
	return 0;
}