#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r, int compare(int a, int b)) {
	int lSize = m - l + 1;
	int rSize = r - m;
	int lArr[lSize];
	int rArr[rSize];
	
	for (int i = 0; i < lSize; i++) {
		lArr[i] = arr[i + l];
	}
	
	for (int i = 0; i < rSize; i++) {
		rArr[i] = arr[i + m + 1];
	}
	
	int lInd = 0;
	int rInd = 0;
	int fInd = l;
	
	while (lInd < lSize && rInd < rSize) {
		if (compare(lArr[lInd], rArr[rInd])) {
			arr[fInd] = lArr[lInd];
			lInd++;
		} else {
			arr[fInd] = rArr[rInd];
			rInd++;
		}
		fInd++;
	}
	
	while (lInd < lSize) {
		arr[fInd] = lArr[lInd];
		fInd++;
		lInd++;
	}
	
	while (rInd < rSize) {
		arr[fInd] = rArr[rInd];
		fInd++;
		rInd++;
	}
	
	
}


void sort(int arr[], int l, int r, int compare(int a, int b)) {
	if (l < r) {
		int m = (l + r) / 2;
		sort(arr, l, m, compare);
		sort(arr, m + 1, r, compare);
		merge(arr, l, m, r, compare);	
	} 
	
}

int comp(int a, int b) {
	return a < b;
}

int
main() {
	int arr[5] = {2, 4, 5, 1, 3};
	sort(arr, 0, 4, comp);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
}
