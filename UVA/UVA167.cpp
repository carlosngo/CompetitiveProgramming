#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int k, maxSum, sum;
int board[8][8];
int queens[8];

void solve(int col) {
	if (col > 7) {
		maxSum = max(maxSum, sum);
	} else {
		for (int i = 0; i < 8; i++) {
			bool isValid = true;
			for (int j = 0; j < col && isValid; j++) {
				if ((queens[j] == i || (abs(queens[j] - i) == abs(j - col)))) {
					isValid = false;
				}
			}
			if (isValid) {
				queens[col] = i;
				sum += board[i][col];
				solve(col + 1);
				sum -= board[i][col];
			}

		}
	}
}

int main() {
	FILE *pFile = fopen("out.txt","w");
	scanf("%d", &k);
	while (k-- > 0) {
		sum = 0;
		maxSum = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		solve(0);
		printf("%5d\n", maxSum);
		fprintf(pFile, "%5d\n", maxSum);
	}
	fclose(pFile);
	return 0;
}