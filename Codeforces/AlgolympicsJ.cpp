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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

char levs[22] = {'s','p','d','f','g','h','i','j','k','l','m','n','o','q','r','t','u','v','w','x','y','z'};
class BigArr {
    public:
    ll total[200000];
    ll subshell[200000];
    ll summ[200000];
};

int main() {
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    vector<string> levels;
    for (int i = 0; i < 22; i++) {
        string s = "";
        s += (char)levs[i];
        levels.PB(s);
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            string s = "";
            s += (char)(i + 'a');
            s += (char)(j + 'a');
            levels.PB(s);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                string s = "";
                s += (char)(i + 'a');
                s += (char)(j + 'a');
                s += (char)(k + 'a');
                levels.PB(s);
            }
        }
    }
    for (int x = 0; x < 26; x++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    string s = "";
                    s += (char)(x + 'a');
                    s += (char)(i + 'a');
                    s += (char)(j + 'a');
                    s += (char)(k + 'a');
                    levels.PB(s);
                }
            }
        }
    }
    // for (int i = 0; i < levels.size(); i++) {
    //     cout << levels[i] << '\n';
    // }
    int size = 200000;
    BigArr* arr = new BigArr;
    arr->subshell[0] = 2;
    arr->total[0] = 2;
    arr->summ[0] = 2;
    ll inc = 6;
    
    for (int i = 1; i < size; i++) {
        if ((i & 1) == 1) { // odd
            arr->subshell[i] = arr->subshell[i - 1];
        } else {
            arr->subshell[i] = arr->subshell[i - 2] + inc;        
            inc += 4;
        }
        arr->total[i] = arr->total[i - 1] + arr->subshell[i];
        arr->summ[i] = arr->summ[i - 1] + 4 * i + 2;
        // fprintf(stdout, "summ[%d] = %lld\n", i, arr->summ[i]);
    }
    
    // for (int i = 0; i < size; i++) {
    //     cout << "total["<< i<< "] = " << arr->total[i] <<'\n';
    // }

    WHILEZ {
        ll a;
        SCLLD(a);
        int pos = (int)(lower_bound(arr->total, arr->total + size, a) - arr->total) + 1;
        ll total = arr->total[pos - 1];
        ll diff = total - a;
        ll dec = (upper_bound(arr->summ, arr->summ + size, diff) - arr->summ) + 1;
        ll n = pos - dec + 1;
        // int e = arr->summ[dec] - diff;
        ll e = (a + arr->summ[dec - 1]) - total;
        // int l = dec - 1;
        // cout << "dec = " << dec << '\n';
        // cout << "n = " << n << '\n';
        // cout << "e = " << e << '\n';
        // cout << "maxsubscap = " << maxSubshellCap << '\n';
        // cout << "s = " << levels[dec - 1] << '\n';
        fprintf(stdout, "%lld%s%lld\n", n, levels[dec - 1].c_str(), e);
        
    }
	return 0;
}