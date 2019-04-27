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
	FILE *pFile = fopen("out.txt","w");
    string line;
    while (cin >> line, line != "0") {
        bool ans = true;
        for (int mask = 0; mask < 32 && ans; mask++) {
            bool p = (mask & (1 << 4));
            bool q = (mask & (1 << 3));
            bool r = (mask & (1 << 2));
            bool s = (mask & (1 << 1));
            bool t = (mask & (1));
            stack<bool> st;
            for (int i = line.length() - 1; i >= 0; i--) {
                if (line[i] == 'K') {
                    bool b1 = st.top(); st.pop();
                    bool b2 = st.top(); st.pop();
                    st.push(b1 && b2);
                } else if (line[i] == 'A') {
                    bool b1 = st.top(); st.pop();
                    bool b2 = st.top(); st.pop();
                    st.push(b1 || b2);
                } else if (line[i] == 'N') {
                    bool temp = st.top(); 
                    st.pop();
                    st.push(!temp);
                } else if (line[i] == 'C') {
                    bool b1 = st.top(); st.pop();
                    bool b2 = st.top(); st.pop();
                    st.push(!b1 || b2);
                } else if (line[i] == 'E') {
                    bool b1 = st.top(); st.pop();
                    bool b2 = st.top(); st.pop();
                    st.push(b1 == b2);
                } else if (line[i] == 'p') {
                    st.push(p);
                } else if (line[i] == 'q') {
                    st.push(q);
                } else if (line[i] == 'r') {
                    st.push(r);
                } else if (line[i] == 's') {
                    st.push(s);
                } else if (line[i] == 't') {
                    st.push(t);
                }
            }
            if (!st.top()) ans = false;
        }
        fprintf(stdout, "%s\n", ans ? "tautology" : "not");
        fprintf(pFile, "%s\n", ans ? "tautology" : "not");
    }
	fclose(pFile);
	return 0;
}