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
    int t;
    SCD(t);
    while (t--) {
        int n;
        SCD(n);
        string arr[71];
        FOR (i, 0, n, 1) cin >> arr[i];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                string s1 = arr[i].length() >= arr[j].length() ? arr[i] : arr[j];
                string s2 = arr[i] == s1 ? arr[j] : arr[i];
                int s1Len = s1.length();
                int s2Len = s2.length();
                // for (int s2start = s2Len - 1; s2start >= 0; s2start--) {
                //     int pts = 0;
                //     int s1Index = 0;
                //     for (int s2Index = s2start; s2Index < s2Len; s2Index++) {
                //         if (s1Index >= s1Len) break;
                //         if (s1[s1Index] == s2[s2Index]) {
                //             pts++;
                //         }
                //         s1Index++;
                //     }
                //     ans = max(ans, pts);
                // }
                for (int s1start = 0; s1start < s1Len; s1start++) {
                    // for (int s2start = s2Len - 1; s2start >= 0; s2start--) {
                        int pts = 0;
                        int s1Index = s1start;
                        for (int s2Index = 0; s2Index < s2Len; s2Index++) {
                            if (s1Index >= s1Len) break;
                            if (s1[s1Index] == s2[s2Index]) {
                                pts++;
                            }
                            s1Index++;
                        }
                        ans = max(ans, pts);
                    // }
                }
            }
        }
        fprintf(stdout, "%d\n", ans);
        fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}