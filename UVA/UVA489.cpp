#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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
    int rnd;
    string soln, guess;
    while (SCD(rnd), rnd != -1) {
        cin >> soln >> guess;
        set<char> sSol;
        bitset<1000> bs;
        int inc = 0, ac = 0; 
        bool win = false;
        
        FOR (i, 0, guess.length(), 1) {
            int val = guess[i] - 'a';
            if (!bs.test(val)) {
                if (soln.find(guess[i]) != std::string::npos) {
                    ac++;
                    soln.erase(remove(all(soln), guess[i]), soln.end());
                }
                else 
                    inc++;
                if (soln == "") {
                    win = true;
                    break;
                }
                if (inc == 7)
                    break;
                bs.set(val);
            }
        }
        printf("Round %d\n", rnd);
        fprintf(pFile, "Round %d\n", rnd);
        if (inc == 7) {
            printf("You lose.\n");
            fprintf(pFile, "You lose.\n");
        } else if (win) {
            printf("You win.\n");
            fprintf(pFile, "You win.\n");
        } else {
            printf("You chickened out.\n");
            fprintf(pFile, "You chickened out.\n");
        }
    }
	fclose(pFile);
	return 0;
}