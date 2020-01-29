#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int
main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vii pts;
        int srcX, srcY;
        cin >> srcX >> srcY;
        pts.push_back(ii(srcX, srcY));
        for (int i = 0; i < n; i++) {
        	int x, y;
        	cin >> x >> y;
        	pts.push_back(ii(x, y));
		}
		int destX, destY;
		cin >> destX >> destY;
		pts.push_back(ii(destX, destY));
        int adjMatrix[n + 2][n + 2];
        for (int i = 0; i < n + 2; i++) {
            adjMatrix[i][i] = 0;
            for (int j = i + 1; j < n + 2; j++) {
                int x0 = pts[i].first, y0 = pts[i].second;
                int x1 = pts[j].first, y1 = pts[j].second;
                int distance = abs(x0 - x1) + abs(y0 - y1);
                adjMatrix[i][j] = distance;
                adjMatrix[j][i] = distance;
            }
        }
        for (int k = 0; k < n + 2; k++) {
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
		
		// for (int i = 0; i < n + 2; i++) {
	    //     for (int j = 0; j < n + 2; j++) {
	    //         cout << adjMatrix[i][j] << ' ';
	    //     }
	    //     cout << '\n';
	    // }
        queue<int> q;
        q.push(0);
        bitset<103> visited;
        visited.set(0);
        bool ans = false;
        while (!q.empty()) {
            int u = q.front();
            if (u == n + 1) ans = true;
            q.pop();
            for (int i = 0; i < n + 2; i++) {
                if (u != i) {
                    int v = i;
                    if (!visited.test(v) && adjMatrix[u][v] <= 1000) {
                        visited.set(v);
                        q.push(v);
                    }
                }
            }
        }
        if (ans) cout << "happy\n";
        else cout << "sad\n";
        
    }
    return 0;
}
