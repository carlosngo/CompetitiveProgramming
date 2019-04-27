#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
#include <sstream>
#include <iterator>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;



int main() {
	FILE *pFile = fopen("out.txt","w");
    vector<string> keywords;
    vector<vector<string> > lines;
    string word;
    while (cin >> word, word != "::")
        keywords.push_back(word);
    while (getline(cin, word)) {
        vector<string> line = split(&word, ' ');
        lines.push_back(line);
    }

    for (int i = 0; i < keywords.size(); i++)
        cout << keywords[i] + "\n";
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            cout << lines[i][j] + " ";
        }
        cout << "\n";
    }
        
	fclose(pFile);
	return 0;
}

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}