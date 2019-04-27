#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


int n, m; 

int
main() {
	int t;
	fscanf(stdin, "%d", &t);
	while (t--) {
		vi occurence;
		vi ms;
		fscanf(stdin, "%d%d", &n, &m);
		int arr[n];
		int sums[n];
		int maxSum = m;
		for (int i = 0; i < n; i++) {
			fscanf(stdin, "%d", &arr[i]);
			if (arr[i] <= m) occurence.push_back(i);
			if (arr[i] == m) ms.push_back(i);
			if (i) sums[i] = sums[i - 1] + arr[i];
			else sums[i] = arr[i];
		}
		for (int i = 0; i < ms.size(); i++) {
			int pos = lower_bound(occurence.begin(), occurence.end(), ms[i]) - occurence.begin();
			int left_Pos = pos - 1;
			int right_Pos = pos + 1;
			if (left_Pos < 0 && right_Pos == occurence.size()) {
				maxSum = max(maxSum, sums[n - 1]);
			} else if (left_Pos < 0) {
				maxSum = max(maxSum, sums[occurence[right_Pos] - 1]);
			} else if (right_Pos == occurence.size()) {
				int sum = sums[n - 1] - sums[occurence[left_Pos]];
				maxSum = max(maxSum, sum);
			} else {
				int sum = sums[occurence[right_Pos] - 1] - sums[occurence[left_Pos]];
				maxSum = max(maxSum, sum);
			}
		}
		
		fprintf(stdout, "%d\n", maxSum);
	}
	
	return 0;
}
