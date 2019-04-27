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
    map<int, int> arr;
    SCD(n);
    for (int i = 0; i < n; i++) {
        int num;
        SCD(num);
        if (arr.find(num) != arr.end()) {
            arr[num]++;
        } else {
            arr[num] = 1;
        }
    }
    vi increasing, decreasing;
    bool valid = true;
    for (map<int, int>::iterator itr = arr.begin(); itr != arr.end(); itr++) {
        if (itr->second == 1) increasing.push_back(itr->first);
        else if (itr->second == 2) {
            increasing.push_back(itr->first);
            decreasing.push_back(itr->first);
        } else valid = false;
    }
    if (valid) {
        cout << "YES\n" << increasing.size() << "\n";
        for (int i = 0; i < increasing.size(); i++) {
            if (i) cout << " ";
            cout << increasing[i];
        }
        cout << "\n" << decreasing.size() << "\n";
        for (int i = decreasing.size() - 1; i >= 0; i--) {
            if (i < decreasing.size() - 1) cout << " ";
            cout << decreasing[i];
        }
    } else cout << "NO";
	
	return 0;
}