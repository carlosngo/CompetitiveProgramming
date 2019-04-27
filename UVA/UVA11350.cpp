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

string line;
FILE *pFile;

void solve (int pos, ll loN, ll loD, ll hiN, ll hiD) {
	ll midN = loN + hiN;
	ll midD = loD + hiD;
	if (pos == (int) line.length()) {
		printf("%lld/%lld\n", midN, midD);
		fprintf(pFile, "%lld/%lld\n", midN, midD);
	} else {
		if (line[pos] == 'L')
			solve(pos + 1, loN, loD, midN, midD);
		else
			solve(pos + 1, midN, midD, hiN, hiD);
	}
}

int main() {
	pFile = fopen("out.txt","w");
	int n;
	scanf("%d", &n);
	getline(cin, line);
	while(n-- > 0) {
		getline(cin, line);
		solve(0, 0, 1, 1, 0);
	}
	fclose(pFile);
	return 0;
}