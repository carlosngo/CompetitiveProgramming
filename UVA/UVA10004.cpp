#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

class Node {
    public:
    Node() {
        visited = false;
    }
    bool color;
    bool visited;
    vi edges;
};

int main() {
	FILE *pFile = fopen("out.txt","w");
    int nodes, edges;
    while (scanf("%d", &nodes), nodes != 0) {
        vector<Node> vn(nodes);
        
        scanf("%d", &edges);
        for (int i = 0; i < edges; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            vn[start].edges.push_back(end);
            vn[end].edges.push_back(start);
        }
        queue<Node> q;
        vn[0].color = true;
        vn[0].visited = true;
        q.push(vn[0]);
        bool ans = true;
        // for (int i = 0; i < vn.size(); i++) {
            
        //     printf("Index: %d\nColor: %d\nVisited: %d\nEdges: ", vn[i].index,vn[i].color, vn[i].visited);
        //     for (int j = 0; j < vn[i].edges.size(); j++) {
        //         printf("%d, ", vn[i].edges[j]);
        //     }
        // }
        while(q.size() > 0 && ans) {
            Node front = q.front(); q.pop();
            // printf("Checking Color: %d\nVisited: %d\n", front.color, front.visited);
            for (int i = 0; i < front.edges.size(); i++) {

                if (vn[front.edges[i]].visited != 1) {
                    // printf("Index: %d\nColor: %d\nVisited: %d\n", front.edges[i], next.color, next.visited);
                    vn[front.edges[i]].color = !front.color;
                    vn[front.edges[i]].visited = true;
                    q.push(vn[front.edges[i]]);    
                } else if (vn[front.edges[i]].visited && (vn[front.edges[i]].color == front.color))
                    ans = false;
                
            }
        }
        ans ? printf("BICOLORABLE.\n") : printf("NOT BICOLORABLE.\n");
        ans ? fprintf(pFile, "BICOLORABLE.\n") : fprintf(pFile, "NOT BICOLORABLE.\n");
    }

	fclose(pFile);
	return 0;
}