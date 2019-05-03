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


map<char, vector<char> > adjList;
bitset<256> lit; 
vector<char> candles;
int k;
char previous;
char trapped;

void dfs(char mino, int num) {
    // fprintf(stdout, "Minotaur at %c, Num = %d\n", mino, num);
    if (num == k - 1) { 
        // fprintf(stdout, "Placing candle...\n");
        lit.set(mino - 'A');
        candles.PB(mino);
    }
    char nextChar;
    vector<char> neighbors = adjList[mino];
    bool found = false;
    for (int i = 0; i < neighbors.size() && !found; i++) {
        char next = neighbors[i];
        if (next != previous && !lit.test(next - 'A')) {
            previous = mino;
            dfs(next, num + 1 == k ? 0 : num + 1);
            found = true;
        }
    }
    if (!found) trapped = mino;
}


int main() {
    // freopen("out.txt", "wt", stdout);
    string line;
    while (getline(cin, line), line != "#") {
        adjList = map<char, vector<char> >();
        lit = bitset<256>();
        candles = vector<char>();
        stringstream ss(line);
        char ch, dummy;
        char current;
        ss >> current >> dummy;
        while (ss >> ch, ch != '.') {
            vector<char> neighbors;
            if (ch == ';') {
                ss >> current;
                ss >> dummy;
            } else {
                adjList[current].push_back(ch);
            }
        }
        char mino, thes;
        ss >> mino >> thes >> k;
        // fprintf(stdout, "Mino starting point = %c, thes = %c, k = %d\n", mino, thes, k);
        previous = thes;
        dfs(mino, 0);
        for (int i = 0; i < candles.size(); i++) {
            if (candles[i] != trapped) fprintf(stdout, "%c ", candles[i]);
        }
        fprintf(stdout, "/%c\n", trapped);
        // fprintf(stdout, "Done processing input.");
    }
	return 0;
}