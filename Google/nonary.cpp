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

int digital_root(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) sum += arr[i];
    while (sum > 10) {
        int n = sum;
        int digit_sum = 0;
        while (n > 0) {
            digit_sum += n % 10;
            n /= 10;
        }
        sum = digit_sum;
    }
    return sum;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    set<iii> s;
    set<ii> s2;
    do {
        int gr1[] = {arr[0], arr[1], arr[2]};
        int gr2[] = {arr[3], arr[4], arr[5]};
        int gr3[] = {arr[6], arr[7], arr[8]};
        sort(gr1, gr1 + 3);
        sort(gr2, gr2 + 3);
        sort(gr3, gr3 + 3);
        int one = gr1[0] * 100 + gr1[1] * 10 + gr1[2];
        int two = gr2[0] * 100 + gr2[1] * 10 + gr2[2];
        int three = gr3[0] * 100 + gr3[1] * 10 + gr3[2];
        int threes[] = {one, two, three};
        sort(threes, threes + 3);
        iii comb = iii(threes[0], ii(threes[1], threes[2]));

        int gr4[] = {arr[0], arr[1], arr[2], arr[3]};
        int gr5[] = {arr[4], arr[5], arr[6], arr[7], arr[8]};
        sort(gr4, gr4 + 4);
        sort(gr5, gr5 + 5);
        int four = gr4[0] * 1000 + gr4[1] * 100 + gr4[2] * 10 + gr4[3];
        int five = gr5[0] * 10000 + gr5[1] * 1000 + gr5[2] * 100 + gr5[3] * 10 + gr5[4];
        int fourFives[] = {four, five};
        sort(fourFives, fourFives + 2);
        ii comb2 = ii(fourFives[0], fourFives[1]);
        if (s.find(comb) == s.end()) {
            if (digital_root(gr1, 3) != digital_root(gr2, 3) && digital_root(gr2, 3) != digital_root(gr3, 3) && digital_root(gr1, 3) != digital_root(gr3, 3)) ans++;
            s.insert(comb);
        }
        if (s2.find(comb2) == s2.end()) {
            if (digital_root(gr4, 4) != digital_root(gr5, 5)) ans++;    
            s2.insert(comb2);
        }
        
    } while (next_permutation(arr, arr + 9));
	cout << ans;
	return 0;
}