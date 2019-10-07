#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;
typedef pair<int, iiii> iiiii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int UNVISITED = -1;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll ans[10][10][10][10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int m = 0; m < 10; m++) {
                        if (i >= 2 && j >= 2 && k >= 2 && l >= 2 && m >= 2) ans[i][j][k][l][m] = -1;
                        ans[i][j][k][l][m] = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                for (int l = 1; l < 10; l++) {
                    for (int m = 1; m < 10; m++) {
                        if (i == 1 && j == 1 && k == 1 && l == 1 && m == 1) {
                            ans[i][j][k][l][m] = -1;
                        } else if (ans[i][j][k][l][m] != -1) {
                            // printf("Processing i = %d j = %d k = %d l = %d m = %d\n", i, j, k, l, m);
                            int rooms[5] = {i, j, k, l, m};
                            bool valid = true;
                            int ctr = 0;
                            vector<iiiii> tuples;
                            vi values;
                            while (valid) {
                                bool found = false;
                                vi indices;
                                for (int n = 0; n < 5 && !found; n++) {
                                    if (rooms[n] == 0) found = true;
                                    else if (rooms[n] >= 2) indices.PB(n); 
                                    // printf("%d ", rooms[n]);
                                }
                                //  printf("\n");
                                if (found) break;
                                tuples.PB(iiiii(rooms[0], iiii(rooms[1], iii(rooms[2], ii(rooms[3], rooms[4])))));
                                values.PB(ans[rooms[0]][rooms[1]][rooms[2]][rooms[3]][rooms[4]]);
                                ans[rooms[0]][rooms[1]][rooms[2]][rooms[3]][rooms[4]] = -2; // VISITED
                                while (!indices.empty()) {
                                    int top = indices.back();
                                    indices.pop_back();
                                    rooms[top] -= 2;
                                    int left = top - 1;
                                    int right = top + 1;
                                    if (left == -1) left = 4;
                                    if (right == 5) right = 0;
                                    rooms[left]++;
                                    rooms[right]++;
                                }
                                ctr++;
                                if (ans[rooms[0]][rooms[1]][rooms[2]][rooms[3]][rooms[4]] == -1 || ans[rooms[0]][rooms[1]][rooms[2]][rooms[3]][rooms[4]] == -2) {
                                    // printf("The following tuples loop:\n");
                                    while (!tuples.empty()) {
                                        iiiii top = tuples.back();
                                        tuples.pop_back();
                                        ans[top.first][top.second.first][top.second.second.first][top.second.second.second.first][top.second.second.second.second] = -1;
                                        // printf("%d %d %d %d %d\n", top.first,top.second.first,top.second.second.first,top.second.second.second.first,top.second.second.second.second);
                                    }
                                    valid = false;
                                    break;
                                } 
                            }
                            // if (i == 1 && j == 1 && k == 2 && l == 1 && m == 2) {
                            //     printf("reached 11212 ctr = %d\n" , ctr);
                            // }
                            if (!valid) ans[i][j][k][l][m] = -1;
                            else {
                                while (!tuples.empty()) {
                                    iiiii top = tuples.back();
                                    tuples.pop_back();
                                    int val = values.back();
                                    values.pop_back();
                                    ans[top.first][top.second.first][top.second.second.first][top.second.second.second.first][top.second.second.second.second] = val;
                                    // printf("%d %d %d %d %d\n", top.first,top.second.first,top.second.second.first,top.second.second.second.first,top.second.second.second.second);
                                }
                                ans[i][j][k][l][m] = ctr;
                            }
                        }
                    }
                }
            }
        }
    }
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         for (int k = 0; k < 10; k++) {
    //             for (int l = 0; l < 10; l++) {
    //                 for (int m = 0; m < 10; m++) {
    //                     if (ans[i][j][k][l][m] == -2) printf("%d %d %d %d %d\n", i, j, k, l, m);
    //                 }
    //             }
    //         }
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << ans[a][b][c][d][e] << '\n';
    }
	return 0;
}