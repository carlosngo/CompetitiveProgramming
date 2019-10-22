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
const int UNVISITED = -1;

int main() {
    string n, k;
    cin >> n >> k;
    int minK;
    int digits = n.length();
    string s = digits + "";
    int digits_of_digits = s.length();
    string subs = k.substr(k.length() - digits_of_digits, digits_of_digits);
    int k_sub = stoi(subs);
    if (digits_of_digits < k.length()) {
        minK = digits;
        minK += 10 * digits;
        string s2 = minK + "";
        int new_k_digits = s2.length();
        if (new_k_digits < k.length()) {
            cout << "Your wish is granted!";
        } else if (new_k_digits == k.length()) {
            
        } else {
            cout << "You will become a flying monkey!";
        }
    } else if (digits_of_digits == k.length()) {
        
        if (digits <= k_sub) {
            minK = digits;
            minK += 10 * digits;
            string s2 = minK + "";
            int new_k_digits = s2.length();
            if (new_k_digits < k.length()) {
                cout << "Your wish is granted!";
            } else if (new_k_digits == k.length()) {
                
            } else {
                cout << "You will become a flying monkey!";
            }
        }
    } else {
        cout << "You will become a flying monkey!";
    }
	return 0;
}