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
	// freopen("out.txt", "wt", stdout);
    
	int n;
    SCD(n);
    bitset<1001> facedUp;
    int facedDown = n;
    map<string, vi> cards;
    int k;
    SCD(k);
    int ans = 0;
    while (k--) {
        int a, b;
        string s1, s2;
        cin >> a >> b >> s1 >> s2;
        if (!facedUp.test(a)) {
            facedDown--;
            facedUp.set(a);
        }
        if (!facedUp.test(b)) {
            facedDown--;
            facedUp.set(b);
        }
        if (s1 == s2) ans--;
        vi meh = cards[s1];
        vi bla = cards[s2];
        if (meh.empty()) {
            cards[s1].PB(a);
        } else if (meh.size() == 1 && meh[0] != a) {
            cards[s1].PB(a);
            ans++;
        }
        if (bla.empty()) {
            cards[s2].PB(b);
        } else if (bla.size() == 1 && bla[0] != b) {
            cards[s2].PB(b);
            ans++;
        }
    }
    int loners = 0;
    int completes = 0;
    for (map<string, vi>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
        if (itr->second.size() == 1) loners++;
    }
    if (loners == facedDown) {
        ans += loners;
    }
    fprintf(stdout, "%d\n", ans);
	return 0;
}