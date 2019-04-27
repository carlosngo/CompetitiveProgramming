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
typedef vector<ii> vii;
typedef long long ll;



int main() {
	FILE *pFile = fopen("out.txt","w");
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int size;
		scanf ("%d", &size);
		int ctr = 0;
		
		bitset<102> bs;
		string field;
		cin >> field;
		for (int j = 0; j < size; j++) {
			if (field[j] == '.' && !bs.test(j)) {
				if (j - 1 >= 0 && field[j - 1] == '.' && !bs.test(j - 1)) {
					ctr++;
					bs.set(j - 1);
					bs.set(j);
					bs.set(j + 1);
				} else {
					ctr++;
					bs.set(j);
					bs.set(j + 1);
					bs.set(j + 2);
				}
			}
		}	
		printf("Case %d: %d\n", i, ctr);
		fprintf(pFile, "Case %d: %d\n", i, ctr);
	}
	fclose(pFile);
	return 0;
}