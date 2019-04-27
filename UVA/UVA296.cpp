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

int raiseTo(int base, int expo) {
    int prod = 1;
    for (int i = 0; i < expo; i++) {
        prod *= base;
    }
    return prod;
}

int getDigit(int pos, int n) {
    return n / (raiseTo(10, pos)) % 10;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    while (t--) {
        int n;
        SCD(n);
        vector<iii> guesses;
        FOR (i, 0, n, 1) {
            iii guess;
            fscanf(stdin, "%d %d/%d", &guess.first, &guess.second.first, &guess.second.second);
            guesses.PB(guess);
        }
        vi ans;
        bool done = false;
        for (int i = 0; i < 10000 && !done; i++) {
            bool consistent = true;
            for (int j = 0; j < n && consistent; j++) {
                int tama = 0;
                int misplaced = 0;
                bitset<4> bs;
                int ansDig[4];
                int arr1[10] = {0};
                int guessDig[4];
                int arr2[10] = {0};
                for (int k = 0; k < 4; k++) {
                    ansDig[k] = getDigit(k, i);
                    guessDig[k] = getDigit(k, guesses[j].first);
                    if (ansDig[k] == guessDig[k]) {
                        tama++;
                        bs.set(k);
                    } else {
                        arr1[ansDig[k]]++;
                        arr2[guessDig[k]]++;
                    }
                }
                for (int k = 0; k < 10; k++) {
                    misplaced += min(arr1[k], arr2[k]);
                }
                if (tama != guesses[j].second.first || misplaced != guesses[j].second.second) {
                    consistent = false;
                }
            }
            if (consistent) {
                ans.PB(i);
                done = ans.size() == 2;
            }
        }
        if (ans.size() == 1) {
            fprintf(stdout, "%04d\n", ans[0]);
            fprintf(pFile, "%04d\n", ans[0]);
        } else if (ans.size() == 0) {
            fprintf(stdout, "impossible\n");
            fprintf(pFile, "impossible\n");
        } else {
            fprintf(stdout, "indeterminate\n");
            fprintf(pFile, "indeterminate\n");
        }
    }
	fclose(pFile);
	return 0;
}