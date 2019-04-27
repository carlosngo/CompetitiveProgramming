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

class Place {
    public: 
        int cont;
        int subs;
        int pen;

        Place(int _cont, int _prob, int _time) {
            cont = _cont;
            subs = _prob;
            pen = _time;
        }
};

bool compare(const Place& a, const Place& b) {
    if (a.subs < b.subs)
        return false;
    else if (a.subs == b.subs) {
        if (a.pen < b.pen)
            return true;
        else if (a.pen == b.pen) {
            return a.cont < b.cont;
        } else
            return false;
    } else
        return true;
        
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    string dummy;
    scanf("%d", &n);
    getline(cin, dummy);
    while(n--) {
        vi penalty(100, 0);
        vi subs(100, 0);
        vvi inc (100, vi(10));
        vector<Place> res;
        vector<bitset<10> > ac(100);
        string input;
       
        while (getline(cin, input), input != "") {
            stringstream ss(input);
            int cont, prob, time;
            char l;
            ss >> cont >> prob >> time >> l;
            cont--; prob--;
            subs[cont]++;
            if (l == 'I') {
                if (!ac[cont].test(prob)) {
                    inc[cont][prob]++;
                }
            } else if (l == 'C') {
                if (!ac[cont].test(prob)) {
                    penalty[cont] += time + inc[cont][prob] * 20;
                    ac[cont].set(prob);
                }
            }
        } 
        FOR (i, 0, 100, 1) {
            if (subs[i] > 0) {
                res.PB(Place(i, ac[i].count(), penalty[i]));
            }
        }
        sort(all(res), compare);
        // for (int i = res.size() - 1; i >= 0; i--) {
        FOR(i, 0, res.size(), 1) {
            printf("%d %d %d\n", res[i].cont + 1, res[i].subs, res[i].pen);
            fprintf(pFile, "%d %d %d\n", res[i].cont + 1, res[i].subs, res[i].pen);
        }
        if (n > 0) {
            printf("\n");
            fprintf(pFile, "\n");
        }
    }
	fclose(pFile);
	return 0;
}