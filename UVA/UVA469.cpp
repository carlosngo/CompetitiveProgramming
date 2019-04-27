#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define PB push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

int main() {
	FILE *pFile = fopen("out.txt","w");
    int nCtr;
	scanf("%d\n\n", &nCtr);
	for (int x = 0; x < nCtr; x++) {
        if (x > 0) {
            printf("\n");
            fprintf(pFile, "\n");
        }
		string line;
		vector<string> grid;
		while (getline(cin, line), line[0] == 'W' || line[0] == 'L') {
			grid.push_back(line);
		}
        int rows = grid.size();
        int cols = grid[0].length();
        do {
            vector<string> dummy = grid;
            const char * str = line.c_str();
            int r, c;
            sscanf(str, "%d %d", &r, &c);
            r--; c--;
            int area = 1;
            dummy[r][c] = 'L';
            queue<int> q;
            q.push(r * cols + c);
            while (!q.empty()) {
                int dex = q.front(); q.pop();
                r = dex / cols;
                c = dex % cols;
                int cOff[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int rOff[] = {-1, 1, 0, 1, -1, -1, 1, 0};
                for (int i = 0; i < 8; i++) {
                    int newR = r + rOff[i];
                    int newC = c + cOff[i]; 
                    if (newR >= 0 && newR < rows && newC >= 0 
                        && newC < cols && dummy[newR][newC] == 'W') {
                        area++;
                        q.push(newR * cols + newC);
                        dummy[newR][newC] = 'L';
                    }
                }
            }
            printf("%d\n", area);
            fprintf(pFile, "%d\n", area);
        } while(getline(cin, line), line != "");
	}
	fclose(pFile);
	return 0;
}
	