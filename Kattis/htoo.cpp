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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	map<char, int> inputMap;
    map<char, int> outputMap;
    string input;
    string output;
    int k;
    cin >> input >> k;
    cin >> output;
    for (int i = 0; i < input.length(); i++) {
        char mol = input[i];
        int num = 0;
        int j;
        for (j = i + 1; j < input.length() && !isalpha(input[j]); j++) {
            num = num * 10 + (int)(input[j] - '0');
        }
        if (num == 0) num = 1;
        inputMap[mol] = inputMap[mol] + num;
        // fprintf(stdout, "inputMap[%c] = %d\n", mol, inputMap[mol]);
        i = j - 1;
    }
    for (map<char, int>::iterator itr = inputMap.begin(); itr != inputMap.end(); itr++) {
        itr->second *= k;
    }
    for (int i = 0; i < output.length(); i++) {
        char mol = output[i];
        int num = 0;
        int j;
        for (j = i + 1; j < output.length() && !isalpha(output[j]); j++) {
            num = num * 10 + (int)(output[j] - '0');
        }
        if (num == 0) num = 1;
        outputMap[mol] = outputMap[mol] + num;
        // fprintf(stdout, "outputMap[%c] = %d\n", mol, outputMap[mol]);
        i = j - 1;
    }
    int ans = INT_MAX;
    for (map<char, int>::iterator itr = outputMap.begin(); itr != outputMap.end(); itr++) {
        ans = min(ans, inputMap[itr->first] / itr->second);
        if (ans == 0) break;
    }
    fprintf(stdout, "%d\n", ans);
	return 0;
}