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
const int MAX_N = 4000;


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
	bitset<MAX_N> sieve;
	vi primes;
	for (ll i = 2; i < MAX_N; i++) {
		if (!sieve.test(i)) {
			primes.PB(i);
			for (ll j = i * i; j < MAX_N; j += i) {
				sieve.set(j);
			}
		}
	}	
	int cases;
	SCD(cases);
	while (cases--) {
		int a, c;
		SCD(a); SCD(c);
		map<int, int> cFacts;
		map<int, int> aFacts;
		bool valid = true;
		int temp = a;
		for (int i = 0; i < primes.size() && primes[i] <= sqrt(temp); i++) {
			int count = 0;
			while (temp % primes[i] == 0) {
				count++;
				temp /= primes[i];
			}
			aFacts[primes[i]] = count;
		}
		if (temp != 1) aFacts[temp] = 1;
		temp = c;
		for (int i = 0; i < primes.size() && primes[i] <= sqrt(temp); i++) {
			int count = 0;
			while (temp % primes[i] == 0) {
				count++;
				temp /= primes[i];
			}
			cFacts[primes[i]] = count;
		}
		if (temp != 1) cFacts[temp] = 1;
		int ans = 1;
		for (map<int, int>::iterator itr = cFacts.begin(); itr != cFacts.end(); itr++) {
			if (aFacts[itr->first] < itr->second) aFacts[itr->first] = -(itr->second);
			else if (aFacts[itr->first] == itr->second) aFacts[itr->first] = 0;
		}

		for (map<int, int>::iterator itr = aFacts.begin(); itr != aFacts.end() && valid; itr++) {
			if (itr->second <= 0) ans *= pow(itr->first, -(itr->second));
			else valid = false;
		}
		// printf("For input a=%d c=%d: ", a, c);
		if (!valid) {
			fprintf(stdout, "NO SOLUTION\n");
			// fprintf(pFile, "NO SOLUTION\n");
		} else {
			fprintf(stdout, "%d\n", ans);
			// fprintf(pFile, "%d\n", ans);
		}
	}
	fclose(pFile);
	return 0;
}