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
    string line;
    while (cin >> line, line != "#") {
        vvi adjList;
        adjList.assign(26, vi());
        bitset<26> used;
        char arr[8];
        char ans[8];
        int arrInd = 0;
        int mini = INT_MAX;
        for (int i = 0; i < line.length(); i++) {
            int node = line[i] - 'A';
            if (!used.test(node)) {
                used.set(node);
                arr[arrInd++] = line[i];
            }
            int j = i + 2;
            while (line[j] != ';' && j < line.length()) {
                int neigh = line[j] - 'A';
                adjList[node].PB(neigh);
                if (!used.test(neigh)) {
                    arr[arrInd++] = line[j];
                    used.set(neigh);
                }
                j++;
            }
            i = j;
        }
        sort(arr, arr + arrInd);
        // for (int i = 0; i < arrInd; i++) {
        //     printf("%c ", arr[i]);
        // }
        // printf("\n");
        do {
            int maxBand = 0;
            for (int i = 0; i < arrInd; i++) {
                int maxi = 1;
                int node = arr[i] - 'A';
                for (int j = 0; j < adjList[node].size(); j++) {
                    char neigh = adjList[node][j] + 'A';
                    int ind = strchr(arr, neigh) - arr;
                    maxi = max(maxi, abs(ind - i));
                }
                // printf("For i = %d, maxi = %d\n", i, maxi);
                maxBand = max(maxBand, maxi);
            }
            if (maxBand < mini) {
                mini = maxBand;
                copy(arr, arr + arrInd, ans);
            }
        } while (next_permutation(arr, arr + arrInd));

        for (int i = 0; i < arrInd; i++) {
            fprintf(stdout, "%c ", ans[i]);
            fprintf(pFile, "%c ", ans[i]);
        }
        fprintf(stdout, "-> %d\n", mini);
        fprintf(pFile, "-> %d\n", mini);
    }
	fclose(pFile);
	return 0;
}