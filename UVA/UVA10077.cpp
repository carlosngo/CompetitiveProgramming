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
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

int n, d;
vc answer;
void treeWalk(int loN, int loD, int hiN, int hiD) {
	int n_ = loN + hiN;
	int d_ = loD + hiD; 
	if (n_ == n && d_ == d) {
		for (int i = 0; i < answer.size(); i++)
			printf("%c", answer[i]);
		printf("\n");
	} else if (n_ * d < d_ * n) {
		answer.push_back('R');
		treeWalk(n_, d_, hiN, hiD);
	} else {
		answer.push_back('L');
		treeWalk(loN, loD, n_, d_);
	}
}
int main() {
	FILE *pFile = fopen("out.txt","w");
	while (scanf("%d %d", &n, &d), !(n == 1 && d == 1)) {
		answer.clear();
		treeWalk(0, 1, 1, 0);
	}
	fclose(pFile);
	return 0;
}