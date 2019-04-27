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

int totalCustomers[20];
int commonCustomers[20];
vector<set<int> > commonTowers;
bitset<20> bs;
vi taken;
int n, p, m, t;
int ans;
vi reco;

int backtrack(int tower, int cust) {
    if (taken.size() == p) {
        // printf("Reached the number of towers. Number of Customers is %d\n", cust);
        if (cust > ans) {
            ans = cust;
            reco = taken;
        }
    } else {
        // printf("At tower %d: %d customers\n", tower, cust);
        for (int i = tower; i < n; i++) {
            // printf("Checking i = %d\n", i);
            int newCust = cust + totalCustomers[i];
            bs.reset();
            for (int j = 0; j < m; j++) { // for each common towers
                // printf("Checking j = %d\n", j);
                for (int k = 0; k < taken.size() && !bs.test(j); k++) { // for each previous taken towers
                    // printf("Checking k = %d\n", k);
                    if (commonTowers[j].find(i) != commonTowers[j].end() && commonTowers[j].find(taken[k]) != commonTowers[j].end()) {
                        // printf("Found common spot with %d with %d customers\n", k, commonCustomers[j]);
                        bs.set(j);
                        newCust -= commonCustomers[j];
                    }
                }
                // bs.reset(j);
            }
            taken.PB(i);
            backtrack(i + 1, newCust);
            taken.pop_back();
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int ctr = 1;
    while (fscanf(stdin, "%d %d", &n, &p), n != 0 || p != 0) {
        taken.clear();
        reco.clear();
        ans = INT_MIN;
        commonTowers.clear();

        FOR (i, 0, n, 1) SCD(totalCustomers[i]);
        SCD(m);

        FOR (i, 0, m, 1) {
            set<int> s;
            int num;
            SCD(num);
            while (num--) {
                int cust;
                SCD(cust);
                cust--;
                s.insert(cust);
            }
            commonTowers.PB(s);
            SCD(commonCustomers[i]);
        }
        backtrack(0, 0);
        fprintf(stdout, "Case Number %2d\nNumber of Customers: %d\nLocations recommended: ", ctr, ans);
        fprintf(pFile, "Case Number %2d\nNumber of Customers: %d\nLocations recommended: ", ctr, ans);
        FOR (i, 0, reco.size(), 1) {
            if (i > 0) {
                fprintf(stdout, " ");
                fprintf(pFile, " ");
            }
            fprintf(stdout, "%d", reco[i] + 1);
            fprintf(pFile, "%d", reco[i] + 1);
        }
        fprintf(stdout, "\n\n");
        fprintf(pFile, "\n\n");
        ctr++;
    }
	fclose(pFile);
	return 0;
}