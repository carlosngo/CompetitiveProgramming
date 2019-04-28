#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int n;

vector<iiii> stories;
vector<iiii> taken;
ll ans;
ll area;

void solve(int pos) {
    if (pos == n) {
        ans = max(ans, area);
    } else {
        iiii next = stories[pos];
        int w1 = next.first, h1 = next.second.first, x1 = next.second.second.first, y1 = next.second.second.second;
        bool shouldTake = x1 >= 0 && x1 + w1 <= 1000 && y1 >= 0 && y1 + h1 <= 1000;
        for (int j = 0; j < taken.size() && shouldTake; j++) {
            iiii prev = taken[j];
            int w2 = prev.first, h2 = prev.second.first, x2 = prev.second.second.first, y2 = prev.second.second.second;
            shouldTake = (x1 >= x2 + w2 || x1 + w1 <= x2) || (y1 >= y2 + h2 || y1 + h1 <= y2);
        }
        if (shouldTake) {
            taken.push_back(next);
            area += next.first * next.second.first;
            solve(pos + 1);
            area -= next.first * next.second.first;
            taken.pop_back();
        } 
        solve(pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    while (cin >> n, n != 0) {
        ans = INT_MIN;
        area = 0;
        stories = vector<iiii>();
        taken = vector<iiii>();
        for (int i = 0; i < n; i++) {
            iiii specs;
            cin >> specs.first >> specs.second.first >> specs.second.second.first >> specs.second.second.second;
            stories.push_back(specs);
        }
        solve(0);
        cout << ans << "\n";
    }
	return 0;
}