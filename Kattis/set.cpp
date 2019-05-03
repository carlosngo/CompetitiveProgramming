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

bool isSet(string first, string second, string third) {
    // cout << first << " " << second << " " << third << "\n";
    if ((first[0] != second[0] && second[0] != third[0] && first[0] != third[0]) || (first[0] == second[0] && first[0] == third[0])) {
        if ((first[1] != second[1] && second[1] != third[1] && first[1] != third[1]) || (first[1] == second[1] && first[1] == third[1])) {
            if ((first[2] != second[2] && second[2] != third[2] && first[2] != third[2]) || (first[2] == second[2] && first[2] == third[2])) {
                return (first[3] != second[3] && second[3] != third[3] && first[3] != third[3]) || (first[3] == second[3] && first[3] == third[3]);
            } else return false;
        } else return false;
    } else return false;
}

int main() {
    string grid[4][3];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }
    set<iii> ans;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            string first = grid[i][j];
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 3; l++) {
                    if (i != k || j != l) {
                        string second = grid[k][l];
                        for (int m = 0; m < 4; m++) {
                            for (int n = 0; n < 3; n++) {
                                if ((m != i || n != j) && (m != k || n != l)) {
                                    string third = grid[m][n];
                                    if (isSet(first, second, third)) {
                                        ans.insert(iii(i * 3 + j + 1, ii(k * 3 + l + 1, m * 3 + n + 1)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        cout << "no sets";
        return 0;
    }
    FOREACH(itr, ans) {
        int first = itr->first, second = itr->second.first, third = itr->second.second;
        if (first < second && second < third) 
            cout << first << " " << second << " " << third << "\n";
    }
	
	return 0;
}