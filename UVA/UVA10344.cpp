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

int arr[5];
bool poss;
void solve(int pos, int yield) {
	if (pos == 5) {
		if (yield == 23)
			poss = true;
	} else {
			solve(pos + 1, yield + arr[pos]);
				solve(pos + 1, yield - arr[pos]);
				solve(pos + 1, yield * arr[pos]);
	}

}

int main() {
	FILE *pFile = fopen("out.txt","w");
	while (scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]), arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && arr[4] != 0) {
		poss = false;
		sort(arr, arr + 5);
		do {
			solve(1, arr[0]);
			if (poss) {
				printf("Possible\n");
				fprintf(pFile, "Possible\n");
				break;	
			}
		} while (next_permutation(arr, arr + 5));
		if (!poss) {	
			printf("Impossible\n");
			fprintf(pFile, "Impossible\n");
		}
	}
	fclose(pFile);
	return 0;
}