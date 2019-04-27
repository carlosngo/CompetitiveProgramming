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
    int c, l, m;
    SCD(c);
    while (c--) {
        SCD(l); SCD(m);
        l *= 100;
        queue<int> left, right;
        int ans = 0;
        while (m--) {
            string wer;
            int weight;
            cin >> weight >> wer;
            if (wer == "left") left.push(weight);
            else right.push(weight);
        }
        bool isLeft = true;
        int cur = 0;
        while (!left.empty() || !right.empty()) {
            if (isLeft) {
                if (cur + left.front() > l || left.empty()) {
                    cur = 0;
                    isLeft = false;
                    ans++;
                } else {
                    cur += left.front(); left.pop();
                }                
            } else {
                if (cur + right.front() > l || right.empty()) {
                    cur = 0;
                    isLeft = true;
                    ans++;
                } else {
                    cur += right.front(); right.pop();
                }                
            }
        }
        fprintf(stdout, "%d\n", ans + 1);
        // fprintf(pFile, "%d\n", ans + 1);
    }
	fclose(pFile);
	return 0;
}