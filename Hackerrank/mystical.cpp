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
    // freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	string char1, char2;
    int tier1, tier2;
    char div1, div2;
    int pow1, pow2;
    int i = 0;
    while (getline(cin, char1), (char1 != "END")) {
        if (i) cout << "\n\n";
        cin >> tier1 >> div1 >> div1 >> pow1;
        // cout << tier1 << div1 << pow1;
        // cin >> div2;
        getline(cin, char2);
        getline(cin, char2);
        // cout << char2;
        cin >> tier2 >> div2 >> div2 >> pow2;
        // cout << tier2 << div2 << pow2;
            if (tier1 == 0 && tier2 == 0) {
                cout << "Stalemate";
            } else if ((tier1 == 2 && (div1 == 'B' || div1 == 'A') && tier2 >= 4)) {
                cout << char1 << " blinks " << char2 << " out of existence";  
            } else if ((tier2 == 2 && (div2 == 'B' || div2 == 'A') && tier1 >= 4)) {
                cout << char2 << " blinks " << char1 << " out of existence";  
            } else if ( (tier1 == 1 && tier2 >= 2) ) {
                cout << char1 << " blinks " << char2 << " out of existence";  
            } else if ( (tier2 == 1 && tier1 >= 2) ) {
                cout << char2 << " blinks " << char1 << " out of existence";  
            } else if (tier1 == 0 && tier2 != 0) {
                cout << char1 << " blinks " << char2 << " out of existence";  
            } else if (tier2 == 0 && tier1 != 0) {
                cout << char2 << " blinks " << char1 << " out of existence";  
            } else if (tier1 < tier2) {
                cout << char1 << " stomps " << char2 ;
            } else if (tier2 < tier1) {
                cout << char2 << " stomps " << char1 ;
            } else if ((tier1 == tier2 && div1 < div2)) {
                cout << char1 << " stomps " << char2 ;
            } else if ((tier1 == tier2 && div2 < div1)) {
                cout << char2 << " stomps " << char1 ;
            } else if ((tier1 == 1 && tier2 == 1 && div1 == div2 && div1 == 'A' && pow1 - pow2 >= 10000000)) {
                cout << char1 << " stomps " << char2 ;
            } else if ((tier1 == 1 && tier2 == 1 && div1 == div2  && div1 == 'A' &&pow2 - pow1 >= 10000000)) {
                cout << char2 << " stomps " << char1 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 8 && tier1 <= 11 && pow1 - pow2 >= 10) {
                cout << char1 << " beats " << char2 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 5 && tier1 <= 7 && pow1 - pow2 >= 100) {
                cout << char1 << " beats " << char2 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 2 && tier1 <= 4 && pow1 - pow2 >= 250) {
                cout << char1 << " beats " << char2 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 == 1 && pow1 - pow2 >= 1000000) {
                cout << char1 << " beats " << char2 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 8 && tier1 <= 11 && pow2 - pow1 >= 10) {
                cout << char2 << " beats " << char1 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 5 && tier1 <= 7 && pow2 - pow1 >= 100) {
                cout << char2 << " beats " << char1 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 >= 2 && tier1 <= 4 && pow2 - pow1 >= 250) {
                cout << char2 << " beats " << char1 ;
            } else if ((tier1 == tier2 && div1 == div2) && tier1 == 1 && pow2 - pow1 >= 1000000) {
                cout << char2 << " beats " << char1 ;
            } else {
                cout << "Stalemate";
            }

        
        getline(cin, char2);
        getline(cin, char2);
        i++;
    } 
	return 0;
}