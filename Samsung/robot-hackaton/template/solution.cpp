#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

int t, n, m, k;
string s;
int memo[100000][100];


// memo pos remF

int solve(int pos, int remF) {
    if (pos >= n) return 0;
    else if (remF == 0 || (pos && s[pos - 1] == 'X')) return memo[pos][remF] = solve(pos + 1, remF) + (s[pos] == '0' ? 1 : 0);
    else if (memo[pos][remF] != -1) return memo[pos][remF];
    else {
        int a, b;
        vector<char> chars;
        for (int i = pos; i < n && i < pos + k; i++) {
            chars.PB(s[i]);
            s[i] = 'X';
        }
        a = solve(pos + k, remF - 1);
        int j = 0;
        for (int i = pos; i < n && i < pos + k; i++) {
            s[i] = chars[j];
            j++;
        }
        b = solve(pos + 1, remF) + (s[pos] == '0' ? 1 : 0);
        return memo[pos][remF] = min(a, b);
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> s;
        memset(memo, -1, sizeof(memo));
        cout << solve(0, m) << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                cout << memo[i][j] << ' ';
            }
            cout << '\n';
        }

    }
	return 0;
}