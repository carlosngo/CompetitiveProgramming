#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

int main() {
    int n, q;
    SCD(n);
    SCD(q);
    set<int> s;
    map<int, int> m;
    s.insert(1);
    s.insert(n);
    int ans = n - 1;
    m[ans] = 1;
    while (q--) {
        int cmd;
        SCD(cmd);
        if (cmd == -1) {
            map<int, int>::iterator it = m.end();
            it--;
            fprintf(stdout, "%d %d\n", it->first, it->second);
        } else {
            set<int>::iterator it = s.upper_bound(cmd);
            int right = *(it);
            it--;
            int left = *(it);
            int prev = m[right - left];
            if (prev == 1) {
                m.erase(right - left); 
            } else m[right - left] = prev - 1;

            m[right - cmd]++;
            m[cmd - left]++;
            s.insert(cmd);
        }
    }
	return 0;
}