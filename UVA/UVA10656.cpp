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

int main() {
	FILE *pFile = fopen("out.txt","w");
	int n;
	while (scanf("%d", &n), n != 0) {
		vi arr;
		
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			if (num != 0)
				arr.push_back(num);
		}
		for (int i = 0; i < arr.size(); i++) {
			
				printf("%d", arr[i]);
				fprintf(pFile, "%d", arr[i]);
				if (i != arr.size() - 1) {
					printf(" ");
					fprintf(pFile, " ");
				}
			
		}
		if (arr.size() == 0) {
			printf("0");
			fprintf(pFile, "0");
		}
		printf("\n");
		fprintf(pFile, "\n");
		
	}
	fclose(pFile);
	return 0;
}