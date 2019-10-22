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
  
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    
    vii scoring;
    scoring.PB(ii(2, 1));
    for (int i = 6; i >= 1; i--) scoring.PB(ii(i, i));
    for (int i = 6; i >= 3; i--) {
        for (int j = i - 1; j >= 1; j--) {
            scoring.PB(ii(i, j));
        }
    }

    char s0, s1, r0, r1;
    while (cin >> s0 >> s1 >> r0 >> r1, !(s0 == '0' && s1 == '0' && r0 == '0' && r1 == '0')) {
        int total = 0;
        int winning = 0;
        int urIndex, oppIndex;
        if (s0 == '*' && s1 == '*' && r0 == '*' && r1 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    for (int y = 1; y <= 6; y++) {
                        for (int z = 1; z <= 6; z++) {
                            int a = w;
                            int b = x;
                            if (a < b) swap(a, b);
                            int c = y;
                            int d = z;
                            if (c < d) swap(c, d);
                            for (int i = scoring.size() - 1; i >= 0; i--) {
                                int j = scoring[i].first;
                                int k = scoring[i].second;
                                if (j == a && k == b) urIndex = i;
                                if (j == c && k == d) oppIndex = i;
                            }
                            if (urIndex < oppIndex) winning++;
                            total++;

                        }
                    }
                    
                }
            }
        } else if (s0 == '*' && s1 == '*' && r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    for (int y = 1; y <= 6; y++) {
                        int a = w;
                        int b = x;
                        if (a < b) swap(a, b);
                        int c = y;
                        int d = r1 - '0';
                        if (c < d) swap(c, d);
                        for (int i = scoring.size() - 1; i >= 0; i--) {
                            int j = scoring[i].first;
                            int k = scoring[i].second;
                            if (j == a && k == b) urIndex = i;
                            if (j == c && k == d) oppIndex = i;
                        }
                    }
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*' && s1 == '*' && r1 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    for (int y = 1; y <= 6; y++) {
                        int a = w;
                        int b = x;
                        if (a < b) swap(a, b);
                        int c = r0 - '0';
                        int d = y;
                        if (c < d) swap(c, d);
                        for (int i = scoring.size() - 1; i >= 0; i--) {
                            int j = scoring[i].first;
                            int k = scoring[i].second;
                            if (j == a && k == b) urIndex = i;
                            if (j == c && k == d) oppIndex = i;
                        }
                    }
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*' && r1 == '*' && r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    for (int y = 1; y <= 6; y++) {
                        int a = w;
                        int b = s1 - '0';
                        if (a < b) swap(a, b);
                        int c = x;
                        int d = y;
                        if (c < d) swap(c, d);
                        for (int i = scoring.size() - 1; i >= 0; i--) {
                            int j = scoring[i].first;
                            int k = scoring[i].second;
                            if (j == a && k == b) urIndex = i;
                            if (j == c && k == d) oppIndex = i;
                        }
                    }
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s1 == '*' && r1 == '*' && r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    for (int y = 1; y <= 6; y++) {
                        int a = s0 - '0';
                        int b = w;
                        if (a < b) swap(a, b);
                        int c = x;
                        int d = y;
                        if (c < d) swap(c, d);
                        for (int i = scoring.size() - 1; i >= 0; i--) {
                            int j = scoring[i].first;
                            int k = scoring[i].second;
                            if (j == a && k == b) urIndex = i;
                            if (j == c && k == d) oppIndex = i;
                        }
                    }
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*' && s1 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = w;
                    int b = x;
                    if (a < b) swap(a, b);
                    int c = r0 - '0';
                    int d = r1 - '0';
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*' && r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = w;
                    int b = s1 - '0';
                    if (a < b) swap(a, b);
                    int c = x;
                    int d = r1 - '0';
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*' && r1 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = w;
                    int b = s1 - '0';
                    if (a < b) swap(a, b);
                    int c = r0 - '0';
                    int d = x;
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s1 == '*' && r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = s0 - '0';
                    int b = w;
                    if (a < b) swap(a, b);
                    int c = x;
                    int d = r1 - '0';
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s1 == '*' && r1 == '*') {
           for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = s0 - '0';
                    int b = w;
                    if (a < b) swap(a, b);
                    int c = r0 - '0';
                    int d = x;
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (r0 == '*' && r1 == '*') {
            for (int w = 1; w <= 6; w++) {
                for (int x = 1; x <= 6; x++) {
                    int a = s0 - '0';
                    int b = s1 - '0';
                    if (a < b) swap(a, b);
                    int c = w;
                    int d = x;
                    if (c < d) swap(c, d);
                    for (int i = scoring.size() - 1; i >= 0; i--) {
                        int j = scoring[i].first;
                        int k = scoring[i].second;
                        if (j == a && k == b) urIndex = i;
                        if (j == c && k == d) oppIndex = i;
                    }
                
                    if (urIndex < oppIndex) winning++;
                    total++;
                }
            }
        } else if (s0 == '*') {
            for (int w = 1; w <= 6; w++) {
                int a = w;
                int b = s1 - '0';
                if (a < b) swap(a, b);
                int c = r0 - '0';
                int d = r1 - '0';
                if (c < d) swap(c, d);
                for (int i = scoring.size() - 1; i >= 0; i--) {
                    int j = scoring[i].first;
                    int k = scoring[i].second;
                    if (j == a && k == b) urIndex = i;
                    if (j == c && k == d) oppIndex = i;
                }
            
                if (urIndex < oppIndex) winning++;
                total++;
                
            }
        } else if (s1 == '*') {
            for (int w = 1; w <= 6; w++) {
                int a = s0 - '0';
                int b = w;
                if (a < b) swap(a, b);
                int c = r0 - '0';
                int d = r1 - '0';
                if (c < d) swap(c, d);
                for (int i = scoring.size() - 1; i >= 0; i--) {
                    int j = scoring[i].first;
                    int k = scoring[i].second;
                    if (j == a && k == b) urIndex = i;
                    if (j == c && k == d) oppIndex = i;
                }
            
                if (urIndex < oppIndex) winning++;
                total++;
                
            }
        } else if (r0 == '*') {
            for (int w = 1; w <= 6; w++) {
                int a = s0 - '0';
                int b = s1 - '0';
                if (a < b) swap(a, b);
                int c = w;
                int d = r1 - '0';
                if (c < d) swap(c, d);
                for (int i = scoring.size() - 1; i >= 0; i--) {
                    int j = scoring[i].first;
                    int k = scoring[i].second;
                    if (j == a && k == b) urIndex = i;
                    if (j == c && k == d) oppIndex = i;
                }
            
                if (urIndex < oppIndex) winning++;
                total++;
                
            }
        } else if (r1 == '*') {
            for (int w = 1; w <= 6; w++) {
                int a = s0 - '0';
                int b = s1 - '0';
                if (a < b) swap(a, b);
                int c = r0 - '0';
                int d = w;
                if (c < d) swap(c, d);
                for (int i = scoring.size() - 1; i >= 0; i--) {
                    int j = scoring[i].first;
                    int k = scoring[i].second;
                    if (j == a && k == b) urIndex = i;
                    if (j == c && k == d) oppIndex = i;
                }
            
                if (urIndex < oppIndex) winning++;
                total++;
                
            }
        } else {
            int a = s0 - '0';
            int b = s1 - '0';
            if (a < b) swap(a, b);
            int c = r0 - '0';
            int d = r1 - '0';
            if (c < d) swap(c, d);
            for (int i = scoring.size() - 1; i >= 0; i--) {
                int j = scoring[i].first;
                int k = scoring[i].second;
                if (j == a && k == b) urIndex = i;
                if (j == c && k == d) oppIndex = i;
            }
        
            if (urIndex < oppIndex) winning++;
            total++;
        }
        int gd= gcd(winning, total);
        if (winning == 0) cout << 0 << '\n';
        else if (winning == total) cout << 1 << '\n';
        else cout << (winning / gd) << '/' << (total / gd) << '\n';
    }


	return 0;
}