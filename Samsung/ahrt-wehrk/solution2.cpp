#include <bits/stdc++.h>

using namespace std;

#define SCD(t) fscanf(stdin, "%d",&t)

const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    int n;
    int t;
    // SCD(t);
    // while (t--) {
        SCD(n);
        int given[5];
        for (int i = 0; i < 5; i++) SCD(given[i]);
        int ans = 0;
        // for(int i = 0; i < (1 << (n * n)); i++) {
            int i = (1 << (n * n)) - 1;
            int grid[n][n];
            memset(grid, 0, sizeof(grid));
            for (int j = 0; j < n * n; j++) {
                if ((i & (1 << j)) != 0) grid[j / n][j % n] = 1;
            }

            int arr[5];
            memset(arr, 0, sizeof(arr));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int ctr = 0;
                    if (grid[j][k]) {
                        for (int l = 0; l < 4; l++) {
                            int nextR = j + fx[l][0];
                            int nextC = k + fx[l][1];
                            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n) {
                                if (grid[nextR][nextC]) ctr++;
                            }
                        }
                        printf("ctr = %d\n", ctr);
                        if (ctr <= 4) arr[ctr]++;
                    }
                    
                }
            }
            bool valid = true;
            for (int j = 0; j < 5; j++) {
                printf("arr[j] = %d given[j] = %d\n", arr[j], given[j]);
                if (arr[j] != given[j]) valid = false;
            }
            // if (valid) ans++;
        // }
        // fprintf(stdout, "%d\n", ans);
    // }
	
	return 0;
}