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
    int cases;
    SCD(cases);
    int ctr = 1;
    while (cases--) {
        map<string, int> dict;
        string due;
        int subjs;
        SCD(subjs);
        while (subjs--) {
            // char *subj;
            string subj;
            int days;
            // fscanf(stdin, "%s %d", subj, &days);
            cin >> subj >> days;
            dict[subj] = days;
        }
        int dueDays;
        SCD(dueDays);
        cin >> due;
        /*if (dict.find(due) == dict.end() || dict[due] > dueDays + 5) {
            fprintf(stdout, "Case %d: Do your own homework!\n", ctr);
            // fprintf(pFile, "Case %d: Do your own homework!\n", ctr);
        } else if (dict[due] > dueDays && dict[due] <= dueDays + 5) {
            fprintf(stdout, "Case %d: Late\n", ctr);
            // fprintf(pFile, "Case %d: Late\n", ctr);
        } else if (dict[due] <= dueDays) {
            fprintf(stdout, "Case %d: Yesss\n", ctr);
            // fprintf(pFile, "Case %d: Yesss\n", ctr);
        }*/
        if (dict[due] && dict[due] <= dueDays)
            fprintf (stdout,"Case %d: Yesss\n",ctr);
        else if (dict[due] && dict[due] <= dueDays+5)
            fprintf (stdout,"Case %d, Late\n", ctr);
        else
            fprintf (stdout,"Case %d: Do your own homework!\n",ctr);
        ctr++;
    }
	fclose(pFile);
	return 0;
}