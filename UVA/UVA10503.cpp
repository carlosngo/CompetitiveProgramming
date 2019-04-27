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

int n, m;
vii board;
vii pieces;
bitset<15> used;
ii lPiece, rPiece;
bool ans;

void solve(int pos) {
	// printf("Board Content:\n");
	// for (int i = 0; i < board.size(); i++) {
	// 	printf("| %d %d |", board[i].first, board[i].second);
	// }
	// printf("\n");
	if (pos == n + 1) {
		ans = rPiece.first == board[pos - 1].second;
	} else {
		for (int i = 0; i < pieces.size() && !ans; i++) {
			if (!used.test(i)) {
				if (pieces[i].first == board[pos - 1].second) {
					board.PB(pieces[i]);
					used.set(i);
					solve(pos + 1);
					board.pop_back();
					used.reset(i);
				} else if (pieces[i].second == board[pos - 1].second) {
					board.PB(ii(pieces[i].second, pieces[i].first));
					used.set(i);
					solve (pos + 1);
					board.pop_back();
					used.reset(i);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
	while (SCD(n), n != 0) {
		SCD(m);
		int le, ri;
		SCD(le); SCD(ri);
		lPiece = ii(le, ri);
		SCD(le); SCD(ri);
		ans = false;
		rPiece = ii(le, ri);
		pieces = vii(m);
		board = vii();
		board.PB(lPiece);
		FOR (i, 0, m, 1) {
			SCD(le); SCD(ri);
			pieces[i] = ii(le, ri);
		} 
		solve(1);
		fprintf(stdout, "%s", ans ? "YES\n" : "NO\n");
		// fprintf(pFile, "%s", ans ? "YES\n" : "NO\n");
	}
	fclose(pFile);
	return 0;
}