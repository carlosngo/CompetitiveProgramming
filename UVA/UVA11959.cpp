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

int up[6] = {2, 4, 1, 3, 0, 5};
int ri[6] = {0, 1, 3, 4, 5, 2};
int si[6] = {5, 3, 2, 0, 4, 1};
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    while (t--) {
        string d1, d2;
        cin >> d1 >> d2;
        bool ans = false;
        for (int i = 0; i < 4 && !ans; i++) {
            string temp = d1;
            bool equal = true;
            for (int j = 0; j < 6 && !ans; j++) {
                d1[j] = temp[up[j]];
                if (d1[j] != d2[j]) equal = false;
            }
            if (equal) ans = true;

            for (int j = 0; j < 4 && !ans; j++) {
                temp = d1;
                equal = true;
                for (int k = 0; k < 6 && !ans; k++) {
                    d1[k] = temp[ri[k]];
                    if (d1[k] != d2[k]) equal = false;
                }   
                if (equal) ans = true;

                for (int k = 0; k < 4 && !ans; k++) {
                    temp = d1;
                    equal = true;
                    for (int l = 0; l < 6 && !ans; l++) {
                        d1[l] = temp[si[l]];
                        if (d1[l] != d2[l]) equal = false;
                    }   
                    if (equal) ans = true;
                }

            }
        }
        if (!ans) {
            fprintf(stdout, "Not Equal\n");
            fprintf(pFile, "Not Equal\n");
        } else {
            fprintf(stdout, "Equal\n");
            fprintf(pFile, "Equal\n");
        }
    }
	fclose(pFile);
	return 0;
}