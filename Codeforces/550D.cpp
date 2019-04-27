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
typedef vector<iii> viii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
    int n;
    SCD(n);
    map<int, vi> m;
    int maxOcc = 0;
    int maxNum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int num;
        SCD(num);
        if (m.find(num) == m.end()) m[num] = vi();
        m[num].push_back(i);
        int occ = m[num].size();
        if (occ > maxOcc) {
            maxOcc = occ;
            maxNum = num;
        }
    }
    vi indices = m[maxNum];
    viii ops;
    // for (int i = 0; i < indices.size(); i++) cout << indices[i];
    for (int i = indices[0]; i > 0; i--) {
        ops.push_back(iii(1, ii(i - 1, i)));
    }

    for (int i = 0; i < indices.size() - 1; i++) {
        for (int j = indices[i]; j < indices[i + 1] - 1; j++) {
            ops.push_back(iii(2, ii(j + 1, j)));
        }
    }
    for (int i = indices[indices.size() - 1]; i < n - 1; i++) {
        ops.push_back(iii(2, ii(i + 1, i)));
    }
    cout << ops.size();
    for (int i = 0; i < ops.size(); i++) {
        cout << "\n" << ops[i].first << " " << (ops[i].second.first + 1) << " " << (ops[i].second.second + 1);
    }
	return 0;
}