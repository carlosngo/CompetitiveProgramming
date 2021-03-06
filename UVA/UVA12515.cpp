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
    int m, q;
    SCD(m); SCD(q);
    string db[m];
    FOR (i, 0, m, 1) {
        cin >> db[i];
    }
    FOR (a, 0, q, 1) {
        string s;
        cin >> s;
        int index;
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            int minDiff = INT_MAX;
            if (db[i].length() >= s.length()) {
                for (int startIndex = 0; startIndex + s.length() <= db[i].length(); startIndex++) {
                    int diff = 0;
                    for (int j = 0; j < s.length(); j++) {
                        // printf("Comparing db string index %d with query string index %d\n", startIndex + j, j);
                        if (s[j] != db[i][startIndex + j]) {
                            // printf("Difference found.");
                            diff++;
                        }
                    }
                    minDiff = min(minDiff, diff);
                }
            }
            if (minDiff < ans) {
                ans = minDiff;
                index = i + 1;
            }
        }
        fprintf(stdout, "%d\n", index);
        fprintf(pFile, "%d\n", index);
    }
	fclose(pFile);
	return 0;
}