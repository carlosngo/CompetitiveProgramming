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
const int CONSONANT = 0;
const int VOWEL = 1;
int l;
string str;
vi underscores;
int len;

ll solve(int index) {
	if (index == underscores.size()) {
		return l > 0 ? 1LL : 0LL;
	} else {
		int pos = underscores[index];
		bool canVow = true;
		bool canCons = true;
		ll ans = 0LL;
		if (pos - 2 >= 0 && pos - 1 >= 0 && str[pos - 2] == 'C' && str[pos - 1] == 'C') canCons = false;
		if (pos - 2 >= 0 && pos - 1 >= 0 && str[pos - 2] == 'V' && str[pos - 1] == 'V') canVow = false;
		if (pos - 1 >= 0 && pos + 1 < len && str[pos - 1] == 'C' && str[pos + 1] == 'C') canCons = false;
		if (pos - 1 >= 0 && pos + 1 < len && str[pos - 1] == 'V' && str[pos + 1] == 'V') canVow = false;
		if (pos + 1 < len && pos + 2 < len && str[pos + 1] == 'C' && str[pos + 2] == 'C') canCons = false;
		if (pos + 1 < len && pos + 2 < len && str[pos + 1] == 'V' && str[pos + 2] == 'V') canVow = false;
		if (canVow) {
			str[pos] = 'V';
			ans += 5LL * solve(index + 1);
		}
		if (canCons) {
			str[pos] = 'C';
			l++;
			ans += solve(index + 1);
			l--;
			ans += 20LL * solve(index + 1);
		}
		str[pos] = '_';
		return ans;
	}
}


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	l = 0;
	len = 0;
	underscores = vi();
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (ch == 'L') {
			l++;
		}
		if (ch == '_') {
			underscores.PB(len);
		} else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
			str[len] = 'V';
		} else {
			str[len] = 'C';
		}
		len++;
	}
	cout << solve(0);
	
	return 0;
}