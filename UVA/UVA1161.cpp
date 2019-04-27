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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

ll n;
vll multiples; 

int main() {
	FILE *pFile = fopen("out.txt","w");
	for (int i = 0; i <= 31; i++) {
		for (int j = 0; j <= 31; j++) {
			multiples.push_back(pow(2, i) * pow(3, j));
		}
	}
	sort(multiples.begin(), multiples.end());
	while (scanf("%lld", &n), n != 0) {
		printf("%lld\n", *(lower_bound(multiples.begin(), multiples.end(), n)));
	}
	fclose(pFile);
	return 0;
}