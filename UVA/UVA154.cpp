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

int convToInt(char ch) {
    if (ch == 'r') return 0;
    if (ch == 'o') return 1;
    if (ch == 'y') return 2;
    if (ch == 'g') return 3;
    if (ch == 'b') return 4;

}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    string line;
    vvi arr;
    while (cin >> line, line != "#") {
        
        if (line[0] == 'e') {
            int ans;
            int minDiff = INT_MAX;
            for (int i = 0; i < arr.size(); i++) {
                int diff = 0;
                for (int j = 0; j < arr.size(); j++) {
                    for (int k = 0; k < 5; k++) {
                        if (arr[i][k] != arr[j][k]) diff++;
                    }
                }
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = i + 1;
                }
            }
            fprintf(stdout, "%d\n", ans);
            fprintf(pFile, "%d\n", ans);
            arr = vvi();
        } else {
            vi bins(5);
            for (int i = 0; i < 5; i++) {
                bins[convToInt(line[i * 4])] = line[i * 4 + 2]; 
            }
            arr.PB(bins);
        }
    }
	fclose(pFile);
	return 0;
}