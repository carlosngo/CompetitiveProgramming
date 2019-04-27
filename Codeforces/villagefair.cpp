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
    int n;
    SCD(n);
    vi nextHop;
    vi nextHopVal;
    vector<set<int> > joyValues = vector<set<int> >(n, set<int>());
    vi kids;
    for (int i = 0; i < n; i++) {
        int init;
        SCD(init);
        kids.PB(init);
        joyValues[i].insert(init);
    }
    for (int i = 0; i < n; i++) {
        int next;
        SCD(next);
        next--;
        nextHop.PB(next);
    }
    for (int i = 0; i < n; i++) {
        int hopValue;
        SCD(hopValue);
        nextHopVal.PB(hopValue);
    }
	for (int i = 0; i < n; i++) {
        int kid = kids[i];
        int cur = i;
        // printf("Starting at house %d with initial value %d and going to next house %d\n", i, kid, cur);
        while (1) {
            // printf("Currently at house %d\n", cur);
            kid += nextHopVal[cur];
            cur = nextHop[cur];
            if (cur == -1) break;
            joyValues[cur].insert(kid);
        }
        // joyValues[next].insert(kid);
    }
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "%d\n", joyValues[i].size());
    }

    // for (int i = 0; i < n; i++) {
        // printf("House %d got the ff joy values: ");
    //     for (set<int>::iterator itr = joyValues[i].begin(); itr != joyValues[i].end(); itr++) {
    //         printf("%d ", *itr);
    //     }
    //     printf("\n");
    // }
	return 0;
}