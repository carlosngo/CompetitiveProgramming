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
	FILE *pFile = fopen("out.txt","w");
    int t, n, p, r;
    int ans[14][14][14] = {
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 2, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 6, 11, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 6, 22, 18, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 11, 18, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 24, 50, 35, 10, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 24, 100, 105, 40, 5, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 50, 105, 60, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 35, 40, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 10, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 120, 274, 225, 85, 15, 1, 0, 0, 0, 0, 0, 0},
		{0, 120, 548, 675, 340, 75, 6, 0, 0, 0, 0, 0, 0, 0},
		{0, 274, 675, 510, 150, 15, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 225, 340, 150, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 85, 75, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 720, 1764, 1624, 735, 175, 21, 1, 0, 0, 0, 0, 0},
		{0, 720, 3528, 4872, 2940, 875, 126, 7, 0, 0, 0, 0, 0, 0},
		{0, 1764, 4872, 4410, 1750, 315, 21, 0, 0, 0, 0, 0, 0, 0},
		{0, 1624, 2940, 1750, 420, 35, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 735, 875, 315, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 175, 126, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 21, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 5040, 13068, 13132, 6769, 1960, 322, 28, 1, 0, 0, 0, 0},
		{0, 5040, 26136, 39396, 27076, 9800, 1932, 196, 8, 0, 0, 0, 0, 0},
		{0, 13068, 39396, 40614, 19600, 4830, 588, 28, 0, 0, 0, 0, 0, 0},
		{0, 13132, 27076, 19600, 6440, 980, 56, 0, 0, 0, 0, 0, 0, 0},
		{0, 6769, 9800, 4830, 980, 70, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1960, 1932, 588, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 322, 196, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 28, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 40320, 109584, 118124, 67284, 22449, 4536, 546, 36, 1, 0, 0, 0},
		{0, 40320, 219168, 354372, 269136, 112245, 27216, 3822, 288, 9, 0, 0, 0, 0},
		{0, 109584, 354372, 403704, 224490, 68040, 11466, 1008, 36, 0, 0, 0, 0, 0},
		{0, 118124, 269136, 224490, 90720, 19110, 2016, 84, 0, 0, 0, 0, 0, 0},
		{0, 67284, 112245, 68040, 19110, 2520, 126, 0, 0, 0, 0, 0, 0, 0},
		{0, 22449, 27216, 11466, 2016, 126, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 4536, 3822, 1008, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 546, 288, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 36, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 362880, 1026576, 1172700, 723680, 269325, 63273, 9450, 870, 45, 1, 0, 0},
		{0, 362880, 2053152, 3518100, 2894720, 1346625, 379638, 66150, 6960, 405, 10, 0, 0, 0},
		{0, 1026576, 3518100, 4342080, 2693250, 949095, 198450, 24360, 1620, 45, 0, 0, 0, 0},
		{0, 1172700, 2894720, 2693250, 1265460, 330750, 48720, 3780, 120, 0, 0, 0, 0, 0},
		{0, 723680, 1346625, 949095, 330750, 60900, 5670, 210, 0, 0, 0, 0, 0, 0},
		{0, 269325, 379638, 198450, 48720, 5670, 252, 0, 0, 0, 0, 0, 0, 0},
		{0, 63273, 66150, 24360, 3780, 210, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 9450, 6960, 1620, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 870, 405, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 45, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 3628800, 10628640, 12753576, 8409500, 3416930, 902055, 157773, 18150, 1320, 55, 1, 0},
		{0, 3628800, 21257280, 38260728, 33638000, 17084650, 5412330, 1104411, 145200, 11880, 550, 11, 0, 0},
		{0, 10628640, 38260728, 50457000, 34169300, 13530825, 3313233, 508200, 47520, 2475, 55, 0, 0, 0},
		{0, 12753576, 33638000, 34169300, 18041100, 5522055, 1016400, 110880, 6600, 165, 0, 0, 0, 0},
		{0, 8409500, 17084650, 13530825, 5522055, 1270500, 166320, 11550, 330, 0, 0, 0, 0, 0},
		{0, 3416930, 5412330, 3313233, 1016400, 166320, 13860, 462, 0, 0, 0, 0, 0, 0},
		{0, 902055, 1104411, 508200, 110880, 11550, 462, 0, 0, 0, 0, 0, 0, 0},
		{0, 157773, 145200, 47520, 6600, 330, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 18150, 11880, 2475, 165, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1320, 550, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 55, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 39916800, 120543840, 150917976, 105258076, 45995730, 13339535, 2637558, 357423, 32670, 1925, 66, 1},
		{0, 39916800, 241087680, 452753928, 421032304, 229978650, 80037210, 18462906, 2859384, 294030, 19250, 726, 12, 0},
		{0, 120543840, 452753928, 631548456, 459957300, 200093025, 55388718, 10007844, 1176120, 86625, 3630, 66, 0, 0},
		{0, 150917976, 421032304, 459957300, 266790700, 92314530, 20015688, 2744280, 231000, 10890, 220, 0, 0, 0},
		{0, 105258076, 229978650, 200093025, 92314530, 25019610, 4116420, 404250, 21780, 495, 0, 0, 0, 0},
		{0, 45995730, 80037210, 55388718, 20015688, 4116420, 485100, 30492, 792, 0, 0, 0, 0, 0},
		{0, 13339535, 18462906, 10007844, 2744280, 404250, 30492, 924, 0, 0, 0, 0, 0, 0},
		{0, 2637558, 2859384, 1176120, 231000, 21780, 792, 0, 0, 0, 0, 0, 0, 0},
		{0, 357423, 294030, 86625, 10890, 495, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 32670, 19250, 3630, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1925, 726, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 66, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	},
};
    SCD(t);
    while (t--) {
        SCD(n); SCD(p); SCD(r);
        fprintf(stdout, "%d\n", ans[n][p][r]);
        // fprintf(pFile, "%d\n", ans[n][p][r]);
    }
   
	fclose(pFile);
	return 0;
}