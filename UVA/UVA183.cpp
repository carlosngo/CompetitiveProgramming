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


string input;

vi DToB(int rows, int cols) {
    vi d;
    printf("String is: %s, Rows = %d, Cols = %d\n", input.c_str(), rows, cols);
    if (rows == 0 || cols == 0) return vi();
    if (input[0] == '1') {
        printf("Pushed 1\n");
        input.erase(input.begin());
        return vi(rows * cols, 1);
    }
    if (input[0] == '0') {
        printf("Pushed 0\n");
        input.erase(input.begin());
        return vi(rows * cols, 0);
    }
    if (input[0] == 'D') {
        input.erase(input.begin());
        vi uLeft, uRight, lLeft, lRight;
        int ulRow, ulCol, urRow, urCol, llRow, llCol, lrRow = rows / 2, lrCol = cols / 2;
        lRight = vi();

        if (rows % 2 && cols % 2) {
            uLeft = vi();
            ulRow = rows / 2 + 1;
            ulCol = cols / 2 + 1;
            uRight = vi();
            urRow = rows / 2 + 1;
            urCol = cols / 2;
            lLeft = vi();
            llRow = rows / 2;
            llCol = cols / 2 + 1;
        } else if (rows % 2 || cols % 2) {
            if (rows % 2) {
                uLeft = vi();
                ulRow = rows / 2 + 1;
                ulCol = cols / 2;
                uRight = vi();
                urRow = rows / 2 + 1;
                urCol = cols / 2;
                lLeft = vi();
                llRow = rows / 2;
                llCol = cols / 2;
            } else if (cols % 2) {
                uLeft = vi();
                ulRow = rows / 2;
                ulCol = cols / 2 + 1;
                uRight = vi();
                urRow = rows / 2;
                urCol = cols / 2;
                lLeft = vi();
                llRow = rows / 2;
                llCol = cols / 2 + 1;
            }
        } else {
            uLeft = vi();
            ulRow = rows / 2;
            ulCol = cols / 2;
            urRow = rows / 2;
            urCol = cols / 2;
            llRow = rows / 2;
            llCol = cols / 2;
            uRight = vi();
            lLeft = vi();
        }
        
        printf("Before recursive:\nRows:ul=%d, ur=%d, ll=%d, lr=%d\nColumns:ul=%d, ur=%d, ll=%d, lr=%d",ulRow,urRow,llRow,lrRow, ulCol, urCol, llCol, lrCol);
        // for (int i = 0; i < ulRow; i++) {
        //     for (int j = 0; j < ulCol; j++) {
                printf("Moving on upper left with %d rows and %d cols\n", ulRow, ulCol);
                vi next = DToB(ulRow, ulCol);
                for (int k = 0; k < next.size(); k++) 
                    d.PB(next[k]);
            // }
        // }
        // for (int i = 0; i < urRow; i++) {
            // for (int j = 0; j < urCol; j++) {
                printf("Moving on upper right with %d rows and %d cols\n", urRow, urCol);
                 next = DToB(urRow, urCol);
                for (int k = 0; k < next.size(); k++) 
                    d.PB(next[k]);
        //     }
        // }
        // for (int i = 0; i < llRow; i++) {
        //     for (int j = 0; j < llCol; j++) {
                printf("Moving on lower left %d rows and %d cols\n", llRow, llCol);
                 next = DToB(llRow, llCol);
                for (int k = 0; k < next.size(); k++) 
                    d.PB(next[k]);
        //     }
        // }
        // for (int i = 0; i < lrRow; i++) {
        //     for (int j = 0; j < lrCol; j++) {
                printf("Moving on lower right %d rows and %d cols\n", lrRow, lrCol);
                 next = DToB(lrRow, lrCol);
                for (int k = 0; k < next.size(); k++) 
                    d.PB(next[k]);
        //     }
        // }
        printf("D Contents:\n");
        for (int i = 0; i < d.size(); i++) printf("%d ", d[i]);
        printf("\n");
        return d;
    }
}

