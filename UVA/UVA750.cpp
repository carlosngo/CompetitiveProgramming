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

int qCol, qRow;
int queens[9];
int n;
int num;
FILE *pFile;
void solve(int col) {
	if (col == 9) {
		printf("%2d      ", num);
		fprintf(pFile, "%2d      ", num);
		for (int i = 1; i < 9; i++) {
			printf("%d", queens[i]);
			fprintf(pFile, "%d", queens[i]);
			if (i != 8) {
				printf(" ");
				fprintf(pFile, " ");
			}

		}
		printf("\n");
		fprintf(pFile, "\n");
		num++;
	} else if (col == qCol) {
		bool isValid = true;
		for (int j = 1; j < col && isValid; j++) {
			if ((queens[j] == qRow || abs(col - j) == abs(qRow - queens[j])))
				isValid = false;
		}
		if (isValid)
			solve(col + 1);
	} else {
		for (int i = 1; i < 9; i++) {
			bool isValid = true;
			for (int j = 1; j < col && isValid; j++) {
				if (queens[j] == i || (abs(col - j) == abs(i - queens[j])))
					isValid = false;
			}
			if (isValid) {
				queens[col] = i;
				solve(col + 1); 
			}
		}
	}
}

int main() {
	pFile = fopen("out.txt","w");
	scanf ("%d", &n);
	while (n-- > 0) {
		num = 1;
		scanf("%d %d", &qRow, &qCol);
		queens[qCol] = qRow;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		fprintf(pFile, "SOLN       COLUMN\n");
		fprintf(pFile, " #      1 2 3 4 5 6 7 8\n\n");
		solve(1);
		if (n > 0) {
			printf("\n");
			fprintf(pFile, "\n");
		}
	}
	fclose(pFile);
	return 0;
}