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
    double l, r;
    while (SCLF(l) == 1) {
        SCLF(r);
        // vector<pair<int, iii> > ans;
        int lo = (int)(l * 100 + 0.5);
        int hi = (int)(r * 100 + 0.5);
        int maxA = 635;
        for (int sum = lo; sum <= hi; sum++) {
            int temp = 10000 * sum;
            for (int a = 1; a <= maxA && a <= hi / 3.0; a++) {
                if (temp % a != 0) continue;
                int maxB = ceil(sqrt(temp / a));
                for (int b = a; b <= maxB; b++) {
                    int c = sum - a - b;
                    if (c < b) break;
                    if (a * b * c == temp) {
                        fprintf(stdout, "%d.%02d = %d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n", 
                            sum / 100, sum % 100, a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, a / 100, a % 100, b / 100, b % 100, c / 100, c % 100);
                        // fprintf(pFile, "%d.%02d = %d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n", 
                        //     sum / 100, sum % 100, a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, a / 100, a % 100, b / 100, b % 100, c / 100, c % 100);
                    } 
                }
            }
        }
    }
	fclose(pFile);
	return 0;
}