#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCLD(t) fscanf(stdin, "%ld",&t)
#define SCLLD(t) fscanf(stdin, "%lld",&t)
#define SCC(t) fscanf(stdin, "%c",&t)
#define SCS(t) fscanf(stdin, "%s",t)
#define SCF(t) fscanf(stdin, "%f",&t)
#define SCLF(t) fscanf(stdin, "%lf",&t)
// CHECKING BOUNDS
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// LOOPS
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define WHILEZ int T; SCD(T); while(T--) 
// MISC
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define PB push_back
#define INF 1000000000

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    int ctr = 1;
    while (t--) {
        int w[10];
        map<int, vi> m;
        FOR (i, 0, 10, 1) { 
            SCD(w[i]);
            m[w[i]].PB(i);
        }
        // printf("Reached here.");
        for (int a = 1; a <= 200; a++) {
            // printf("a = %d\n", a);
            int b = w[0] - a;
            int c = w[1] - a;
            int d, e;
            bitset<10> bs;
            bs.set(0);
            bs.set(1);
            vi weight = m[b + c];
            if (weight.empty()) continue;
            else {
                bool found = false;
                for (int i = 0; i < weight.size() && !found; i++) {
                    if (!bs.test(weight[i])) {
                        bs.set(weight[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) continue;

            }
            
            // if (a == 90) printf("b = %d, c = %d\n", b, c);
            // SOLVING FOR D
            
            bitset<10> temp = bs;
            // if (a == 90) {
            //     for (int i = 0; i < bs.size(); i++) {
            //         printf("%d", bs.test(i));
            //     }
            // }
            bool foundD = false;
            for (int i = 2; i < 10 && !foundD; i++) {
                if (bs.test(i)) continue;
                // if (a == 90) printf("i = %d\n", i);
                bool valid = true;
                d = w[i] - a;
                // if (a == 90) printf("d = %d is a candidate\n", d);
                bs.set(i);
                weight = m[b + d];
                if (weight.empty()) valid = false;
                else {
                    bool found = false;
                    for (int i = 0; i < weight.size() && !found; i++) {
                        if (!bs.test(weight[i])) {
                            bs.set(weight[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) valid = false;
                }
                weight = m[c + d];
                if (weight.empty()) valid = false;
                else {
                    bool found = false;
                    for (int i = 0; i < weight.size() && !found; i++) {
                        if (!bs.test(weight[i])) {
                            bs.set(weight[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) valid = false;
                }
                if (!valid) bs = temp;
                else foundD = true;
            }                
            if (!foundD) continue;
            // if (a == 90) printf("Successfully found d = %d\n", d);
            // SOLVING FOR E
            temp = bs;
            bool foundE = false;
            for (int i = 3; i < 10 && !foundE; i++) {
                if (bs.test(i)) continue;
                bool valid = true;
                e = w[i] - a;
                bs.set(i);
                weight = m[b + e];
                if (weight.empty()) valid = false;
                else {
                    bool found = false;
                    for (int i = 0; i < weight.size() && !found; i++) {
                        if (!bs.test(weight[i])) {
                            bs.set(weight[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) valid = false;
                }

                weight = m[c + e];
                if (weight.empty()) valid = false;
                else {
                    bool found = false;
                    for (int i = 0; i < weight.size() && !found; i++) {
                        if (!bs.test(weight[i])) {
                            bs.set(weight[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) valid = false;
                }

                weight = m[d + e];
                if (weight.empty()) valid = false;
                else {
                    bool found = false;
                    for (int i = 0; i < weight.size() && !found; i++) {
                        if (!bs.test(weight[i])) {
                            bs.set(weight[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) valid = false;
                }

                if (!valid) bs = temp;
                else foundE = true;
            }
            if (!foundE) continue;
            else {
                fprintf(stdout, "Case %d: %d %d %d %d %d\n", ctr, a, b, c, d, e);
                // fprintf(pFile, "Case %d: %d %d %d %d %d\n", ctr, a, b, c, d, e);
                break;
            }
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}