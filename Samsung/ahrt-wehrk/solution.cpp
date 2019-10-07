#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

class Answer {
    public:
    int ans[5][17][17][17][17][17];
};

int main() {
    Answer* a = new Answer();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 17; j++) {
            for (int k = 0; k < 17; k++) {
                for (int x = 0; x < 17; x++) {
                    for (int y = 0; y < 17; y++) {
                        for (int z = 0; z < 17; z++) {
                            a->ans[i][j][k][x][y][z] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int n = 1; n < 5; n++) {
        int ans = 0;
        for(int i = 0; i < (1 << (n * n)); i++) {

            int grid[n][n];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    grid[j][k] = 0;
                }
            }
            for (int j = 0; j < n * n; j++) {
                if ((i & (1 << j)) != 0) grid[j / n][j % n] = 1;
            }
            int arr[5] = {0};
            for (int j = 0; j < 5; j++) arr[j] = 0;
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
                        if (ctr <= 4) arr[ctr]++;
                    }
                    
                }
            }
            int v = arr[0];
            int w = arr[1];
            int x = arr[2];
            int y = arr[3];
            int z = arr[4];
            a->ans[n][v][w][x][y][z]++;
        }
    }
    int t;
    SCD(t);
    while (t--) {
        int n;
        SCD(n);
        int c0, c1, c2, c3, c4;
        SCD(c0);
        SCD(c1);
        SCD(c2); 
        SCD(c3);
        SCD(c4);
        fprintf(stdout, "%d\n", a->ans[n][c0][c1][c2][c3][c4]);
    }
	
	return 0;
}
