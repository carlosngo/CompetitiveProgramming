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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// FILE *pFile = fopen("out.txt","w");
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
    int perms[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 297, 319, 339, 360, 382, 405, 426, 448, 468, 489, 511, 534, 555, 577, 597, 618, 640, 663, 684, 706, 726, 744, 763, 783, 798, 820, 834, 852, 868, 888, 900, 925, 936, 951, 961, 978, 984, 1009, 1014, 1026, 1027, 1038, 1035, 1054, 1053, 1056, 1056, 1059, 1047, 1063, 1047, 1044, 1035, 1032, 1008, 1024, 996, 990, 976, 969, 930, 949, 906, 906, 885, 885, 834, 862, 810, 813, 792, 786, 729, 760, 699, 705, 685, 678, 618, 655, 588, 591, 579, 558, 507, 547, 480, 483, 477, 450, 399, 445, 375, 375, 379, 342, 306, 349, 279, 279, 288, 246, 219, 268, 195, 198, 219, 165, 153, 198, 126, 132, 160, 105, 102, 147, 78, 87, 117, 63, 66, 103, 45, 54, 84, 36, 42, 73, 21, 33, 55, 15, 24, 45, 9, 18, 36, 6, 12, 28, 0, 9, 21, 0, 6, 15, 0, 3, 10, 0, 0, 6, 0, 0, 3, 0, 0, 1};
    int combs[] = {1, 1, 2, 3, 4, 5, 7, 8, 10, 12, 14, 16, 19, 21, 24, 27, 30, 33, 37, 40, 44, 48, 52, 55, 60, 62, 67, 70, 75, 77, 83, 84, 90, 92, 98, 99, 106, 106, 113, 114, 121, 121, 129, 128, 135, 135, 141, 140, 148, 146, 153, 152, 159, 157, 166, 163, 170, 168, 174, 171, 180, 176, 182, 178, 184, 179, 187, 182, 187, 183, 187, 181, 188, 181, 184, 179, 182, 174, 181, 172, 175, 170, 171, 161, 168, 157, 160, 154, 156, 144, 153, 140, 144, 138, 139, 126, 135, 121, 125, 120, 120, 107, 118, 102, 106, 102, 100, 88, 99, 84, 87, 85, 81, 70, 82, 66, 69, 69, 63, 54, 65, 50, 52, 53, 46, 39, 51, 35, 38, 41, 32, 27, 38, 23, 26, 31, 21, 18, 29, 14, 18, 23, 13, 11, 21, 8, 11, 17, 8, 7, 16, 4, 7, 12, 4, 4, 10, 2, 4, 8, 2, 2, 7, 0, 2, 5, 0, 1, 4, 0, 1, 3, 0, 0, 2, 0, 0, 1, 0, 0, 1};
    
    int score;
    while (SCD(score), score > 0) {
        if (score > 180 || combs[score] == 0) {
            fprintf(stdout, "THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        } else {
            fprintf(stdout, "NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combs[score]);
            fprintf(stdout, "NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perms[score]);
        }
        
        fprintf(stdout, "**********************************************************************\n");        
    }
    fprintf(stdout, "END OF OUTPUT\n");
	return 0;
}