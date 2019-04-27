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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    
    int sets;
    SCD(sets);
    FOR (i, 0, sets, 1) {
        if (i > 0) {
            printf("\n");
            fprintf(pFile, "\n");
        }
        map<int, int> m;
        int nums;
        SCD(nums);
        string input;
        FOR (j, 0, nums, 1) {
            cin >> input;
            int standard = 0;
            FOR (k, 0, input.length(), 1) {
                char ch = input[k];
                if (isalpha(ch)) {
                    int digit = 0;
                    switch (ch) {
                        case 'A':
                        case 'B':
                        case 'C':
                            digit = 2;
                            break;
                        case 'D':
                        case 'E':
                        case 'F':
                            digit = 3;
                            break;
                        case 'G':
                        case 'H':
                        case 'I':
                            digit = 4;
                            break;
                        case 'J':
                        case 'K':
                        case 'L':
                            digit = 5;
                            break;
                        case 'M':
                        case 'N':
                        case 'O':
                            digit = 6;
                            break;
                        case 'P':
                        case 'R':
                        case 'S':
                            digit = 7;
                            break;
                        case 'T':
                        case 'U':
                        case 'V':
                            digit = 8;
                            break;
                        case 'W':
                        case 'X':
                        case 'Y':
                            digit = 9;
                            break;
                    }
                    standard = standard * 10 + digit;
                } else if (ch != '-') {
                    standard = standard * 10 + (ch - '0');
                }
            }
            if (m.find(standard) != m.end()) {
                m[standard]++;
            } else {
                m[standard] = 1;
            }
        }
        
        vi ans;
        for (map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second != 1) {
                ans.PB(itr->first);
            }
        }
        sort(all(ans));
        if (ans.empty()) {
            printf("No duplicates.\n");
            fprintf(pFile, "No duplicates.\n");
        } else {
            for (int i = 0; i < ans.size(); i++) {
                int number = ans[i];
                printf("%03d-%04d %d\n", number / 10000, number % 10000, m[number]);
                fprintf(pFile, "%03d-%04d %d\n", number / 10000, number % 10000, m[number]);
            }
        }
    }
	fclose(pFile);
	return 0;
}