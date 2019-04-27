#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int MAX_N = (1 << 16);
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    string input;
    vi primes;
    bitset<MAX_N> sieve;
    for (int i = 2; i < MAX_N; i++) {
        if (!sieve.test(i)) {
            primes.PB(i);
            if (i <= (int) sqrt(MAX_N)) {
                for (int j = i * i; j < MAX_N; j += i) {
                    sieve.set(j);
                }
            } 
        }
    }

    while (getline(cin, input), input != "0") {
        map<int, int> pf;
        stringstream ss(input);
        int num, power;
        int prod = 1;
        while (ss >> num >> power) {
            prod *= pow(num, power);
        }
        int temp = prod - 1;
        for (int i = 0; i < primes.size(); i++) {
            int ctr = 0;
            while (temp % primes[i] == 0) {
                ctr++;
                temp /= primes[i];
            }
            if (ctr > 0) {
                pf[primes[i]] = ctr;
            }

        }
        if (temp != 1) {
            pf[temp] = 1;
        }
        int ctr = 0;
        // reverse(map);
        // for (map<int, int>::iterator itr = pf.begin(); itr != pf.end(); itr++) {
        for (map<int, int>::reverse_iterator itr = pf.rbegin(); itr != pf.rend(); itr++) {
            if (ctr > 0) {
                printf(" ");
                fprintf(pFile, " ");
            }
            printf("%d %d", itr->first, itr->second);
            fprintf(pFile,"%d %d", itr->first, itr->second);
            ctr++;
        }
        printf("\n");
        fprintf(pFile, "\n");
    }
	fclose(pFile);
	return 0;
}