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
    string input;
    map<string, pair<int, string> > s;
    while (cin >> input, input != "#") {
        string sorted = input;
        transform(sorted.begin(), sorted.end(), sorted.begin(), ::tolower);
        sort(all(sorted));
        if (s.find(sorted) == s.end()) {
            s[sorted] = pair<int, string>(1, input);
        } else {
            s[sorted] = pair<int, string>(s[sorted].first + 1, input);
        }
    }
    set<string> ans;
    for (map<string, pair<int, string> >::iterator itr = s.begin(); itr != s.end(); ++itr) {
        if (itr->second.first == 1) {
            ans.insert(itr->second.second);
        }
    }
    for (set<string>::iterator itr = ans.begin(); itr != ans.end(); ++itr) {
        printf("%s\n", (*itr).c_str());
        fprintf(pFile, "%s\n", (*itr).c_str());
        
    }
    
	fclose(pFile);
	return 0;
}