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
const int fxx[6][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}};

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	int t;
    SCD(t);
    for (int ctr = 1; ctr <= t; ctr++) {
        if (ctr > 1) fprintf(stdout, "\n");
        map<char, int> neighbors;
        string input;
        cin >> input;
        stack<char> s;
        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];
            if (s.empty()) { 
                s.push(ch);
                neighbors[s.top()] = -1;
            } else {
                neighbors[s.top()]++;
                if (s.top() != ch) {
                    s.push(ch);
                } else {
                    s.pop();
                }
            }
        } 
        fprintf(stdout, "Case %d\n", ctr);
        int j = 0;
        for (map<char, int>::iterator itr = neighbors.begin(); itr != neighbors.end(); itr++) {
            if (j) fprintf(stdout, "\n");
            fprintf(stdout, "%c = %d", itr->first, itr->second);
            j++;
        }
    }
	return 0;
}