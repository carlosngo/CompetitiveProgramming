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

class Light {
    public:
        double pos;
        int green;
        int yellow;
        int red;
        Light(double _pos, int _green, int _yellow, int _red) {
            pos = _pos;
            green = _green;
            yellow = _yellow;
            red = _red;
        }
};

bool isGreen(Light l, int speed) {
    double time = fmod(l.pos * 3600 / speed, l.green + l.yellow + l.red);
    return time <= l.green + l.yellow;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    int ctr = 1;
    while (SCD(n), n != -1) {
        vector<Light> arr;
        FOR (i, 0, n, 1) {
            double pos;
            int green, yellow, red;
            SCLF(pos); SCD(green); SCD(yellow); SCD(red);
            arr.PB(Light(pos, green, yellow, red));
        }
        vi ans;
        for (int speed = 30; speed <= 60; speed++) {
            bool valid = true;
            for (int i = 0; i < n && valid; i++) {
                valid = isGreen(arr[i], speed);
            }
            if (valid) {
                // printf("Pushing %d\n", speed);
                ans.PB(speed);
            }
        }
        fprintf(stdout, "Case %d: ", ctr);
        fprintf(pFile, "Case %d: ", ctr);
        ctr++;
        int cnt = 0;
        if (ans.empty()) {
            fprintf(stdout, "No acceptable speeds.\n");
            fprintf(pFile, "No acceptable speeds.\n");
        } else {
            for (int i = 0; i < ans.size(); i++) {
                int start = ans[i];
                int end = -1;
                int j;
                for (j = i + 1; j < ans.size() && ans[j] - ans[j - 1] == 1; j++) {
                    end = ans[j];    
                    i = j;
                }
                if (cnt) {
                    fprintf(stdout, ", ");
                    // fprintf(pFile, ", ");
                }
                fprintf(stdout, "%d", start);
                // fprintf(pFile, "%d", start);
                if (end != -1) {
                    fprintf(stdout, "-%d", end);
                    // fprintf(pFile, "-%d", end);
                }
                cnt++;
            }
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
    }
	fclose(pFile);
	return 0;
}