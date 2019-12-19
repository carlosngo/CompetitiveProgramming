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
const int UNVISITED = -1;

class Compare
{
public:
    bool operator() (string a, string b)
    {
        return a.length() < b.length();
    }
};

int main() {
    string in;
    while (cin >> in, in != "0") {
        vector<string> binaryOps;
        vector<string> unaryOps;
        priority_queue<string, vector<string>, Compare > operands;
        for (int i = 0; i < in.length(); i++) {
            char ch = in[i];
            string s;
            s.PB(ch);
            if (islower(ch)) operands.push(s);
            else {
                if (ch == 'N') unaryOps.PB(s);
                else binaryOps.PB(s);
            }
        }
        // for (int i = 0; i < unaryOps.size(); i++) cout << unaryOps[i];
        while (!unaryOps.empty() && !operands.empty()) {
            string unaryOp = unaryOps.back(); unaryOps.pop_back();
            // cout << unaryOp;
            string operand = operands.top(); operands.pop();
            operands.push(unaryOp + operand);
        }
        while (!binaryOps.empty() && operands.size() > 1) {
            string binaryOp = binaryOps.back(); binaryOps.pop_back();
            string op1 = operands.top(); operands.pop();
            string op2 = operands.top(); operands.pop();
            operands.push(binaryOp + op1 + op2);
        }
        if (operands.empty()) cout << "no WFF possible";
        else cout << operands.top();
        cout << '\n';
    }
	
	return 0;
}