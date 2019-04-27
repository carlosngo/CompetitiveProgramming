#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;


int main() {
	FILE *pFile = fopen("out.txt","w");
    int n;
    scanf("%d", &n);
    vvi memo;
    memo.assign(n, vi(n));
    for (int i = 0; i < memo.size(); i++)
        for( int j = 0; j < n; j++)
            memo[i][j] = 0; 
    int grid[n][n];
    int ans = -128 * 100 * 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
            if (i == 0 && j == 0) {
                memo[0][0] = grid[0][0];
                ans = memo[0][0];
            } else {
                if (j > 0 && i > 0) {
                    memo[i][j] = (memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1]) + grid[i][j];
                } else if (j == 0) {
                    memo[i][j] = memo[i - 1][j] + grid[i][j];
                } else if (i == 0) {
                    memo[i][j] = memo[i][j - 1] + grid[i][j];
                }

            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    int rect = memo[k][l];
                    if (i == 0 && j == 0) {;
                    } else {
                        if (j > 0 && i > 0) {
                            rect = rect - memo[i - 1][l] - memo[k][j - 1] + memo[i - 1][j - 1]; 
                        } else if (j == 0) {
                            rect = rect - memo[i - 1][l];
                        } else if (i == 0) {
                            rect = rect - memo[k][j - 1];
                        }

                    }
                    ans = max(ans, rect);
                }
            }
        }
    }
    printf("%d\n", ans);
    fprintf(pFile ,"%d\n", ans);
	fclose(pFile);
	return 0;
}