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
    priority_queue<int, vi, less<int> > evens1;
    priority_queue<int, vi, less<int> > evens2;
    priority_queue<int, vi, less<int> > odds1;
    priority_queue<int, vi, less<int> > odds2;
    for (int i = 0; i < n; i++) {
        int num;
        SCD(num);
        if (num % 2) odds1.push(num);
        else evens1.push(num);
    }
    evens2 = evens1;
    odds2 = odds1;
    bool isFinished = false;
    int ans1 = 0, ans2 = 0;
    bool state = false;
    if (!evens1.empty()) evens1.pop();
    while (!isFinished) {
        if (state) {
            if (evens1.empty()) isFinished = true; 
            else evens1.pop();
        } else {
            if (odds1.empty()) isFinished = true; 
            else odds1.pop();
        }
        state = !state;
    }
    while (!evens1.empty()) {
        ans1 += evens1.top();
        evens1.pop();
    }
    while (!odds1.empty()) {
        ans1 += odds1.top();
        odds1.pop();
    }
    isFinished = false;
    state = true;
    if (!odds2.empty()) odds2.pop();
    while (!isFinished) {
        if (state) {
            if (evens2.empty()) isFinished = true; 
            else evens2.pop();
        } else {
            if (odds2.empty()) isFinished = true; 
            else odds2.pop();
        }
        state = !state;
    }
    while (!evens2.empty()) {
        ans2 += evens2.top();
        evens2.pop();
    }
    while (!odds2.empty()) {
        ans2 += odds2.top();
        odds2.pop();
    }
    cout << min(ans1, ans2);
	return 0;
}