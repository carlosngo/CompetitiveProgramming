#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, len, lCtr, inds[10];
string inp;
	
ll solve(int cur) {
	if(cur == n) {
		return lCtr > 0 ? 1LL : 0LL;
	} else {
		int ind = inds[cur];
		ll ans = 0LL;
		if(!(ind >= 2 && inp[ind - 1] == 'V' && inp[ind - 2] == 'V' ||
			ind >= 1 && ind < len - 1 && inp[ind - 1] == 'V' && 
			inp[ind + 1] == 'V' ||
			ind < len - 2 && inp[ind + 1] == 'V' && inp[ind + 2] == 'V')) {
			inp[ind] = 'V';
			ans += 5LL * solve(cur + 1);
		} 
		if(!(ind >= 2 && inp[ind - 1] == 'C' && inp[ind - 2] == 'C' ||
			ind >= 1 && ind < len - 1 && inp[ind - 1] == 'C' && 
			inp[ind + 1] == 'C' ||
			ind < len - 2 && inp[ind + 1] == 'C' && inp[ind + 2] == 'C')){
			inp[ind] = 'C';
			lCtr++;
			ans += solve(cur + 1);
			lCtr--;
			ans += 20LL * solve(cur + 1);
		}
		inp[ind] = '_';
		return ans;
	}
}

int main() {
	while(cin >> inp) {
		n = 0;
		len = inp.length();
		lCtr = 0;
		for(int i = 0; i < len; i++) {
			if(inp[i] == 'A' || inp[i] == 'E' || inp[i] == 'I' || inp[i] == 'O' || inp[i] == 'U') {
				inp[i] = 'V';
			} else if(inp[i] == '_'){
				inds[n++] = i;
			} else {
				if(inp[i] == 'L') {
					lCtr++;
				}
				inp[i] = 'C';
			}
		}
		printf("%lld\n",solve(0));
	}
}