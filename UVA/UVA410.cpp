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
    int c, s;
    int ctr = 1;
    while (SCD(c) == 1) {
        SCD(s);
        ii chambs[c];
        double avg;
        int specis[2 * c];
        int sum = 0;
        FOR (i, 0, s, 1) {
            SCD(specis[i]);
            sum += specis[i];
        }
        avg = sum * 1.0 / c;
        if (s > c) {
            FOR (i, s, 2 * c, 1) {
                specis[i] = 0;
            }
            sort(specis, specis + 2 * c);
            
            for (int i = 0; i < c; i++) {
                // printf("%d ",specis[i]);
                chambs[i].first = specis[i];
                chambs[i].second = specis[2 * c - i - 1];  
            }
        } else {
            for (int i = 0; i < s; i++) {
                chambs[i].first = specis[i];
            }
        }
        fprintf(stdout, "Set #%d\n", ctr);
        // fprintf(pFile, "Set #%d\n", ctr);
        double imb = 0;
        
        FOR (i, 0, sizeof(chambs) / sizeof(ii), 1) {
            sum = 0;
            fprintf(stdout, " %d:", i);
            // fprintf(pFile, " %d:", i);
            if (chambs[i].first != 0) {
                fprintf(stdout, " %d", chambs[i].first);
                // fprintf(pFile, " %d", chambs[i].first);
                sum += chambs[i].first;
            } 
            if (chambs[i].second != 0) {
                fprintf(stdout, " %d", chambs[i].second);
                // fprintf(pFile, " %d", chambs[i].second);
                sum += chambs[i].second;
            }  
            // printf("Sum = %d, Avg = %lf", sum, avg);
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
            imb += fabs(sum - avg);
        }
        fprintf(stdout, "IMBALANCE = %.5lf\n\n", imb);
        // fprintf(pFile, "IMBALANCE = %.5lf\n\n", imb);
        ctr++;
    }
	fclose(pFile);
	return 0;
}