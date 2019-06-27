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
    int c, n, m, t;
    SCD(c);
    FOR (a, 0, c, 1) {
        if (a > 0) {
            fprintf(stdout, "\n");
        }
        SCD(n); SCD(t); SCD(m);
        queue<ii> left, right;
        map<int, int> ans;
        bool isLeft = true;
        int cur = 0;
        int ctr = 0;
        vi carrying;
        FOR (i, 0, m, 1) {
            char wer[1000];
            int weight;
            fscanf(stdin, " %d %s", &weight, wer);
            if (strcmp(wer, "left") == 0) {
                left.push(ii(i, weight));
            }
            else { 
                right.push(ii(i, weight)); 
            }
        }
        
        while (!left.empty() || !right.empty()) {
            if (isLeft) {
                if (!left.empty() && cur >= left.front().second && carrying.size() < n) {
                    carrying.PB(left.front().first);
                    left.pop();
                } else if (carrying.size() > 0 || (!right.empty() && cur >= right.front().second)) {
                    isLeft = false;
                    cur += t;
                    FOR (i, 0, carrying.size(), 1) {
                        ans[carrying[i]] = cur;
                    }
                    carrying.clear();
                } else {
                    if (right.empty()) {
                        cur = left.front().second;
                    } else if (left.empty()) {
                        cur = right.front().second;
                    } else {
                        cur = min(right.front().second, left.front().second);
                    }
                }    
            } else {
                if (!right.empty() && cur >= right.front().second && carrying.size() < n) {
                    carrying.PB(right.front().first);
                    right.pop();
                } else if (carrying.size() > 0 || (!left.empty() && cur >= left.front().second)) {
                    isLeft = true;
                    cur += t;
                    FOR (i, 0, carrying.size(), 1) {
                        ans[carrying[i]] = cur;
                    }
                    carrying.clear();
                } else {
                    if (right.empty()) {
                        cur = left.front().second;
                    } else if (left.empty()) {
                        cur = right.front().second;
                    } else {
                        cur = min(right.front().second, left.front().second);
                    }
                }           
            }
            ctr++;
        }
        FOR (i, 0, m, 1) {
            fprintf(stdout, "%d\n", ans[i] != 0 ? ans[i] : cur + t);
        }
    }
	// fclose(pFile);
	return 0;
}