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


string s;
int q;
vvi letters;

int binSearch(int lo, int hi, int letterInd, int curInd) {
    if (letters[letterInd][0] > curInd) {
        return 0;
    }
    if (letters[letterInd][hi] <= curInd) {
        return -1;
    }
    int mid = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (letters[letterInd][mid - 1] <= curInd && letters[letterInd][mid] > curInd) {
            return mid;
        } else if (letters[letterInd][mid] > curInd) {
            hi = mid - 1;
        } else if (letters[letterInd][mid] <= curInd) {
            lo = mid + 1;
        }
    }
    return mid;
}


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    cin >> s;
    letters = vvi(52, vi());
    for (int i = 0; i < s.length(); i++) {
        if (islower(s[i])) {
            letters[s[i] - 'a' + 26].PB(i);
        } else {
            letters[s[i] - 'A'].PB(i);
        }
    }
    // FOR(i, 0, letters.size(), 1) {
    //     printf("Letter %d: ", i);
    //     FOR (j, 0, letters[i].size(), 1) {
    //         printf("%d ", letters[i][j]);
    //     }
    //     printf("\n");
    // }
    SCD(q);
    FOR (i, 0, q, 1) {
        string ss;
        cin >> ss;
        bool ans = true;
        vi indices;
        int curInd = -1;
        for (int j = 0; j < ss.length() && ans; j++) {
            int let;
            
            if (islower(ss[j])) {
                let = ss[j] - 'a' + 26;
            } else {
                let = ss[j] - 'A';   
            }
            int ind = binSearch(0, letters[let].size() - 1, let, curInd);
            if (ind == -1) {
                ans = false;
            } else {
                curInd = letters[let][ind];
                indices.PB(curInd);
            }
            // printf("For char %c in index %d: Found %d\n", ss[j], j, curInd);
        }
        if (ans) {
            fprintf(stdout, "Matched %d %d\n", indices[0], indices[indices.size() - 1]);
            // fprintf(pFile, "Matched %d %d\n", indices[0], indices[indices.size() - 1]);
        } else {
            fprintf(stdout, "Not matched\n");
            // fprintf(pFile, "Not matched\n");
        }
    }
	fclose(pFile);
	return 0;
}