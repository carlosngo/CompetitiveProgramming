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

bool compare(const pair<ii, string> a, const pair<ii, string> b) {
    if (a.first.first < b.first.first) {
        return true;
    } else if (a.first.first == b.first.first) {
        if (a.first.second > b.first.second) {
            return true;
        } else if (a.first.second == b.first.second) {
            return a.second.compare(b.second) > 0;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    FOR (i, 1, t + 1, 1) {
        vector<string> atk;
        vector<string> def;
        pair<ii, string> players[10];
        FOR (j, 0, 10, 1) {
            string name;
            int atkVal, defVal;
            cin >> name >> atkVal >> defVal;
            players[j] = pair<ii, string>(ii(atkVal, defVal), name);
        }
        sort(players, players + 10, compare);
        for (int j = 0; j < 10; j++) {
            printf("%s %d %d\n", players[j].second.c_str(), players[j].first.first, players[j].first.second);
        }
        for (int j = 9; j >= 5; j--) {
            atk.PB(players[j].second);
        }
        for (int j = 4; j >= 0; j--) {
            def.PB(players[j].second);
        }
        sort(atk.begin(), atk.end());
        sort(def.begin(), def.end());

        fprintf(stdout, "Case %d:\n(", i);
        fprintf(pFile, "Case %d:\n(", i);
        FOR (j, 0, 5, 1) {
            if (j) {
                fprintf(stdout, ", ");
                fprintf(pFile, ", ");
            }
            fprintf(stdout, "%s", atk[j].c_str());
            fprintf(pFile, "%s", atk[j].c_str());
        }
        fprintf(stdout, ")\n(");
        fprintf(pFile, ")\n(");
        FOR (j, 0, 5, 1) {
            if (j) {
                fprintf(stdout, ", ");
                fprintf(pFile, ", ");
            }
            fprintf(stdout, "%s", def[j].c_str());
            fprintf(pFile, "%s", def[j].c_str());
        }
        fprintf(stdout, ")\n");
        fprintf(pFile, ")\n");
    }
	fclose(pFile);
	return 0;
}