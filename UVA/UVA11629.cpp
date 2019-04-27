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

int compare (double d, int i) {
    if (fabs(d - i) < 1e-10) {
        return 0; 
    } else if (d > i) {
        return 1;
    } else {
        return -1;
    };
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int p, g;
    SCD(p); SCD(g);
    map<string, int> dict;
    while (p--) {
        char input[21];
        int val;
        int dec;
        scanf("%s %d.%d", input, &val, &dec);
        dict[string(input)] = val * 10 + dec;
    }
    int ctr = 1;
    while (g--) {
        bool ans;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        int total = 0;
        while (ss >> word) {
            if (word ==  "=") {
                int comp;
                ss >> comp;
                comp *= 10;
                ans = total == comp;
            } else if (word == "<=") {
                int comp;
                ss >> comp;
                comp *= 10;
                ans = total <= comp;
            } else if (word == ">=") {
                int comp;
                ss >> comp;
                comp *= 10;
                ans = total >= comp;

            } else if (word == ">") {
                int comp;
                ss >> comp;
                comp *= 10;
                ans = total > comp;
            } else if (word == "<") {
                int comp;
                ss >> comp;
                comp *= 10;
                ans = total <  comp;
            } 
            if (word != "+") {
                total += dict[word];
            }
        }
        printf("Guess #%d was %s", ctr, ans ? "correct.\n" : "incorrect.\n");
        ctr++;
    }
	fclose(pFile);
	return 0;
}