string BToD(vvi grid) {
    bool one = true, zero = true;
    
    if (grid.empty()) return "";
    // printf("Grid Contents:\n");
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            // printf("%d ", grid[i][j]);
            if (grid[i][j] == 0) one = false;
            if (grid[i][j] == 1) zero = false;
        }
        // printf("\n");
    }
    
    if (one) {
        // printf("One\n");
        return "1";
    }
    else if (zero) {
        // printf("Zero\n");
        return "0";
    }
    else {
        vvi uLeft, uRight, lLeft, lRight;
        int rows = grid.size(), cols = grid[0].size();
        lRight = vvi(rows / 2, vi(cols / 2));
        int row, col;
        if (rows % 2 && cols % 2) {
            uLeft = vvi(rows / 2 + 1, vi(cols / 2 + 1));
            uRight = vvi(rows / 2 + 1, vi(cols / 2));
            lLeft = vvi (rows / 2, vi(cols / 2 + 1));
            row = 0, col = 0;
            for (int i = rows / 2 + 1; i < rows; i++) {
                col = 0;
                for (int j = cols / 2 + 1; j < cols; j++) {
                    lRight[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
            row = 0, col = 0;
            for (int i = 0; i < uRight.size(); i++) {
                col = 0;
                for (int j = cols / 2 + 1; j < cols; j++) {
                    uRight[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
            row = 0, col = 0;
            
            for (int i = rows / 2 + 1; i < rows; i++) {
                col = 0;
                for (int j = 0; j < cols / 2 + 1; j++) {
                    lLeft[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
        } else if (rows % 2 || cols % 2) {
            if (rows % 2) {
                uRight = vvi(rows / 2 + 1, vi(cols / 2));
                uLeft = vvi(rows / 2 + 1, vi(cols / 2));
                lLeft = vvi(rows / 2, vi(cols / 2));
                row = 0, col = 0;
                for (int i = rows / 2 + 1; i < rows; i++) {
                    col = 0;
                    for (int j = cols / 2; j < cols; j++) {
                        lRight[row][col] = grid[i][j];
                        col++;
                    }
                    row++;
                }
                // printf("Done initializing lRight\n");

                row = 0, col = 0;
                // printf("Upper Right Grid Contents:\n");
                for (int i = 0; i < rows / 2 + 1; i++) {
                    col = 0;
                    for (int j = cols / 2; j < cols; j++) {
                        uRight[row][col] = grid[i][j];
                        // printf("%d ", uRight[row][col]);
                        col++;
                    }
                    // printf("\n");
                    row++;
                }
                // printf("Done initializing uRight\n");
                row = 0, col = 0;
                for (int i = rows / 2 + 1; i < rows; i++) {
                    col = 0;
                    for (int j = 0; j < cols / 2; j++) {
                        lLeft[row][col] = grid[i][j];
                        col++;
                    }
                    row++;
                }
                // printf("Done initializing lLeft\n");
            } else if (cols % 2) {
                lLeft = vvi(rows / 2, vi(cols / 2 + 1));
                uLeft = vvi(rows / 2, vi(cols / 2 + 1));
                uRight = vvi(rows / 2, vi(cols / 2));
                row = 0;
                for (int i = rows / 2; i < rows; i++) {
                    col = 0;
                    for (int j = cols / 2 + 1; j < cols; j++) {
                        lRight[row][col] = grid[i][j];
                        col++;
                    }
                    row++;
                }
                row = 0, col = 0;
                for (int i = 0; i < uRight.size(); i++) {
                    col = 0;
                    for (int j = cols / 2 + 1; j < cols; j++) {
                        uRight[row][col] = grid[i][j];
                        col++;
                    }
                    row++;
                }
                row = 0, col = 0;
                for (int i = rows / 2; i < rows; i++) {
                    col = 0;
                    for (int j = 0; j < cols / 2 + 1; j++) {
                        lLeft[row][col] = grid[i][j];
                        col++;
                    }
                    row++;
                }
            }
        } else {
            uRight = vvi(rows / 2, vi(cols / 2));
            uLeft = vvi(rows / 2, vi(cols / 2));
            lLeft = vvi(rows / 2, vi(cols / 2));
            row = 0, col = 0;
            for (int i = rows / 2; i < rows; i++) {
                col = 0;
                for (int j = cols / 2; j < cols; j++) {
                    lRight[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
            row = 0, col = 0;
            for (int i = 0; i < uRight.size(); i++) {
                col = 0;
                for (int j = cols / 2; j < cols; j++) {
                    uRight[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
            row = 0, col = 0;
            for (int i = rows / 2; i < rows; i++) {
                col = 0;
                for (int j = 0; j < cols / 2; j++) {
                    lLeft[row][col] = grid[i][j];
                    col++;
                }
                row++;
            }
        }
        row = 0, col = 0;
        for (int i = 0; i < uLeft.size(); i++) {
            col = 0;
            for (int j = 0; j < uLeft[0].size(); j++) {
                uLeft[row][col] = grid[i][j];
                col++;
            }
            row++;
        }
        // printf("Done with the body, moving to next.");
        // printf("Upper Right Grid Contents:\n");
        
        return "D" + BToD(uLeft) + BToD(uRight) + BToD(lLeft) + BToD(lRight);
    }
}


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    char dummy;
    int n, m;
    while (getline(cin, input) && input != "#") {
        char type;
        stringstream ss(input);
        ss >> type >> n >> m;
        
        
        if (type == 'B') {
            vvi grid = vvi(n, vi(m));
            int i = 0;
            int maxCols = 0;
            int rows = 1;
            while (i < n) {
                int j = 0;
                char line[m];
                int cols = 0;
                while (j < m) {
                    char ch;
                    SCC(ch);
                    cols++;
                    if (ch != '\n') {
                        line[j] = ch;
                        if (line[j] == '0') grid[i][j] = 0;
                        else if (line[j] == '1') grid[i][j] = 1;
                        else grid[i][j] = -1;
                        j++;
                        
                    } else {
                        rows++;
                    }
                }
                maxCols = max(maxCols, cols);
                i++;
            }
            // for (int i = 0; i < n; i++) {
            //     char line[m];
            //     // cin >> input;
            //     for (int j = 0; j < m; j++) {
            //         SCC(line[j]);
                    
            //         if (line[j] == '0') grid[i][j] = 0;
            //         else if (line[j] == '1') grid[i][j] = 1;
            //         else grid[i][j] = -1;
            //     }
            // }
            // printf("Grid COntents:\n");
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         printf("%d ", grid[i][j]);
            //     }
            //     printf("\n");
            // }
            fprintf(stdout, "D%4d%4d\n", type, n, m);
            fprintf(pFile, "D%4d%4d\n", type, n, m);
            string ans = BToD(grid);
            for (i = 0; i < rows; i++) {
                for (int j = 0; j < maxCols; j++) {
                    fprintf(stdout, "%c", ans[i * maxCols + j]);
                    fprintf(pFile, "%c", ans[i * maxCols + j]);
                }
                fprintf(stdout, "\n");
                fprintf(pFile, "\n");
            }
        } else {
            // getline(cin, input);
            getline(cin, input);
            vi ans = DToB(n, m);
            fprintf(stdout, "B%4d%4d\n", type, n, m);
            fprintf(pFile, "B%4d%4d\n", type, n, m);
            for (int i = 0; i < ans.size(); i++) {
                fprintf(stdout, "%d", ans[i]);
                fprintf(pFile, "%d", ans[i]);
            }
            fprintf(stdout, "\n");
            fprintf(pFile, "\n");
        }
    }
	fclose(pFile);
	return 0;
}